#include "AutoInfo.hpp"

/**
 * @file AutoInfo.cpp
 * @brief Implementation of the AutoInfo class methods
 */

AutoInfo::AutoInfo() : ownerName(""), carBrand(""), productionYear(0), licensePlate(""), color("") {}

AutoInfo::AutoInfo(const std::string& ownerName, const std::string& carBrand, int productionYear, const std::string& licensePlate, const std::string& color)
    : ownerName(ownerName), carBrand(carBrand), productionYear(productionYear), licensePlate(licensePlate), color(color) {}

AutoInfo::~AutoInfo() {}

bool AutoInfo::operator==(const AutoInfo& other) const {
    return licensePlate == other.licensePlate &&
           productionYear == other.productionYear &&
           carBrand == other.carBrand &&
           color == other.color &&
           ownerName == other.ownerName;
}

bool AutoInfo::operator!=(const AutoInfo& other) const {
    return !(*this == other);
}

bool AutoInfo::operator<(const AutoInfo& other) const {
    if (licensePlate != other.licensePlate) {
        return licensePlate < other.licensePlate;
    }
    if (productionYear != other.productionYear) {
        return productionYear < other.productionYear;
    }
    if (carBrand != other.carBrand) {
        return carBrand < other.carBrand;
    }
    if (color != other.color) {
        return color < other.color;
    }
    return ownerName < other.ownerName;
}
    
bool AutoInfo::operator>(const AutoInfo& other) const {
    return other < *this;
}
   
bool AutoInfo::operator<=(const AutoInfo& other) const {
    return *this < other || *this == other;
}

bool AutoInfo::operator>=(const AutoInfo& other) const {
    return *this > other || *this == other;
}