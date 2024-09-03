#include "Menu.h"
#include <iostream>
#include <string>

// ����������� �� ���������
Menu::Menu() {}

// ����� ����������� ����
void Menu::displayMenu() {
    std::cout << "����:" << std::endl;
    std::cout << "1. �������� ��������" << std::endl;
    std::cout << "2. ������� ��������" << std::endl;
    std::cout << "3. ������������� ��������" << std::endl;
    std::cout << "4. ����� ��������" << std::endl;
    std::cout << "5. ����������� ���������" << std::endl;
    std::cout << "6. �������� ���� ���������" << std::endl;
    std::cout << "7. ��������� � ����" << std::endl;
    std::cout << "8. ��������� �� �����" << std::endl;
    std::cout << "9. �����" << std::endl;
    std::cout << "�������� �����: ";
}

// ����� ��� ���������� ��������
void Menu::addStudent() {
    char surname[50], birthDate[50], enrollmentDate[50], dismissalDate[50], address[50], group[50];
    std::cout << "������� �������: ";
    std::cin.ignore();
    std::cin.getline(surname, 50);
    std::cout << "������� ���� �������� (��.��.����): ";
    std::cin.getline(birthDate, 50);
    std::cout << "������� ���� ����������� (��.��.����): ";
    std::cin.getline(enrollmentDate, 50);
    std::cout << "������� ���� ���������� (��.��.����): ";
    std::cin.getline(dismissalDate, 50);
    std::cout << "������� �����: ";
    std::cin.getline(address, 50);
    std::cout << "������� ������: ";
    std::cin.getline(group, 50);

    Student student(surname, birthDate, enrollmentDate, dismissalDate, address, group);
    studentList.add(student);
    std::cout << "������� ��������!" << std::endl;
}

// ����� ��� �������� ��������
void Menu::removeStudent() {
    char surname[50];
    std::cout << "������� ������� �������� ��� ��������: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            studentList.remove(current->data);
            std::cout << "������� ������!" << std::endl;
            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "������� �� ������." << std::endl;
}

// ����� ��� �������������� ��������
void Menu::editStudent() {
    char surname[50];
    std::cout << "������� ������� �������� ��� ��������������: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            char newAddress[50];
            std::cout << "������� ����� �����: ";
            std::cin >> newAddress;
            current->data.setAddress(newAddress);
            std::cout << "����� ��������!" << std::endl;
            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "������� �� ������." << std::endl;
}

// ����� ��� ������ ��������
void Menu::searchStudent() {
    char surname[50];
    std::cout << "������� ������� �������� ��� ������: ";
    std::cin >> surname;

    Node<Student>* current = studentList.getHead();
    do {
        if (strcmp(current->data.getSurname(), surname) == 0) {
            current->data.print();
            return;
        }
        current = current->next;
    } while (current != studentList.getHead());

    std::cout << "������� �� ������." << std::endl;
}

// ����� ��� ���������� ���������
void Menu::sortStudents() {
    studentList.sort();
    std::cout << "�������� �������������!" << std::endl;
}

// ����� ��� ����������� ���� ���������
void Menu::displayStudents() {
    studentList.display();
}

// ����� ��� ���������� ������ ��������� � ����
void Menu::saveToFile() {
    std::string filename;
    std::cout << "������� ��� ����� ��� ����������: ";
    std::cin >> filename;

    studentList.saveToFile(filename);
    std::cout << "������ ��������� �������� � ����!" << std::endl;
}

// ����� ��� �������� ������ ��������� �� �����
void Menu::loadFromFile() {
    std::string filename;
    std::cout << "������� ��� ����� ��� ��������: ";
    std::cin >> filename;

    studentList.loadFromFile(filename);
    std::cout << "������ ��������� �������� �� �����!" << std::endl;
}

// ����� ��� ������� ����
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
            std::cout << "����� �� ���������." << std::endl;
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����." << std::endl;
            break;
        }
    } while (choice != 9);
}
