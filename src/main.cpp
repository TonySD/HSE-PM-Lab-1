#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "AutoInfo.hpp"
#include "SortMethods.hpp"

/**
 * @file main.cpp
 * @brief Program, that implements sorting algorithms and compares their performance
 * @author Vagin Anton
 * @date 2025
 */

/**
 * @brief Splits a string into tokens based on a delimiter
 *
 * @param str The input string to be split
 * @param delimiter The delimiter string
 * @return Vector of string tokens
 */
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

/**
 * @brief Executes a sorting algorithm and measures its performance
 *
 * Creates a copy of the input array, runs the specified sorting algorithm,
 * measures the execution time, and outputs the results.
 *
 * @param autos Pointer to the vector of AutoInfo objects to be sorted
 * @param current_sort Pointer to the sorting algorithm to be used
 */
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

/**
 * @brief Main function
 *
 * Reads automobile data from a CSV file, applies different sorting algorithms,
 * measures their performance, and writes the sorted data to an output file.
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return 0 if successful, 1 if an error occurred
 */
int main(int argc, char* argv[]) {
    // Check if input file is provided
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Open input file
    std::string input_file = argv[1];
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << input_file << std::endl;
        return 1;
    }

    // Read and parse data from the CSV file
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

    // Test standard sort algorithm
    std::cout << "[Debug] Starting std::sort" << std::endl;
    auto start = std::chrono::system_clock::now();
    std::sort(autos_copy.begin(), autos_copy.end());
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "        std::sort completed in " << std::fixed << std::setprecision(4) << elapsed_seconds.count() << " seconds" << std::endl << std::endl;
    
    // Test custom sorting algorithms
    sort_iteration(&autos, new SelectionSort());
    sort_iteration(&autos, new MergeSort());
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