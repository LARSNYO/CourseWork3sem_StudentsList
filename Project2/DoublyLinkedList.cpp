#include "DoublyLinkedList.h"
#include "Student.h"
#include <iostream>

// ����������� �� ���������
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// ����������
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    if (!head) return;

    Node<T>* current = head;
    do {
        Node<T>* next = current->next;
        delete current;
        current = next;
    } while (current != head);
}

// ����� ���������� �������� � ����� ������
template <typename T>
void DoublyLinkedList<T>::add(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

// ����� �������� �������� �� ������
template <typename T>
void DoublyLinkedList<T>::remove(const T& data) {
    if (!head) return;

    Node<T>* current = head;
    do {
        if (current->data == data) {
            if (current == head) {
                head = head->next;
                tail->next = head;
                head->prev = tail;
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    } while (current != head);
}

// ����� ��������� �������� �� �������
template <typename T>
T DoublyLinkedList<T>::get(int index) const {
    if (!head) throw std::out_of_range("������ ����");

    Node<T>* current = head;
    int count = 0;
    do {
        if (count == index) return current->data;
        current = current->next;
        count++;
    } while (current != head);

    throw std::out_of_range("������ ��� ���������");
}

// ����� ���������� ������
template <typename T>
void DoublyLinkedList<T>::sort() {
    if (!head || head == tail) return;

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;
        do {
            Node<T>* nextNode = current->next;
            if (current->data > nextNode->data) {
                std::swap(current->data, nextNode->data);
                swapped = true;
            }
            current = nextNode;
        } while (current->next != head);
    } while (swapped);
}

// ����� ������� �������� � ��������������� ������
template <typename T>
void DoublyLinkedList<T>::insert(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node<T>* current = head;
    do {
        if (current->data > data) {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;

            if (current == head) {
                head = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);

    // ���� ������� ����� ����
    add(data);
}

// ����� ���������� ������ � ����
template <typename T>
void DoublyLinkedList<T>::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
        return;
    }

    Node<T>* current = head;
    do {
        current->data.saveToFile(file);
        current = current->next;
    } while (current != head);

    file.close();
}

// ����� �������� ������ �� �����
template <typename T>
void DoublyLinkedList<T>::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "������ �������� ����� ��� ������." << std::endl;
        return;
    }

    while (file.peek() != EOF) {
        T data;
        data.loadFromFile(file);
        add(data);
    }

    file.close();
}

// ����� ������ ������
template <typename T>
void DoublyLinkedList<T>::display() const {
    if (isEmpty()) {
        std::cout << "������ ����." << std::endl;
        return;
    }

    Node<T>* current = head;
    do {
        current->data.print();
        current = current->next;
    } while (current != head);
}

// ������������ ������������� ������� ��� ������ Student
template class DoublyLinkedList<Student>;
