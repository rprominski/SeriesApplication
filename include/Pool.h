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
        auto r = std::find(records.begin(),records.end(),name);
        if( r != records.end()) {
            return *r;
        }
        return T();
    }

    bool exist(std::string name) {
        return (std::find(records.begin(),records.end(),name)!= records.end()) ? true : false;
    }

    void remove (std::string name) {
        records.erase(records.find(name));
    }

    bool add(T t) {
        if(exist(t.getName())) {
            std::cout << "Record with this name already exists" << std::endl;
            return false;
        }
        records.push_back(t);
        return true;
    }
};
#endif //SERIESAPPLICATION_POOL_H