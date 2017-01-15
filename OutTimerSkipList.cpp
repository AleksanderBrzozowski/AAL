//
// Created by Aleksander on 27.12.2016.
//

#include "OutTimerSkipList.h"
#include <chrono>

OutTimerSkipList::OutTimerSkipList(BaseTimerSkipList &skipList, std::ofstream &insertOrUpdateOut) :
        timerSkipList(skipList), insertOrUpdateOut(insertOrUpdateOut) {}

OutTimerSkipList::~OutTimerSkipList() {}

std::string OutTimerSkipList::peek() {
    return timerSkipList.peek();
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

long long int OutTimerSkipList::getLastInsertOrUpdateTime() const {
    return timerSkipList.getLastInsertOrUpdateTime();
}

double OutTimerSkipList::getAverageInsertOrUpdateTime() const {
    return timerSkipList.getAverageInsertOrUpdateTime();
}

int OutTimerSkipList::getMaxKey() const {
    return timerSkipList.getMaxKey();
}
