//
// Created by Salvador Cruz on 20/01/2025.
//

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "cliente.h"

struct Node {
    cliente customer;
    Node* left;
    Node* right;
    int height;

    Node(const cliente& c) : customer(c), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { deleteTree(root); }

    void insert(const cliente& c) {
        root = insertNode(root, c);
    }

    void printTree() {
        printTreeHelper(root, 0);
    }

private:
    Node* root;

    int getNodeHeight(Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    int getBalance(Node* node) {
        return node == nullptr ? 0 : getNodeHeight(node->left) - getNodeHeight(node->right);
    }

    int maxHeight(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, const cliente& c) {
        if (node == nullptr)
            return new Node(c);

        if (c.getId_user() < node->customer.getId_user())
            node->left = insertNode(node->left, c);
        else if (c.getId_user() > node->customer.getId_user())
            node->right = insertNode(node->right, c);
        else
            return node;

        node->height = 1 + maxHeight(getNodeHeight(node->left), getNodeHeight(node->right));

        int balance = getBalance(node);

        // Rotaciones para balancear el árbol.
        if (balance > 1 && c.getId_user() < node->left->customer.getId_user())
            return rightRotate(node);

        if (balance < -1 && c.getId_user() > node->right->customer.getId_user())
            return leftRotate(node);

        if (balance > 1 && c.getId_user() > node->left->customer.getId_user()) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && c.getId_user() < node->right->customer.getId_user()) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void printTreeHelper(Node* node, int space) {
        if (node == nullptr)
            return;


        space += 5;


        printTreeHelper(node->right, space);


        std::cout << std::endl;
        for (int i = 5; i < space; i++)
            std::cout << " ";

        std::cout << node->customer.getId_user() << std::endl;


        printTreeHelper(node->left, space);
    }

    void deleteTree(Node* node) {
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};




#endif //AVLTREE_H
