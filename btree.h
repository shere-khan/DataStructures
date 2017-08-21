//
// Created by Justin on 8/20/2017.
//

#ifndef DATASTRUCTURES_BTREE_H
#define DATASTRUCTURES_BTREE_H

struct node {
    int key_value;
    node *left;
    node *right;
};

class btree {
    public:
        btree();

        ~btree();

        void insert(int key);

        node* search(int key);

        void destroy_tree();

        void inorder();

    private:
        void destroy_tree(node *leaf);

        void insert(int key, node *leaf);

        node* search(int key, node *leaf);

        node* root;

        void inorder(node *leaf);
};


#endif //DATASTRUCTURES_BTREE_H
