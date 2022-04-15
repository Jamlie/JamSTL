// Omar Estietie
#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

class real {
private:
    double *number;
public:
    real(double value = 0):number{new double(value)} {};
    void set(double value) { *number = value; }
    void print() { cout << *number << '\n'; }
    ~real() { delete number; }

    real& operator= (const real &REAL) {
        if (this != &REAL) *number = *REAL.number;
        return *this; 
    }

    real operator+ (const real& REAL) const {
        return real(*number + *REAL.number);
	}

    real operator* (const real& REAL) const {
        return real(*number * *REAL.number);
	}

    real operator- (const real& REAL) const {
        return real(*number - *REAL.number);
	}

    real operator/ (const real& REAL) const {
        return real(*number / *REAL.number);
	}

    bool operator== (real REAL) {
		return *number == *REAL.number;
	}

    bool operator!= (real REAL) {
		return *number != *REAL.number;
	}

    bool operator> (real REAL) {
		return *number > *REAL.number;
	}

    bool operator>= (real REAL) {
		return *number >= *REAL.number;
	}

    bool operator< (real REAL) {
		return *number < *REAL.number;
	}

    bool operator<= (real REAL) {
		return *number <= *REAL.number;
	}

    friend ostream& operator<<(ostream& os, const real& REAL) {
        os << *REAL.number;
        return os;
    }
    friend istream& operator>>(istream& is, const real& REAL) {
        is >> *REAL.number;
        return is;
    }


};
