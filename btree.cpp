//
// Created by Justin on 8/20/2017.
//

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "btree.h"

btree::btree() {
    root = NULL;
}

void btree::destroy_tree(node *leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, node *leaf) {
    if (key < leaf->key_value)
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    else if (key > leaf->key_value)
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
}

void btree::insert(int key) {
    if (root != NULL)
        insert(key, root);
    else {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
};

node* btree::search(int key) {
    return search(key, root);
};

node* btree::search(int key, node *leaf) {
    if (leaf != NULL) {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        if (key >= leaf->key_value)
            return search(key, leaf->right);
    }
    else return NULL;
}

void btree::inorder() {
    if (root != NULL)
        inorder(root);
    else
        throw std::invalid_argument("root is null");
}

void btree::inorder(node *leaf) {
    if (leaf->left != NULL)
        inorder(leaf->left);
    std::cout << "node value: " << leaf->key_value << "\n";
    if (leaf->right != NULL)
        inorder(leaf->right);
}
