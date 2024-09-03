#ifndef MENU_H
#define MENU_H

#include "DoublyLinkedList.h"
#include "Student.h"
#include <iostream>
#include <string>

class Menu {
private:
    DoublyLinkedList<Student> studentList;

public:
    Menu();
    void displayMenu();
    void addStudent();
    void removeStudent();
    void editStudent();
    void searchStudent();
    void sortStudents();
    void displayStudents();
    void saveToFile();
    void loadFromFile();
    void run();
};

#endif // MENU_H
