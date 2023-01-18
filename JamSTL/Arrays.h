#pragma once

#ifndef ARRAYS_H
#define ARRAYS_H

#include "Macros.h"
#include "Datatypes.h"
#include "Collections/Array.h"
#include "Collections/JArray.h"
#include "Exception/ArrayIndexOutOfBoundsException.h"


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

            template<class T, usize size>
            static void quickSort(Array<T, size>& arr, usize left, usize right) {
                try {
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
                } catch(ArrayIndexOutOfBoundsException& aioobe) {}
            }

            template<class T>
            static void quickSort(JArray<T>& arr, usize left, usize right) {
                try {
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
                } catch(ArrayIndexOutOfBoundsException& aioobe) {}
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

            template<class T, usize size>
            static usize binarySearch0(Array<T, size> arr, usize fromIndex, usize toIndex, T key) {
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

            template<class T>
            static usize binarySearch0(JArray<T> arr, usize fromIndex, usize toIndex, T key) {
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
            
            template<class T, usize size>
            static void sort(Array<T, size>& arr) {
                quickSort(arr, 0, size - 1);
            }

            template<class T>
            static void sort(JArray<T>& arr) {
                quickSort(arr, 0, arr.size() - 1);
            }

            template<class T>
            static usize binarySearch(T* arr, usize size, T key) {
                return binarySearch0(arr, 0, size, key);
            }

            template<class T, usize size>
            static usize binarySearch(Array<T, size> arr, T key) {
                return binarySearch0(arr, 0, size, key);
            }

            template<class T>
            static usize binarySearch(JArray<T> arr, T key) {
                return binarySearch0(arr, 0, arr.size(), key);
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

            template<class T, usize size>
            static void fill(Array<T, size> arr, T value) {
                for(usize i = 0; i < size; i++)
                    arr[i] = value;
            }

            template<class T>
            static void fill(JArray<T> arr, T value) {
                for(usize i = 0; i < arr.size(); i++)
                    arr[i] = value;
            }

            template<class T>
            static void fill(T* arr, usize fromIndex, usize toIndex, T value) {
                for(usize i = fromIndex; i < toIndex; i++)
                    arr[i] = value;
            }

            template<class T, usize size>
            static void fill(Array<T, size> arr, usize fromIndex, usize toIndex, T value) {
                if(toIndex > size) {
                    throw IndexOutOfBoundsException();
                }
                if(fromIndex > toIndex) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = fromIndex; i < toIndex; i++)
                    arr[i] = value;
            }

            template<class T>
            static void fill(JArray<T> arr, usize fromIndex, usize toIndex, T value) {
                if(toIndex > arr.size()) {
                    throw IndexOutOfBoundsException();
                }
                if(fromIndex > toIndex) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = fromIndex; i < toIndex; i++)
                    arr[i] = value;
            }

            template<class T>
            static void copy(T* src, usize srcPos, T* dest, usize destPos, usize length) {
                for(usize i = 0; i < length; i++)
                    dest[destPos + i] = src[srcPos + i];
            }

            template<class T, usize size>
            static void copy(Array<T, size> src, usize srcPos, Array<T, size> dest, usize destPos, usize length) {
                if(length > size) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = 0; i < length; i++)
                    dest[destPos + i] = src[srcPos + i];
            }

            template<class T>
            static void copy(JArray<T> src, usize srcPos, JArray<T> dest, usize destPos, usize length) {
                if(length > src.size()) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = 0; i < length; i++)
                    dest[destPos + i] = src[srcPos + i];
            }

            template<class T>
            static void copy(T* src, T* dest, usize length) {
                for(usize i = 0; i < length; i++)
                    dest[i] = src[i];
            }

            template<class T, usize size>
            static void copy(Array<T, size> src, Array<T, size> dest, usize length) {
                if(length > size) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = 0; i < length; i++)
                    dest[i] = src[i];
            }

            template<class T>
            static void copy(JArray<T> src, JArray<T> dest, usize length) {
                if(length > src.size()) {
                    throw IndexOutOfBoundsException();
                }
                for(usize i = 0; i < length; i++)
                    dest[i] = src[i];
            }

            template<class T>
            static void copy(T* src, usize srcPos, T* dest, usize destPos, usize length, usize srcStride, usize destStride) {
                for(usize i = 0; i < length; i++)
                    dest[destPos + i * destStride] = src[srcPos + i * srcStride];
            }
            
    };


JAMSTL_NAMESPACE_END


#endif