#pragma once

#include "Transportation.h"
#include "Passanger_T.h" // Включаємо Passanger_T.h, де вже визначено InvalidInputException

class Cargo_Transportation : public Transportation {
private:
    double Max_Load;     // Максимальна вантажопідйомність
    double Current_Load; // Поточна вага вантажу

public:
    Cargo_Transportation()
        : Max_Load(0), Current_Load(0) {}

    // Метод для створення та вводу даних
    void Cargo_Create() {
        try {
            std::cout << "Enter the city of departure: ";
            std::getline(std::cin, Departure);
            if (Departure.empty()) throw InvalidInputException("City of departure cannot be empty!");

            std::cout << "Enter the city of destination: ";
            std::getline(std::cin, Destination);
            if (Destination.empty()) throw InvalidInputException("City of destination cannot be empty!");

            std::cout << "Enter the vehicle: ";
            std::getline(std::cin, Vehicle);
            if (Vehicle.empty()) throw InvalidInputException("Vehicle cannot be empty!");

            std::cout << "Enter the transportation ID: ";
            std::cin >> Transportation_ID;
            if (Transportation_ID <= 0) throw InvalidInputException("Transportation ID must be a positive integer!");

            std::cout << "Enter the transportation time in minutes: ";
            std::cin >> Transportation_Time;
            if (Transportation_Time <= 0) throw InvalidInputException("Transportation time must be positive!");

            std::cout << "Enter the break time in minutes: ";
            std::cin >> Break_Time;
            if (Break_Time <= 0) throw InvalidInputException("Break time must be positive!");

            std::cout << "Enter the maximum load capacity (kg): ";
            std::cin >> Max_Load;
            if (Max_Load <= 0) throw InvalidInputException("Max load must be a positive value!");

            std::cout << "Enter the current load (kg): ";
            std::cin >> Current_Load;
            if (Current_Load < 0) throw InvalidInputException("Current load cannot be negative!");
            if (Current_Load > Max_Load) throw InvalidInputException("Current load cannot exceed max load!");

        } catch (const InvalidInputException& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    void SaveToFile(std::ofstream& out) const override {
        Transportation::SaveToFile(out);
        out << Max_Load << '\n'
            << Current_Load << '\n';
    }

    void LoadFromFile(std::ifstream& in) override {
        Transportation::LoadFromFile(in);
        in >> Max_Load >> Current_Load;
        in.ignore();
    }

    void Print() const override {
        Transportation::Print();
        std::cout << "Max Load: " << Max_Load << " kg\n"
                  << "Current Load: " << Current_Load << " kg\n";
    }
};
