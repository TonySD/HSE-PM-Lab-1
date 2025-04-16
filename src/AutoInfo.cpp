#include "AutoInfo.hpp"

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
    if (licensePlate < other.licensePlate) {
        return true;
    }

        if (productionYear < other.productionYear) {
            return true;
        }

        if (carBrand < other.carBrand) {
            return true;
        }

        if (color < other.color) {
            return true;
        }

        if (ownerName < other.ownerName) {
            return true;
        }
        
    return false;
};
    

bool AutoInfo::operator>(const AutoInfo& other) const {
    return !(*this < other);
};
   
bool AutoInfo::operator<=(const AutoInfo& other) const {
    return *this < other || *this == other;
};

bool AutoInfo::operator>=(const AutoInfo& other) const {
    return *this > other || *this == other;
};