#pragma once

#ifndef JAMSTL_RANDOMGENERATOR_H
#define JAMSTL_RANDOMGENERATOR_H
#include "Macros.h"
#include "Object.h"
#include "Collections/Array.h"
#include "Math.h"
#include <time.h>

JAMSTL_NAMESPACE_BEGIN

// Random using MersenneTwister
class Random : public Object {
private:
    static constexpr usize N = 624;
    static constexpr unsigned M = 397;
    static constexpr unsigned A = 0x9908b0df;
    static constexpr unsigned U = 11;
    static constexpr unsigned D = 0xffffffff;
    static constexpr unsigned S = 7;
    static constexpr unsigned B = 0x9d2c5680;
    static constexpr unsigned T = 15;
    static constexpr unsigned C = 0xefc60000;
    static constexpr unsigned L = 18;
    static constexpr unsigned F = 1812433253;
    static constexpr unsigned LOWER_MASK = 0x7fffffff;
    static constexpr unsigned UPPER_MASK = ~LOWER_MASK;
    static constexpr unsigned MAX_INT = 0xffffffff;
    static constexpr double DOUBLE_UNIT = 1ll << 53; 

    Array<unsigned, N> state;
    usize index;

    void twist() {
        for(usize i = 0; i < N; i++) {
            unsigned x = (state[i] & UPPER_MASK) + (state[(i + 1) % N] & LOWER_MASK);
            unsigned xA = x >> 1;
            if(x & 1) xA ^= x;
            state[i] = state[(i + M) % N] ^ xA;
        }
        index = 0;
    }

    int next(int bits) {
        if(index >= N) twist();
        unsigned y = state[index++];
        y ^= (y >> U);
        y ^= (y << S) & B;
        y ^= (y << T) & C;
        y ^= (y >> L);
        return y >> (32 - bits);
    }

public:

    Random(unsigned seed = Random::now()) : index(N) {
        state[0] = seed;
        for(usize i = 1; i < N; i++) {
            state[i] = (F * (state[i - 1] ^ (state[i - 1] >> 30)) + i);
        }
    }


    int nextInt() {
        return next(32);
    }

    int nextInt(unsigned bound) {
        int r = next(31);
        int m = bound - 1;
        if((bound & m) == 0) {
            r = (int)((bound * (long long)r) >> 31);
        } else {
            for(int u = r; u - (r = u % bound) + m < 0; u = next(31));
        }
        return r;
    }

    int nextInt(int from, int to) {
        return from + nextInt(to - from);
    }

    long long nextLong() {
        return ((long long)next(32) << 32) + next(32);
    }

    long long nextLong(unsigned long long bound) {
        long long r = nextLong() & 0x7fffffffffffffff;
        long long m = bound - 1;
        if((bound & m) == 0) {
            r = (long long)((bound * (long long)r) >> 63);
        } else {
            for(long long u = r; u - (r = u % bound) + m < 0; u = nextLong() & 0x7fffffffffffffff);
        }
        return r;
    }

    long long nextLong(long long from, long long to) {
        return from + nextLong(to - from);
    }

    bool nextBoolean() {
        return next(1) != 0;
    }

    float nextFloat() {
        return next(24) / (float)(1 << 24);
    }

    float nextFloat(float from, float to) {
        return from + nextFloat() * (to - from);
    }

    double nextDouble() {
        return (((long long)next(26) << 27) + next(27)) / DOUBLE_UNIT;
    }

    double nextDouble(double from, double to) {
        return from + nextDouble() * (to - from);
    }

    double nextGaussian() {
        double v1, v2, s;
        do {
            v1 = 2 * nextDouble() - 1;
            v2 = 2 * nextDouble() - 1;
            s = v1 * v1 + v2 * v2;
        } while(s >= 1 || s == 0);
        double multiplier = Math.sqrt(-2 * Math.ln(s) / s);
        return v1 * multiplier;
    }
    
    static unsigned now() {
        return time(NULL);
    }

    void setSeed(unsigned seed) {
        state[0] = seed;
        for(usize i = 1; i < N; i++) {
            state[i] = (F * (state[i - 1] ^ (state[i - 1] >> 30)) + i);
        }
    }

};


JAMSTL_NAMESPACE_END

#endif