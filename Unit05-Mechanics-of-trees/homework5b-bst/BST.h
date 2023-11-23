#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    BST() {
        // implement the contructor here
        root = nullptr;
    }

    ~BST() {
        // implement the destructor here
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        // return a pointer to the tree's root node
    }

    bool insert(T item) {
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
        return insertHelper(root, item)
    }
    bool insertHelper(Node*&T, int v) { //
        if(T==nullptr) {
            T = new Node(v);
            return true;
        }
        if (T->value == v) {
            return false;
        }
        else if (v > T->value) {
            return insertHelper(T->right, v);
        }
        else {
            return insertHelper(T->left, v);
        }
    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool removeHelper(Node *& T, int v) { // this is not set up correctly
        if(T== nullptr) {
            return false;
        }
        if(T->value == v){
            //no children just remove it

        }
        else if () {
            //if one child, remove and assign grandparent to grandchild
        }
        else { //2 children
            //find in order predecessor (down right side of left sub tree of where you are removing)
            //replace value of node deleting with in order predecessor
            // removeHelper(T
        }
    }

    bool contains(T item) const {
        // implement contains here
        // return true if item is in the tree, false otherwise
    }

    void clear() {
        // implement clear here
        // remove all nodes from the tree
    }

    int size() const {
        // implement size here
        // return the number of nodes in the tree
    }
private:
    Node root = nullptr;
};
