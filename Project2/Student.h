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
    // ����������� �� ���������
    Student();

    // ����������� � �����������
    Student(const char* surname, const char* birthDate, const char* enrollmentDate, const char* dismissalDate, const char* address, const char* group);

    // ����������� �����������
    Student(const Student& other);

    // �������� ������������
    Student& operator=(const Student& other);

    // ����������
    ~Student();

    // ������� � �������
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

    // ������������� ��������� ���������
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    bool operator==(const Student& other) const;

    // ����� ���������� � ��������
    void print() const;

    // ���������� � �������� �������� � �������� ����
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

#endif // STUDENT_H
