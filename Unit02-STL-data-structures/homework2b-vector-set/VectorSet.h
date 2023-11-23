#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class VectorSet {
private:
    std::vector<T> elements;
public:
    bool contains(T item) const {  // return true if item is in the set and false if not
        // implement contains here
        if (find(elements.begin(), elements.end(), item) == elements.end()) {
            return false;
        }
        else {
            return true;
        }
    }

    bool insert(T item) {
        // implement insert here
        if(contains(item) == false) {
            elements.push_back(item);
            return true;
        }
        else {
            return false;
        }
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        if(contains(item) == false) {
            return false;
        }
        else {
            elements.erase(find(elements.begin(), elements.end(), item));
            return true;
        }
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return elements.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (elements.empty() == true) {
            return true;
        }
        else{
            return false;
        }

        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        elements.clear();

        // remove all items from the set
    }
};
