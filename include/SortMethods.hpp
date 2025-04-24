#pragma once
#include "AutoInfo.hpp"
#include <vector>

/**
 * @file SortMethods.hpp
 * @brief Collection of sorting algorithm implementations
 * @author Lab-01
 * @date 2023
 */

/**
 * @class SortMethod
 * @brief Base abstract class for sorting algorithms
 *
 * Defines the interface for all sorting algorithm implementations.
 * Each derived class must implement the sort method.
 */
class SortMethod {
public:
    std::string name; /**< Name of the sorting algorithm */
    
    /**
     * @brief Constructor with algorithm name
     * @param method_name Name of the sorting algorithm
     */
    SortMethod(const std::string& method_name) : name(method_name) {}
    
    /**
     * @brief Pure virtual function for sorting
     * @param arr Vector of AutoInfo objects to be sorted
     */
    virtual void sort(std::vector<AutoInfo>& arr) = 0;
};

/**
 * @class SelectionSort
 * @brief Implementation of selection sort algorithm
 *
 * Selection sort works by repeatedly finding the minimum element
 * from the unsorted part of the array and putting it at the beginning.
 * Time complexity: O(n²) in all cases.
 */
class SelectionSort : public SortMethod {
public:
    /**
     * @brief Constructor
     * Initializes the name of the sorting method
     */
    SelectionSort() : SortMethod("SelectionSort") {}
    
    /**
     * @brief Sorts an array using selection sort algorithm
     * @param arr Vector of AutoInfo objects to be sorted
     */
    void sort(std::vector<AutoInfo>& arr) override;
};

/**
 * @class QuickSort
 * @brief Implementation of quick sort algorithm
 *
 * Quick sort works by selecting a 'pivot' element and partitioning
 * the array around the pivot.
 * Time complexity: O(n log n) average case, O(n²) worst case.
 */
class QuickSort : public SortMethod {
private:
    /**
     * @brief Partitions the array around a pivot element
     * @param arr Vector to be partitioned
     * @param low Starting index
     * @param high Ending index
     * @return Position of the pivot element after partitioning
     */
    size_t partition(std::vector<AutoInfo>& arr, size_t low, size_t high);
    
    /**
     * @brief Recursive helper function for quick sort
     * @param arr Vector to be sorted
     * @param low Starting index
     * @param high Ending index
     */
    void quickSortHelper(std::vector<AutoInfo>& arr, size_t low, size_t high);

public:
    /**
     * @brief Constructor
     * Initializes the name of the sorting method
     */
    QuickSort() : SortMethod("QuickSort") {}
    
    /**
     * @brief Sorts an array using quick sort algorithm
     * @param arr Vector of AutoInfo objects to be sorted
     */
    void sort(std::vector<AutoInfo>& arr) override;
};

/**
 * @class MergeSort
 * @brief Implementation of merge sort algorithm
 *
 * Merge sort works by dividing the array into two halves,
 * recursively sorting them, and then merging the sorted halves.
 * Time complexity: O(n log n) in all cases.
 */
class MergeSort : public SortMethod {
private:
    /**
     * @brief Merges two sorted subarrays
     * @param arr Vector containing the subarrays
     * @param left Starting index of first subarray
     * @param mid Ending index of first subarray
     * @param right Ending index of second subarray
     */
    void merge(std::vector<AutoInfo>& arr, size_t left, size_t mid, size_t right);
    
    /**
     * @brief Recursive helper function for merge sort
     * @param arr Vector to be sorted
     * @param left Starting index
     * @param right Ending index
     */
    void mergeSortHelper(std::vector<AutoInfo>& arr, size_t left, size_t right);

public:
    /**
     * @brief Constructor
     * Initializes the name of the sorting method
     */
    MergeSort() : SortMethod("MergeSort") {}
    
    /**
     * @brief Sorts an array using merge sort algorithm
     * @param arr Vector of AutoInfo objects to be sorted
     */
    void sort(std::vector<AutoInfo>& arr) override;
};