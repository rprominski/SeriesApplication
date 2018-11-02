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
                //std::cout<<"YESSS";
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
        std::sort(records.begin(),records.end());
    }
};
#endif //SERIESAPPLICATION_POOL_H