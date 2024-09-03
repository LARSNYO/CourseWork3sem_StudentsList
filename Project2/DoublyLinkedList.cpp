#include "DoublyLinkedList.h"
#include "Student.h"
#include <iostream>

// Конструктор по умолчанию
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор
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

// Метод добавления элемента в конец списка
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

// Метод удаления элемента из списка
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

// Метод получения элемента по индексу
template <typename T>
T DoublyLinkedList<T>::get(int index) const {
    if (!head) throw std::out_of_range("Список пуст");

    Node<T>* current = head;
    int count = 0;
    do {
        if (count == index) return current->data;
        current = current->next;
        count++;
    } while (current != head);

    throw std::out_of_range("Индекс вне диапазона");
}

// Метод сортировки списка
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

// Метод вставки элемента в отсортированный список
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

    // Если вставка после всех
    add(data);
}

// Метод сохранения списка в файл
template <typename T>
void DoublyLinkedList<T>::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    Node<T>* current = head;
    do {
        current->data.saveToFile(file);
        current = current->next;
    } while (current != head);

    file.close();
}

// Метод загрузки списка из файла
template <typename T>
void DoublyLinkedList<T>::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return;
    }

    while (file.peek() != EOF) {
        T data;
        data.loadFromFile(file);
        add(data);
    }

    file.close();
}

// Метод вывода списка
template <typename T>
void DoublyLinkedList<T>::display() const {
    if (isEmpty()) {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    Node<T>* current = head;
    do {
        current->data.print();
        current = current->next;
    } while (current != head);
}

// Эксплицитная инстанцировка шаблона для класса Student
template class DoublyLinkedList<Student>;
