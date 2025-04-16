#include <string>

class AutoInfo {
public:
    std::string ownerName;      // ФИО владельца
    std::string carBrand;       // Марка автомобиля
    int productionYear;         // Год выпуска
    std::string licensePlate;   // Государственный номер
    std::string color;          // Цвет автомобиля

    AutoInfo() {
        ownerName = std::string();
        carBrand = std::string();
        productionYear = 0;
        licensePlate = std::string();
        color = std::string();
    };
    
    AutoInfo(const std::string& ownerName, 
             const std::string& carBrand, 
             int productionYear, 
             const std::string& licensePlate, 
             const std::string& color) {
        this->ownerName = ownerName;
        this->carBrand = carBrand;
        this->productionYear = productionYear;
        this->licensePlate = licensePlate;
        this->color = color;
    };
    
    ~AutoInfo() {};

    bool operator==(const AutoInfo& other) const {
        return licensePlate == other.licensePlate &&
               productionYear == other.productionYear &&
               carBrand == other.carBrand &&
               color == other.color &&
               ownerName == other.ownerName;
    }

    bool operator<(const AutoInfo& other) const {
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
    

    bool operator>(const AutoInfo& other) const {
        return !(*this < other);
    };
   
    bool operator<=(const AutoInfo& other) const {
        return *this < other || *this == other;
    };
    
    bool operator>=(const AutoInfo& other) const {
        return *this > other || *this == other;
    };
};