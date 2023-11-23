#pragma once
#include <iostream>

using namespace std;

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
        //Node(T v) {
          //  value = v;
            //next = nullptr;
        //}
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here

        return head;
    }

    void push_back(T item) {
        // 1. create the node
        Node* nodeNuevo = new Node(item);

        // 2. update tail next to point to new node
        if (tail != nullptr) {
            tail->next = nodeNuevo;
        }

        //  3. then update head and tail appropriately
        tail = nodeNuevo;
        if (head == nullptr) {
            head = nodeNuevo;
        }

        count++;
    }

    void pop_back() {
        // implement pop_back here
        //remove(count-1);

        if (head == nullptr) {
            return; // Empty list, nothing to pop
        }

        // If there's only one element in the list, set head and tail to nullptr
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            count = 0;
        } else {
            // If there are multiple elements, find the second-to-last element and update its next pointer
            Node *itr = head;
            while (itr->next != tail) {
                itr = itr->next;
            }
            delete tail;
            tail = itr;
            tail->next = nullptr;
            count--;
        }
    }

    const T& front() const {
        // implement front here
        return head->value;
    }

    void remove(int position) { //this gets rid of the pointer (maybe??)
        if (head == nullptr){
            return;
        }
        if (position == 0) {
            Node* tmp = head;
            head = head->next; //gives the memory address of the second node
            delete tmp;
        }
        else{
            //get pointer (itr) to item before position
             Node* itr = head;
             for(int i = 0; i <(position-1); i++) {
                 itr = itr->next;
             }

             Node* tmp = itr->next;
             itr->next = itr->next->next; //skip the item we don't want anymore
             delete tmp;
        }
        count--;
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

    void print() {
        cout << "The items in the linked list are: ";
        Node* itr = head;
        while (itr != nullptr) {
            cout << itr->value << ", ";
            itr = itr->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int count;
};
