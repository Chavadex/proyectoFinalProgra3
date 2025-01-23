//
// Created by Salvador Cruz on 23/01/2025.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include <list>

#include "package.h"

template <typename T>
class HashTable {
public:

    HashTable(int size) {
        sizeTable = size;
        table.resize(size);
    }

    int hashFunction(const package& object) {
        int key = object.getTrackingCode();
        return key % sizeTable;
    }


    void insert(const package& package) {
        int index = hashFunction(package);
        table[index].push_back(package);
    }


    bool search(int trackingCode) {
        int index = hashFunction(trackingCode);
        for (const auto& item : table[index]) {
            if (item.getTrackingCode() == trackingCode) {
                return true;
            }
        }
        return false;
    }

    void remove(int trackingCode) {
        int index = trackingCode % sizeTable;
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->getTrackingCode() == trackingCode) {
                bucket.erase(it);
                return;
            }
        }
    }


    void display() const {
        for (int i = 0; i < sizeTable; ++i) {
            std::cout << "Indice: " << i << ": ";
            for (const auto& item : table[i]) {
                std::cout << item.getTrackingCode() << " -> ";
            }
            std::cout << "NULL\n";
        }
    }

private:
    int sizeTable;
    std::vector<std::list<package>> table;
};

#endif //HASHTABLE_H
