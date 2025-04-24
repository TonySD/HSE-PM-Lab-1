#pragma once
#include <string>

class AutoInfo {
public:
    std::string ownerName;      // ФИО владельца
    std::string carBrand;       // Марка автомобиля
    int productionYear;         // Год выпуска
    std::string licensePlate;   // Государственный номер
    std::string color;          // Цвет автомобиля

    AutoInfo();
    AutoInfo(const std::string& ownerName, 
             const std::string& carBrand, 
             int productionYear, 
             const std::string& licensePlate, 
             const std::string& color);
    ~AutoInfo();

    bool operator==(const AutoInfo& other) const;
    bool operator!=(const AutoInfo& other) const;
    bool operator<(const AutoInfo& other) const;
    bool operator>(const AutoInfo& other) const;
    bool operator<=(const AutoInfo& other) const;
    bool operator>=(const AutoInfo& other) const;
};