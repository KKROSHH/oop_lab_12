#include "Passanger_T.h"

int main() {
    Passanger_Transportation transport;

    int choice;
    do {
        std::cout << "\n1. Create new transportation\n"
                  << "2. Print all transportation details\n"
                  << "3. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            transport.Pass_Create(); // Створення нового перевезення
            break;
        case 2:
            std::cout << "\nLoading and printing all transportation details...\n";
            transport.LoadAllFromFile("transportations.txt"); // Завантаження та друк
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
