#pragma once
#include <string>

/**
 * @file AutoInfo.hpp
 * @brief Class for storing automobile information
 * @author Lab-01
 * @date 2023
 */

/**
 * @class AutoInfo
 * @brief Stores information about automobiles
 *
 * This class encapsulates data about a car including owner information,
 * car brand, production year, license plate, and color. It provides
 * comparison operators for sorting purposes.
 */
class AutoInfo {
public:
    std::string ownerName;      // Owner's full name
    std::string carBrand;       // Car brand/make
    int productionYear;         // Production year
    std::string licensePlate;   // License plate number
    std::string color;          // Car color

    /**
     * @brief Default constructor
     * 
     * Creates an AutoInfo object with empty fields
     */
    AutoInfo();
    
    /**
     * @brief Parameterized constructor
     * 
     * @param ownerName Owner's full name
     * @param carBrand Car brand/make
     * @param productionYear Production year
     * @param licensePlate License plate number
     * @param color Car color
     */
    AutoInfo(const std::string& ownerName, 
             const std::string& carBrand, 
             int productionYear, 
             const std::string& licensePlate, 
             const std::string& color);
    
    /**
     * @brief Destructor
     */
    ~AutoInfo();

    /**
     * @brief Equality comparison operator
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if objects are equal, false otherwise
     */
    bool operator==(const AutoInfo& other) const;
    
    /**
     * @brief Inequality comparison operator
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if objects are not equal, false otherwise
     */
    bool operator!=(const AutoInfo& other) const;
    
    /**
     * @brief Less than comparison operator
     * 
     * Compares according to the following order: licensePlate, productionYear,
     * carBrand, color, ownerName
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if this object is less than other, false otherwise
     */
    bool operator<(const AutoInfo& other) const;
    
    /**
     * @brief Greater than comparison operator
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if this object is greater than other, false otherwise
     */
    bool operator>(const AutoInfo& other) const;
    
    /**
     * @brief Less than or equal comparison operator
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if this object is less than or equal to other, false otherwise
     */
    bool operator<=(const AutoInfo& other) const;
    
    /**
     * @brief Greater than or equal comparison operator
     * 
     * @param other Another AutoInfo object to compare with
     * @return true if this object is greater than or equal to other, false otherwise
     */
    bool operator>=(const AutoInfo& other) const;
};