#include "AutoInfo.hpp"
#include <vector>

class SortMethod {
public:
    virtual void sort(std::vector<AutoInfo>& arr) = 0;
};

class SelectionSort : public SortMethod {
public:
    void sort(std::vector<AutoInfo>& arr) override;
};

class QuickSort : public SortMethod {
private:
    size_t partition(std::vector<AutoInfo>& arr, size_t low, size_t high);
    void quickSortHelper(std::vector<AutoInfo>& arr, size_t low, size_t high);

public:
    void sort(std::vector<AutoInfo>& arr) override;
};


class MergeSort : public SortMethod {
private:
    void merge(std::vector<AutoInfo>& arr, size_t left, size_t mid, size_t right);
    void mergeSortHelper(std::vector<AutoInfo>& arr, size_t left, size_t right);

public:
    void sort(std::vector<AutoInfo>& arr) override;
};