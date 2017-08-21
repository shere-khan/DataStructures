#include <iostream>
#include <ctime>
#include "btree.h"

int main() {
    btree *atree;
    atree = new btree();
    srand((unsigned)time(0));

    for (int i = 0; i < 10; i++) {
        atree->insert(rand());
    }
    node *anode = atree->search(4);

    atree->inorder();

    // std::cout << "node value: " << anode->key_value << "\n";
    return 0;
}
