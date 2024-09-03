#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
private:
    char* surname;
    char* birthDate;
    char* enrollmentDate;
    char* dismissalDate;
    char* address;
    char* group;

public:
    // Конструктор по умолчанию
    Student();

    // Конструктор с параметрами
    Student(const char* surname, const char* birthDate, const char* enrollmentDate, const char* dismissalDate, const char* address, const char* group);

    // Конструктор копирования
    Student(const Student& other);

    // Оператор присваивания
    Student& operator=(const Student& other);

    // Деструктор
    ~Student();

    // Геттеры и сеттеры
    const char* getSurname() const;
    void setSurname(const char* surname);

    const char* getBirthDate() const;
    void setBirthDate(const char* birthDate);

    const char* getEnrollmentDate() const;
    void setEnrollmentDate(const char* enrollmentDate);

    const char* getDismissalDate() const;
    void setDismissalDate(const char* dismissalDate);

    const char* getAddress() const;
    void setAddress(const char* address);

    const char* getGroup() const;
    void setGroup(const char* group);

    // Перегруженные операторы сравнения
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator==(const Student& other) const;

    // Вывод информации о студенте
    void print() const;

    // Сохранение и загрузка студента в бинарный файл
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

#endif // STUDENT_H
