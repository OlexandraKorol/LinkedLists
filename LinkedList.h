#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    Node<T>* search(T value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void deleteValue(T value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node<T>* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
                return;
            }
            current = current->next;
        }
    }

    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << " -> nullptr" << endl;
    }
};

#endif