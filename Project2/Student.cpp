#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>
#include <cstring>
#include <fstream>

// Конструктор по умолчанию
Student::Student() {
    surname = new char[1];
    surname[0] = '\0';
    birthDate = new char[1];
    birthDate[0] = '\0';
    enrollmentDate = new char[1];
    enrollmentDate[0] = '\0';
    dismissalDate = new char[1];
    dismissalDate[0] = '\0';
    address = new char[1];
    address[0] = '\0';
    group = new char[1];
    group[0] = '\0';
}

// Конструктор с параметрами
Student::Student(const char* surname, const char* birthDate, const char* enrollmentDate, const char* dismissalDate, const char* address, const char* group) {
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
    this->birthDate = new char[strlen(birthDate) + 1];
    strcpy(this->birthDate, birthDate);
    this->enrollmentDate = new char[strlen(enrollmentDate) + 1];
    strcpy(this->enrollmentDate, enrollmentDate);
    this->dismissalDate = new char[strlen(dismissalDate) + 1];
    strcpy(this->dismissalDate, dismissalDate);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    this->group = new char[strlen(group) + 1];
    strcpy(this->group, group);
}

// Конструктор копирования
Student::Student(const Student& other) {
    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);
    birthDate = new char[strlen(other.birthDate) + 1];
    strcpy(birthDate, other.birthDate);
    enrollmentDate = new char[strlen(other.enrollmentDate) + 1];
    strcpy(enrollmentDate, other.enrollmentDate);
    dismissalDate = new char[strlen(other.dismissalDate) + 1];
    strcpy(dismissalDate, other.dismissalDate);
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
    group = new char[strlen(other.group) + 1];
    strcpy(group, other.group);
}

// Оператор присваивания
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] surname;
        delete[] birthDate;
        delete[] enrollmentDate;
        delete[] dismissalDate;
        delete[] address;
        delete[] group;

        surname = new char[strlen(other.surname) + 1];
        strcpy(surname, other.surname);
        birthDate = new char[strlen(other.birthDate) + 1];
        strcpy(birthDate, other.birthDate);
        enrollmentDate = new char[strlen(other.enrollmentDate) + 1];
        strcpy(enrollmentDate, other.enrollmentDate);
        dismissalDate = new char[strlen(other.dismissalDate) + 1];
        strcpy(dismissalDate, other.dismissalDate);
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
        group = new char[strlen(other.group) + 1];
        strcpy(group, other.group);
    }
    return *this;
}

// Деструктор
Student::~Student() {
    delete[] surname;
    delete[] birthDate;
    delete[] enrollmentDate;
    delete[] dismissalDate;
    delete[] address;
    delete[] group;
}

// Геттеры и сеттеры
const char* Student::getSurname() const { return surname; }
void Student::setSurname(const char* surname) {
    delete[] this->surname;
    this->surname = new char[strlen(surname) + 1];
    strcpy(this->surname, surname);
}

const char* Student::getBirthDate() const { return birthDate; }
void Student::setBirthDate(const char* birthDate) {
    delete[] this->birthDate;
    this->birthDate = new char[strlen(birthDate) + 1];
    strcpy(this->birthDate, birthDate);
}

const char* Student::getEnrollmentDate() const { return enrollmentDate; }
void Student::setEnrollmentDate(const char* enrollmentDate) {
    delete[] this->enrollmentDate;
    this->enrollmentDate = new char[strlen(enrollmentDate) + 1];
    strcpy(this->enrollmentDate, enrollmentDate);
}

const char* Student::getDismissalDate() const { return dismissalDate; }
void Student::setDismissalDate(const char* dismissalDate) {
    delete[] this->dismissalDate;
    this->dismissalDate = new char[strlen(dismissalDate) + 1];
    strcpy(this->dismissalDate, dismissalDate);
}

const char* Student::getAddress() const { return address; }
void Student::setAddress(const char* address) {
    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

const char* Student::getGroup() const { return group; }
void Student::setGroup(const char* group) {
    delete[] this->group;
    this->group = new char[strlen(group) + 1];
    strcpy(this->group, group);
}

// Перегруженные операторы сравнения
bool Student::operator<(const Student& other) const {
    return strcmp(surname, other.surname) < 0;
}

bool Student::operator>(const Student& other) const {
    return strcmp(surname, other.surname) > 0;
}

bool Student::operator==(const Student& other) const {
    return strcmp(surname, other.surname) == 0;
}

// Метод для вывода информации о студенте
void Student::print() const {
    std::cout << "Фамилия: " << surname << ", "
        << "Дата рождения: " << birthDate << ", "
        << "Дата поступления: " << enrollmentDate << ", "
        << "Дата отчисления: " << dismissalDate << ", "
        << "Адрес: " << address << ", "
        << "Группа: " << group << std::endl;
}

// Сохранение и загрузка студента в бинарный файл
void Student::saveToFile(std::ofstream& file) const {
    // Пример: записать строки в файл (возможно, нужно будет использовать фиксированную длину)
    size_t length;

    length = strlen(surname);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(surname, length);

    length = strlen(birthDate);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(birthDate, length);

    length = strlen(enrollmentDate);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(enrollmentDate, length);

    length = strlen(dismissalDate);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(dismissalDate, length);

    length = strlen(address);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(address, length);

    length = strlen(group);
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(group, length);
}

void Student::loadFromFile(std::ifstream& file) {
    size_t length;

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] surname;
    surname = new char[length + 1];
    file.read(surname, length);
    surname[length] = '\0';

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] birthDate;
    birthDate = new char[length + 1];
    file.read(birthDate, length);
    birthDate[length] = '\0';

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] enrollmentDate;
    enrollmentDate = new char[length + 1];
    file.read(enrollmentDate, length);
    enrollmentDate[length] = '\0';

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] dismissalDate;
    dismissalDate = new char[length + 1];
    file.read(dismissalDate, length);
    dismissalDate[length] = '\0';

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] address;
    address = new char[length + 1];
    file.read(address, length);
    address[length] = '\0';

    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    delete[] group;
    group = new char[length + 1];
    file.read(group, length);
    group[length] = '\0';
}
