#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <iostream>
#include <fstream>

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Функции для работы с двусвязным списком
    void add(const T& data);
    void remove(const T& data);
    T get(int index) const;
    void sort();
    void insert(const T& data);

    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

    void display() const;

    Node<T>* getHead() const {
        return head;
    }

    // Проверка на пустоту списка
    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif // DOUBLY_LINKED_LIST_H
