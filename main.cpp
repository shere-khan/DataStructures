#include <iostream>
#include <ctime>
#include "btree.h"

void changeValue(int &r) {
    r = 40;
}

void changePointerValue(int* &m, int x) {
    std::cout << "address of changepointervalue x: " << &x << "\n";
    std::cout << "value of changepointervalue x: " << x << "\n";
    m = &x;
//    m = new int;
    *m = x;
}

void changePointerValue(int* m) {
    *m = 19;
}

void pointerAddress(int *m) {
    std::cout << "pointer m: " << m << "\n";
}

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
    int *x;
    int y = 17;
    x = &y;

    std::cout << "*x: " << *x << "\n";
    std::cout << "y: " << y << "\n";

    changeValue(y);

    std::cout << "*x: " << *x << "\n";
    std::cout << "y: " << y << "\n";

    int *m = &y;

    std::cout << "m: " << m << "\n";
    std::cout << "address of : " << m << "\n";
    changePointerValue(m);
    std::cout << "m: " << m << "\n";

    int p = 20;
    int *h = &p;
    int t = 30;
    std::cout << "pointer address outside of function: " << h << "\n";
    std::cout << "pointer value outside of function: " << *h << "\n";
    pointerAddress(h);
    int e = 18;
    std::cout << "*h: " << *h << "\n";
    std::cout << "address of e: " << &e << "\n";
    std::cout << "address of p: " << &p << "\n";
    std::cout << "pointer addres outside of function before change: " << h << "\n";
    std::cout << "pointer value outside of function before change: " << *h << "\n";
    changePointerValue(h, 18);
    std::cout << "pointer addres outside of function after change: " << h << "\n";
    std::cout << "pointer value outside of function after change: " << *h << "\n";
    std::cout << "e value outside of function after change: " << e << "\n";

    return 0;
}
