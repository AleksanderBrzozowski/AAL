//
// Created by Aleksander on 07.01.2017.
//

#include <chrono>
#include <iostream>
#include "TimerSkipList.h"

TimerSkipList::TimerSkipList(BaseSkipList &skipList) : skipList(skipList), lastInsertOrUpdateTime(0), lastPeekTime(0),
                                                       averageInsertOrUpdateTime(0), averagePeekTime(0) {}

std::string TimerSkipList::peek() {
    static bool isFirst = true;

    auto t1 = std::chrono::high_resolution_clock::now();
    std::string value = skipList.peek();
    auto t2 = std::chrono::high_resolution_clock::now();
    lastPeekTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    if (isFirst) {
        averagePeekTime = lastPeekTime;
        isFirst = false;
    }
    else
        averagePeekTime = (averagePeekTime + lastPeekTime) / 2;

    return value;
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
    }
    else
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

long TimerSkipList::getLastInsertOrUpdateTime() const {
    return lastInsertOrUpdateTime;
}

long TimerSkipList::getLastPeekTime() const {
    return lastPeekTime;
}

double TimerSkipList::getAverageInsertOrUpdateTime() const {
    return averageInsertOrUpdateTime;
}

double TimerSkipList::getAveragePeekTime() const {
    return averagePeekTime;
}
