//
// Created by Aleksander on 27.12.2016.
//

#include "TimerSkipList.h"
#include <chrono>

TimerSkipList::TimerSkipList(BaseSkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut) : skipList(
        skipList), frontOut(frontOut), insertOrUpdateOut(insertOrUpdateOut) {}

TimerSkipList::~TimerSkipList() {}

std::string TimerSkipList::peek() {
    auto t1 = std::chrono::high_resolution_clock::now();

    std::string value = skipList.peek();

    auto t2 = std::chrono::high_resolution_clock::now();

    frontOut << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << std::endl;

    return value;
}

void TimerSkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    auto t1 = std::chrono::system_clock::now();

    skipList.insertOrUpdate(searchKey, newValue);

    auto t2 = std::chrono::system_clock::now();

    insertOrUpdateOut << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << std::endl;
}

unsigned int TimerSkipList::size() const {
    return skipList.size();
}

bool TimerSkipList::isEmpty() const {
    return skipList.isEmpty();
}

int TimerSkipList::keysOnSpecificLevel(unsigned int level) const {
    return skipList.keysOnSpecificLevel(level);
}

int TimerSkipList::getMinKey() const {
    return skipList.getMinKey();
}

int TimerSkipList::getMaxLevel() {
    return skipList.getMaxLevel();
}
