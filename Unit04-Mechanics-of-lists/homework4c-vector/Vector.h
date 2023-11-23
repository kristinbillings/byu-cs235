#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:
    Vector() : count(0), capacity(1) {
        array = new T[capacity];
    }

    ~Vector() { delete[] array; }

    void makeBigger() {
        T* tmp = array;
        size_t old_cap = capacity;
        capacity *= 2;
        array = new T[capacity];
        for (int i = 0; i < old_cap; i++) {
            array[i] = tmp[i];
        }
        delete[] tmp;
    }

    void push_back(T item) {
        // implement push_back here
        if (count == capacity) {
            makeBigger();
        }
        array[count++] = item;
    }

    void insert(T item, int position) {
        // implement insert here
        if (position > count || position < 0) {
            throw std::out_of_range("Position is out of range");
        }
        if (count == capacity) {
            makeBigger();
        }
        for(int i = count; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = item;
        count++;
    }

    void remove(int position) {
        // implement remove here
        if (position >= count || position < 0) {
            throw std::out_of_range("Position is out of range");
        }
        for (int i = position; i < count - 1; i++) {
            array[i] = array[i + 1];
        }
        count--;
    }

    T& operator[](int index) {
        // implement operator[] here
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    int size() const {
        // implement size here
        return count;
    }

    void clear() {
        // implement clear here
        delete[] array;
        array = new T[capacity];
        count = 0;
    }
private:
    T* array;
    int count;
    int capacity;
};
