//
// Created by rafal on 20/10/18.
//
#include <vector>
#include "Movie.h"
#include <bits/unique_ptr.h>
#include <iostream>
#include <algorithm>

#ifndef SERIESAPPLICATION_POOL_H
#define SERIESAPPLICATION_POOL_H

template <class T>
class Pool {
private:
    std::vector<T> records;

public:
    const std::vector<T> &getRecords() const {
        return records;
    }

    T findbyName(std::string name) {
        for(auto i : records) {
            if(i -> getName() == name) {
                return i;
            }
        }
        return nullptr;
    }

    void remove (std::string name) {
        for(int i = 0; i < records.size(); i++) {
            if(records[i] -> getName() == name) {
                records.erase(records.begin() + i);
            }
        }
    }

    bool add(T t) {
        if(findbyName(t -> getName()) != nullptr) {
            std::cout << "Record with this name already exists" << std::endl;
            return false;
        }
        records.push_back(t);
        return true;
    }

    void sort() {
        std::sort(records.begin(),records.end(),comp);
    }

    static bool comp (Movie* m1, Movie* m2) {
        return m1->getRate() < m2 ->getRate();
    }

    void showAll() {
        for(auto i :records) {
            std :: cout << i -> getName() <<"fff\n";
            std:: cout << *i << "\n\n";
        }
    }
    bool operator += (T m) {
        return add(m);
    };
};


#endif //SERIESAPPLICATION_POOL_H