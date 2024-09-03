#include "Menu.h"
#include <iostream>
#include <string>

// Конструктор по умолчанию
Menu::Menu() {}

// Метод отображения меню
void Menu::displayMenu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Добавить студента" << std::endl;
    std::cout << "2. Удалить студента" << std::endl;
    std::cout << "3. Редактировать студента" << std::endl;
    std::cout << "4. Поиск студента" << std::endl;
    std::cout << "5. Сортировать студентов" << std::endl;
    std::cout << "6. Показать всех студентов" << std::endl;
    std::cout << "7. Сохранить в файл" << std::endl;
    std::cout << "8. Загрузить из файла" << std::endl;
    std::cout << "9. Выйти" << std::endl;
    std::cout << "Выберите опцию: ";
}

// Метод для добавления студента
void Menu::addStudent() {
    char surname[50], birthDate[50], enrollmentDate[50], dismissalDate[50], address[50], group[50];
    std::cout << "Введите фамилию: ";
    std::cin.ignore();
    std::cin.getline(surname, 50);
    std::cout << "Введите дату рождения (дд.мм.гггг): ";
    std::cin.getline(birthDate, 50);
    std::cout << "Введите дату поступления (дд.мм.гггг): ";
    std::cin.getline(enrollmentDate, 50);
    std::cout << "Введите дату отчисления (дд.мм.гггг): ";
    std::cin.getline(dismissalDate, 50);
    std::cout << "Введите адрес: ";
    std::cin.getline(address, 50);
    std::cout << "Введите группу: ";
    std::cin.getline(group, 50);

    Student student(surname, birthDate, enrollmentDate, dismissalDate, address, group);
    studentList.add(student);
    std::cout << "Студент добавлен!" << std::endl;
}

// Метод для удаления студента
void Menu::removeStudent() {
    char surname[50];
    std::cout << "Введите фамилию студента для удаления: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            studentList.remove(current->data);
            std::cout << "Студент удален!" << std::endl;
            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "Студент не найден." << std::endl;
}

// Метод для редактирования студента
void Menu::editStudent() {
    char surname[50];
    std::cout << "Введите фамилию студента для редактирования: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            int choice;
            do {
                std::cout << "Выберите, что хотите отредактировать:" << std::endl;
                std::cout << "1. Фамилия" << std::endl;
                std::cout << "2. Дата рождения" << std::endl;
                std::cout << "3. Дата поступления" << std::endl;
                std::cout << "4. Дата отчисления" << std::endl;
                std::cout << "5. Адрес" << std::endl;
                std::cout << "6. Группа" << std::endl;
                std::cout << "7. Закончить редактирование" << std::endl;
                std::cout << "Ваш выбор: ";
                std::cin >> choice;

                // Буфер для хранения новых данных
                char newData[50];

                switch (choice) {
                case 1:
                    std::cout << "Введите новую фамилию: ";
                    std::cin.ignore();  // Игнорируем оставшийся '\n' в буфере
                    std::cin.getline(newData, 50);
                    current->data.setSurname(newData);
                    std::cout << "Фамилия обновлена!" << std::endl;
                    break;
                case 2:
                    std::cout << "Введите новую дату рождения (дд.мм.гггг): ";
                    std::cin.ignore();
                    std::cin.getline(newData, 50);
                    current->data.setBirthDate(newData);
                    std::cout << "Дата рождения обновлена!" << std::endl;
                    break;
                case 3:
                    std::cout << "Введите новую дату поступления (дд.мм.гггг): ";
                    std::cin.ignore();
                    std::cin.getline(newData, 50);
                    current->data.setEnrollmentDate(newData);
                    std::cout << "Дата поступления обновлена!" << std::endl;
                    break;
                case 4:
                    std::cout << "Введите новую дату отчисления (дд.мм.гггг): ";
                    std::cin.ignore();
                    std::cin.getline(newData, 50);
                    current->data.setDismissalDate(newData);
                    std::cout << "Дата отчисления обновлена!" << std::endl;
                    break;
                case 5:
                    std::cout << "Введите новый адрес: ";
                    std::cin.ignore();
                    std::cin.getline(newData, 50);
                    current->data.setAddress(newData);
                    std::cout << "Адрес обновлен!" << std::endl;
                    break;
                case 6:
                    std::cout << "Введите новую группу: ";
                    std::cin.ignore();
                    std::cin.getline(newData, 50);
                    current->data.setGroup(newData);
                    std::cout << "Группа обновлена!" << std::endl;
                    break;
                case 7:
                    std::cout << "Завершение редактирования." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор. Пожалуйста, выберите снова." << std::endl;
                    break;
                }
            } while (choice != 7);  // Цикл продолжается, пока пользователь не выберет "Закончить редактирование"

            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "Студент не найден." << std::endl;
}

// Метод для поиска студента
void Menu::searchStudent() {
    char surname[50];
    std::cout << "Введите фамилию студента для поиска: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            current->data.print();
            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "Студент не найден." << std::endl;
}

// Метод для сортировки студентов
void Menu::sortStudents() {
    studentList.sort();
    std::cout << "Студенты отсортированы!" << std::endl;
}

// Метод для отображения всех студентов
void Menu::displayStudents() {
    studentList.display();
}

// Метод для сохранения списка студентов в файл
void Menu::saveToFile() {
    std::string filename;
    std::cout << "Введите имя файла для сохранения: ";
    std::cin >> filename;

    studentList.saveToFile(filename);
    std::cout << "Список студентов сохранен в файл!" << std::endl;
}

// Метод для загрузки списка студентов из файла
void Menu::loadFromFile() {
    std::string filename;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> filename;

    studentList.loadFromFile(filename);
    std::cout << "Список студентов загружен из файла!" << std::endl;
}

// Метод для запуска меню
void Menu::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            editStudent();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            sortStudents();
            break;
        case 6:
            displayStudents();
            break;
        case 7:
            saveToFile();
            break;
        case 8:
            loadFromFile();
            break;
        case 9:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 9);
}
