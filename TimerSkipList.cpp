//
// Created by Aleksander on 27.12.2016.
//

#include "TimerSkipList.h"
#include <chrono>

TimerSkipList::TimerSkipList(SkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut) : skipList(
        skipList), frontOut(frontOut), insertOrUpdateOut(insertOrUpdateOut) {}

TimerSkipList::~TimerSkipList() {}

std::string TimerSkipList::front() {
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    std::string value = skipList.front();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    frontOut << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

    return value;
}

void TimerSkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    auto before = std::chrono::system_clock::now();

    skipList.insertOrUpdate(searchKey, newValue);

    auto after = std::chrono::system_clock::now();

    insertOrUpdateOut << std::chrono::duration_cast<std::chrono::nanoseconds>(before - after).count() << std::endl;
}

unsigned int TimerSkipList::size() const {
    return skipList.size();
}

bool TimerSkipList::isEmpty() const {
    return skipList.isEmpty();
}
