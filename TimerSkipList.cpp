//
// Created by Aleksander on 07.01.2017.
//

#include <chrono>
#include <iostream>
#include "TimerSkipList.h"

TimerSkipList::TimerSkipList(BaseSkipList &skipList) : skipList(skipList), lastInsertOrUpdateTime(0),
                                                       averageInsertOrUpdateTime(0) {}

std::string TimerSkipList::peek() {
    return skipList.peek();
}

int TimerSkipList::getMinKey() const {
    return skipList.getMinKey();
}

void TimerSkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    static bool isFirst = true;

    auto t1 = std::chrono::high_resolution_clock::now();
    skipList.insertOrUpdate(searchKey, newValue);
    auto t2 = std::chrono::high_resolution_clock::now();
    lastInsertOrUpdateTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    if (isFirst) {
        averageInsertOrUpdateTime = lastInsertOrUpdateTime;
        isFirst = false;
    } else
        averageInsertOrUpdateTime = (averageInsertOrUpdateTime + lastInsertOrUpdateTime) / 2;
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

int TimerSkipList::getMaxLevel() {
    return skipList.getMaxLevel();
}

long long int TimerSkipList::getLastInsertOrUpdateTime() const {
    return lastInsertOrUpdateTime;
}

double TimerSkipList::getAverageInsertOrUpdateTime() const {
    return averageInsertOrUpdateTime;
}

int TimerSkipList::getMaxKey() const {
    return skipList.getMaxKey();
}
