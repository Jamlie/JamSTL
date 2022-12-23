#pragma once

#ifndef ARRAYS_H
#define ARRAYS_H

#include "Macros.h"
#include "Datatypes.h"
#include "Collections/ArrayList.h"

JAMSTL_NAMESPACE_BEGIN

    class Arrays {
        private:
            Arrays() {}
            template<class T>
            static void quickSort(T* arr, usize left, usize right) {
                usize i = left, j = right;
                T tmp;
                T pivot = arr[(left + right) / 2];

                while (i <= j) {
                    while (arr[i] < pivot)
                        i++;
                    while (arr[j] > pivot)
                        j--;
                    if (i <= j) {
                        tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                        i++;
                        j--;
                    }
                };

                if (left < j)
                    quickSort(arr, left, j);
                if (i < right)
                    quickSort(arr, i, right);
            }

            template<class T>
            static usize binarySearch0(T* arr, usize fromIndex, usize toIndex, T key) {
                usize low = fromIndex;
                usize high = toIndex - 1;

                while(low <= high) {
                    usize mid = (low + high) >> 1;
                    T midVal = arr[mid];

                    if(midVal < key)
                        low = mid + 1;
                    else if(midVal > key)
                        high = mid - 1;
                    else
                        return mid; 
                }
                
                return -(low + 1);
            }

            static usize binarySearch1(float* arr, usize fromIndex, 
                                    usize toIndex, float key) {

                usize low = fromIndex;
                usize high = toIndex - 1;

                while(low <= high) {
                    usize mid = (low + high) >> 1;
                    float midVal = arr[mid];

                    if(midVal < key)
                        low = mid + 1;
                    else if(midVal > key)
                        high = mid - 1;
                    else {
                        int midBits = Float::floatToIntBits(midVal);
                        int keyBits = Float::floatToIntBits(key);

                        if(midBits == keyBits)
                            return mid;
                        else if(midBits < keyBits)
                            low = mid + 1;
                        else
                            high = mid - 1;
                    }
                }
                return -(low + 1);
            }

            static usize binarySearch2(double* arr, usize fromIndex,
                                    usize toIndex, double key) {
                
                usize low = fromIndex;
                usize high = toIndex - 1;

                while(low <= high) {
                    usize mid = (low + high) >> 1;
                    double midVal = arr[mid];

                    if(midVal < key)
                        low = mid + 1;
                    else if(midVal > key)
                        high = mid - 1;
                    else {
                        long midBits = Double::doubleToRawLongBits(midVal);
                        long keyBits = Double::doubleToRawLongBits(key);

                        if(midBits == keyBits)
                            return mid;
                        else if(midBits < keyBits)
                            low = mid + 1;
                        else
                            high = mid - 1;
                    }
                }
                return -(low + 1);
            }

        public:
            
            template<class T>
            static void sort(T* arr, usize size) {
                quickSort(arr, 0, size - 1);
            }
            
            template<class T>
            static usize binarySearch(T* arr, usize size, T key) {
                return binarySearch0(arr, 0, size, key);
            }

            static usize binarySearch(float* arr, usize size, float key) {
                return binarySearch1(arr, 0, size, key);
            }

            static usize binarySearch(double* arr, usize size, double key) {
                return binarySearch2(arr, 0, size, key);
            }

            template<class T>
            static void fill(T* arr, usize size, T value) {
                for(usize i = 0; i < size; i++)
                    arr[i] = value;
            }

            template<class T>
            static void fill(T* arr, usize fromIndex, usize toIndex, T value) {
                for(usize i = fromIndex; i < toIndex; i++)
                    arr[i] = value;
            }

            template<class T>
            static void copy(T* src, usize srcPos, T* dest, usize destPos, usize length) {
                for(usize i = 0; i < length; i++)
                    dest[destPos + i] = src[srcPos + i];
            }

            template<class T>
            static void copy(T* src, T* dest, usize length) {
                for(usize i = 0; i < length; i++)
                    dest[i] = src[i];
            }




            

            

            

    };

JAMSTL_NAMESPACE_END


#endif