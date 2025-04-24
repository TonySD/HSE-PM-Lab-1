#include "SortMethods.hpp"
#include <algorithm>

/**
 * @file SortMethods.cpp
 * @brief Implementation of various sorting algorithms
 */

/**
 * @brief Implementation of selection sort algorithm
 * 
 * This method sorts a vector of AutoInfo objects using selection sort.
 * For each position, it finds the minimum element in the remaining unsorted
 * portion and swaps it with the element at the current position.
 * 
 * @param arr Vector of AutoInfo objects to be sorted
 */
void SelectionSort::sort(std::vector<AutoInfo>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

/**
 * @brief Partitions the array around a pivot
 * 
 * Selects the last element as pivot and partitions the array such that
 * all elements less than the pivot come before it, and all elements
 * greater than the pivot come after it.
 * 
 * @param arr Vector to be partitioned
 * @param low Starting index
 * @param high Ending index (pivot)
 * @return Position of the pivot after partitioning
 */
size_t QuickSort::partition(std::vector<AutoInfo>& arr, size_t low, size_t high) {
    AutoInfo pivot = arr[high];
    size_t i = low;

    for (size_t j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

/**
 * @brief Recursive helper function for quicksort
 * 
 * Recursively sorts the array by partitioning and then
 * sorting each partition.
 * 
 * @param arr Vector to be sorted
 * @param low Starting index
 * @param high Ending index
 */
void QuickSort::quickSortHelper(std::vector<AutoInfo>& arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high);
        if (pi > 0) quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

/**
 * @brief Main quick sort function
 * 
 * Initiates the quicksort algorithm on the entire array.
 * 
 * @param arr Vector of AutoInfo objects to be sorted
 */
void QuickSort::sort(std::vector<AutoInfo>& arr) {
    if (arr.size() <= 1) return;
    quickSortHelper(arr, 0, arr.size() - 1);
}

/**
 * @brief Merges two sorted subarrays
 * 
 * Creates temporary arrays to store the two subarrays,
 * and then merges them back into the original array in sorted order.
 * 
 * @param arr Vector containing the subarrays
 * @param left Starting index of first subarray
 * @param mid Ending index of first subarray
 * @param right Ending index of second subarray
 */
void MergeSort::merge(std::vector<AutoInfo>& arr, size_t left, size_t mid, size_t right) {
    size_t size_1 = mid - left + 1;
    size_t size_2 = right - mid;

    std::vector<AutoInfo> L(size_1), R(size_2);

    for (size_t i = 0; i < size_1; ++i)
        L[i] = arr[left + i];
    for (size_t j = 0; j < size_2; ++j)
        R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;

    while (i < size_1 && j < size_2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < size_1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < size_2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

/**
 * @brief Recursive helper function for merge sort
 * 
 * Recursively divides the array into two halves, sorts them,
 * and then merges them back.
 * 
 * @param arr Vector to be sorted
 * @param left Starting index
 * @param right Ending index
 */
void MergeSort::mergeSortHelper(std::vector<AutoInfo>& arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Main merge sort function
 * 
 * Initiates the merge sort algorithm on the entire array.
 * 
 * @param arr Vector of AutoInfo objects to be sorted
 */
void MergeSort::sort(std::vector<AutoInfo>& arr) {
    if (arr.size() <= 1) return;
    mergeSortHelper(arr, 0, arr.size() - 1);
}
