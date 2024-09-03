#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

#endif // NODE_H
