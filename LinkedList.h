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
    
    void insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
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
    
    size_t getSize() const {
        size_t counter{0};

        Node<T>* current = head;

        while (current != nullptr) {
            counter++;
            current = current->next;
        }

        return counter;
    }
    
    void reverse() {

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;  
            prev = current;     
            current = nextNode;   
        }

        head = prev;
    }
    
    bool detectCycle() const {
        
    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          
        fast = fast->next->next;  

        if (slow == fast) {
            return true;
        }
    }

    return false;  
    
        
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
    
    Node<T>* getNthFromEnd(size_t n) const {
    Node<T>* slow = head;
    Node<T>* fast = head;

    for (size_t i = 0; i < n; i++) {
        if (fast == nullptr) return nullptr; 
        fast = fast->next;
    };

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    };

    return slow;
    }
};

#endif
