#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_front(T item) {
        // implement push_front here
        Node* newNode = new Node(item);
        newNode->value = item;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        count++;
    }
    void push_back(T item) {
        Node* newNode = new Node(item);
        newNode->value = item;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }

        tail = newNode;

        if (head == nullptr) {
            head = newNode;
        }

        count++;

        // implement push_back here
    }
    void insert(T item, int position) {
        if (position < 0 || position > count) {
            throw std::out_of_range("Position is out of range");
        }

        Node* newNode = new Node(item);
        Node* current = head;

        if (position == 0) {
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;

            if (tail == nullptr) {
                tail = newNode;
            }

            count++;
            return;
        }

        for (int i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                throw std::out_of_range("Position is out of range");
            }
            current = current->next;
        }

        Node* prev = current;
        Node* next = (current == nullptr) ? nullptr : current->next;;

        newNode->prev = prev;
        newNode->next = next;

        if (prev != nullptr) {
            prev->next = newNode;
        } else {
            // If prev is nullptr, it means we are inserting at the beginning
            head = newNode;
        }

        if (next != nullptr) {
            next->prev = newNode;
        } else {
            // If next is nullptr, it means we are inserting at the end
            tail = newNode;
        }

        count++;
    }
    void pop_front() {
        // implement pop_front here
        if (head == nullptr) {
            throw std::length_error("List is empty");
        }

        //T value = head->value;
        Node* newHead = head->next;

        if (newHead != nullptr) {
            newHead->prev = nullptr;
        }

        delete head;
        head = newHead;

        if (newHead == nullptr) {
            tail = nullptr;
        }

        count--;

        //return value;
    }
    void pop_back() {
        // implement pop_back here
        if (tail == nullptr) {
            throw std::length_error("List is empty");
        }

       // T value = tail->value;
        Node* newTail = tail->prev;

        if (newTail != nullptr) {
            newTail->next = nullptr;
        }

        delete tail;
        tail = newTail;

        if (newTail == nullptr) {
            head = nullptr;
        }

        count--;

        //return value;
    }
    void remove(int position) {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        if (position < 0 || position >= count) {
            throw std::out_of_range("Position is out of range");
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            if (current == nullptr) {
                throw std::out_of_range("Position is out of range");
            }
            current = current->next;
        }

        Node* prev = current->prev;
        Node* next = current->next;

        if (prev != nullptr) {
            prev->next = next;
        } else {
            // If prev is nullptr, it means we are removing the first node
            head = next;
        }

        if (next != nullptr) {
            next->prev = prev;
        } else {
            // If next is nullptr, it means we are removing the last node
            tail = prev;
        }

        delete current;
        count--;
    }
    const T& front() const {
        if (head == nullptr) {
            throw std::length_error("List is empty");
        }
        return head->value;
    }
    const T& back() const {
        if (tail == nullptr) {
            throw std::length_error("List is empty");
        }
        return tail->value;
    }
    const T& at(int index) const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current == nullptr) {
                throw std::out_of_range("Index is out of range");
            }
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("Index is out of range");
        }
        return current->value;
    }

    bool contains(const T& item) const {
        // implement contains here
        if (head == nullptr) {
            return false;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int size() const {
        // implement size here
        return count;
    }
    void clear() {
        // implement clear here
        while (head != nullptr) {
            remove(0);
        }
    }

private:
    Node* head;
    Node* tail;
    int count;
};
