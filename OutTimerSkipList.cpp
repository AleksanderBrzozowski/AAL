//
// Created by Aleksander on 27.12.2016.
//

#include "OutTimerSkipList.h"
#include <chrono>

OutTimerSkipList::OutTimerSkipList(BaseTimerSkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut) : timerSkipList(
        skipList), frontOut(frontOut), insertOrUpdateOut(insertOrUpdateOut) {}

OutTimerSkipList::~OutTimerSkipList() {}

std::string OutTimerSkipList::peek() {
    std::string value = timerSkipList.peek();
    frontOut << getLastPeekTime() << std::endl;
    return value;
}

void OutTimerSkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    timerSkipList.insertOrUpdate(searchKey, newValue);
    insertOrUpdateOut << getLastInsertOrUpdateTime() << std::endl;
}

unsigned int OutTimerSkipList::size() const {
    return timerSkipList.size();
}

bool OutTimerSkipList::isEmpty() const {
    return timerSkipList.isEmpty();
}

int OutTimerSkipList::keysOnSpecificLevel(unsigned int level) const {
    return timerSkipList.keysOnSpecificLevel(level);
}

int OutTimerSkipList::getMinKey() const {
    return timerSkipList.getMinKey();
}

int OutTimerSkipList::getMaxLevel() {
    return timerSkipList.getMaxLevel();
}

long OutTimerSkipList::getLastInsertOrUpdateTime() const {
    return timerSkipList.getLastInsertOrUpdateTime();
}

long OutTimerSkipList::getLastPeekTime() const {
    return timerSkipList.getLastPeekTime();
}

double OutTimerSkipList::getAverageInsertOrUpdateTime() const {
    return timerSkipList.getAverageInsertOrUpdateTime();
}

double OutTimerSkipList::getAveragePeekTime() const {
    return timerSkipList.getAveragePeekTime();
}

int OutTimerSkipList::getMaxKey() const {
    return timerSkipList.getMaxKey();
}
