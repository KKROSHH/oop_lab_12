#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>

class Animal {
public:
    virtual void feed() const = 0;  // Віртуальна функція для годування
    virtual void print() const = 0; // Віртуальна функція для виведення даних
    virtual ~Animal() {}
};

class Predator : public Animal {
public:
    void feed() const override {
        std::cout << "I am a predator, I eat meat." << std::endl;
    }

    void print() const override {
        std::cout << "I am a predator." << std::endl;
    }
};

class Herbivore : public Animal {
public:
    void feed() const override {
        std::cout << "I am a herbivore, I eat plants." << std::endl;
    }

    void print() const override {
        std::cout << "I am a herbivore." << std::endl;
    }
};

class AnimalCollection {
    std::vector<Animal*> animals;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void printAll() const {
        for (const auto& animal : animals) {
            animal->print();
        }
    }

    ~AnimalCollection() {
        for (auto animal : animals) {
            delete animal;
        }
    }
};

void openFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("File not found!");
    }
    std::cout << "File opened successfully." << std::endl;
}

int main() {
    try {
        AnimalCollection collection;
        collection.addAnimal(new Predator());
        collection.addAnimal(new Herbivore());

        collection.printAll();

        // Перевірка файлу
        openFile("data.txt");

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}