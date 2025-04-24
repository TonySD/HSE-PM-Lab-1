#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "AutoInfo.hpp"
#include "SortMethods.hpp"

std::vector<std::string>* split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> *tokens = new std::vector<std::string>();
    size_t start = 0, end = 0;
    while ((end = str.find(delimiter, start)) != std::string::npos) {
        tokens->push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    tokens->push_back(str.substr(start));
    return tokens;
}

void sort_iteration(const std::vector<AutoInfo>* autos, SortMethod* current_sort) {
    std::vector<AutoInfo> autos_copy = *autos;
    // Selection sort
    std::cout << "[Debug] Starting " << current_sort->name << std::endl;
    auto start = std::chrono::system_clock::now();
    current_sort->sort(autos_copy);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "        " << current_sort->name << " completed in " << std::fixed << std::setprecision(4) << elapsed_seconds.count() << " seconds" << std::endl << std::endl;
    delete current_sort;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << input_file << std::endl;
        return 1;
    }

    std::vector<AutoInfo> autos;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        std::vector<std::string>* tokens = split(line, ";");
        if (tokens->size() != 5) {
            std::cout << "[Error] Malformed line in csv: " << line << std::endl;
            delete tokens;
            continue;
        }

        AutoInfo autoInfo((*tokens)[0], (*tokens)[1], std::stoi((*tokens)[2]), (*tokens)[3], (*tokens)[4]);
        autos.push_back(autoInfo);
        delete tokens;
    }
    
    std::vector<AutoInfo> autos_copy = autos;

    // Standart sort
    std::cout << "[Debug] Starting std::sort" << std::endl;
    auto start = std::chrono::system_clock::now();
    std::sort(autos_copy.begin(), autos_copy.end());
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "        std::sort completed in " << std::fixed << std::setprecision(4) << elapsed_seconds.count() << " seconds" << std::endl << std::endl;
    
    // Selection sort
    sort_iteration(&autos, new SelectionSort());

    // Merge sort
    sort_iteration(&autos, new MergeSort());

    // Quick sort
    sort_iteration(&autos, new QuickSort());

    // Write sorted data to CSV file
    std::cout << "[Debug] Writing sorted data to CSV file" << std::endl;
    std::ofstream output_file("sorted_dataset.csv");
    
    if (!output_file.is_open()) {
        std::cout << "[Error] Could not create output file sorted_dataset.csv" << std::endl;
        return 1;
    }
    
    for (const auto& car : autos_copy) {
        output_file << car.carBrand << ";"
                    << car.ownerName << ";"
                    << car.productionYear << ";"
                    << car.licensePlate << ";"
                    << car.color << std::endl;
    }
    
    output_file.close();
    std::cout << "[Debug] Sorted data successfully written to sorted_dataset.csv" << std::endl;

    return 0;
}