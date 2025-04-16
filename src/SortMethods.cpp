#include "SortMethods.hpp"
#include <algorithm>

// Selection sort implementation
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

// Quick sort
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

void QuickSort::quickSortHelper(std::vector<AutoInfo>& arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high);
        if (pi > 0) quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}


void QuickSort::sort(std::vector<AutoInfo>& arr) {
    if (arr.size() <= 1) return;
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Merge sort
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

void MergeSort::mergeSortHelper(std::vector<AutoInfo>& arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void MergeSort::sort(std::vector<AutoInfo>& arr) {
    if (arr.size() <= 1) return;
    mergeSortHelper(arr, 0, arr.size() - 1);
}
