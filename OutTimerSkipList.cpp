//
// Created by Aleksander on 27.12.2016.
//

#include "OutTimerSkipList.h"
#include <chrono>

OutTimerSkipList::OutTimerSkipList(BaseSkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut) : skipList(
        skipList), frontOut(frontOut), insertOrUpdateOut(insertOrUpdateOut) {}

OutTimerSkipList::~OutTimerSkipList() {}

std::string OutTimerSkipList::peek() {
    auto t1 = std::chrono::high_resolution_clock::now();

    std::string value = skipList.peek();

    auto t2 = std::chrono::high_resolution_clock::now();

    frontOut << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << std::endl;

    return value;
}

void OutTimerSkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    auto t1 = std::chrono::system_clock::now();

    skipList.insertOrUpdate(searchKey, newValue);

    auto t2 = std::chrono::system_clock::now();

    insertOrUpdateOut << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << std::endl;
}

unsigned int OutTimerSkipList::size() const {
    return skipList.size();
}

bool OutTimerSkipList::isEmpty() const {
    return skipList.isEmpty();
}

int OutTimerSkipList::keysOnSpecificLevel(unsigned int level) const {
    return skipList.keysOnSpecificLevel(level);
}

int OutTimerSkipList::getMinKey() const {
    return skipList.getMinKey();
}

int OutTimerSkipList::getMaxLevel() {
    return skipList.getMaxLevel();
}
