//
// Created by Justin on 8/21/2017.
//

class HashEntry {
private:
    int key;
    int value;
public:
    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }
};

class LinkedHashTable {
private:
    HashEntry **table;
public:
};