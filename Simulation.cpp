//
// Created by Aleksander on 07.01.2017.
//

#include <cstdlib>
#include <limits>
#include <iostream>
#include <stdexcept>
#include "Simulation.h"

Simulation::Simulation(BaseSkipList &skipList, std::ostream &os) : skipList(skipList), os(os), minAction(MIN_ACTION), maxAction(MAX_ACTION), range(maxAction - minAction) {}


Simulation::Simulation(BaseSkipList &skipList, std::ostream &os, int actionsToGenerate) : Simulation(skipList, os) {
    generateActions(skipList, actionsToGenerate);
}

void Simulation::run() {
    int actionCounter = 0;
    int addedActionCounter = 0;

    const int SHOW_LEVELS = 10000000;
    int i = SHOW_LEVELS;

    while (!skipList.isEmpty()) {
        if (i >= SHOW_LEVELS) {
            showLevelsStatistics();
            i = 0;
        }
        ++i;

        int minKey = skipList.getMinKey();
        std::string value = skipList.peek();

        for (char &c : value) {
            if(singleAction(minKey, c))
                ++addedActionCounter;
            ++actionCounter;
        }
    }

    os << "Done actions: " << actionCounter << ", added actions: " << addedActionCounter << std::endl;
}

bool Simulation::singleAction(int actualTime, const char &c) const {
    static int previousActualTime = 0;
    if(previousActualTime > actualTime)
        throw std::runtime_error("key is lower than actual time");
    previousActualTime = actualTime;

    if(c < minAction || c > maxAction)
        throw std::invalid_argument("Unknown action!");

    char sign = randomChar();
    bool addAction = sign >= minAction + 10;

    if (addAction) {
        int key = rand() % 10000 + actualTime;
        std::string action = std::string(1, c);
        skipList.insertOrUpdate(key, action);
    }
    return addAction;
}

void Simulation::showLevelsStatistics() const{
    int size = skipList.size();
    for (unsigned int i = 0; i < skipList.getMaxLevel(); ++i) {
        os << "level: " << i << ", elements: " << skipList.keysOnSpecificLevel(i)
                  << ", should have: " << size << std::endl;
        size /= 2;
    }
    os << std::endl;
}

char Simulation::randomChar() const {
    return randomChar(minAction, maxAction);
}

void Simulation::generateActions(BaseSkipList &skipList, int actionsToGenerate) {
    for (int i = 0; i < actionsToGenerate; ++i) {
        skipList.insertOrUpdate(i, std::string(1, randomChar(MIN_ACTION, MAX_ACTION)));
    }
}

char Simulation::randomChar(char min, char max) {
    return (char) (std::rand() % (max - min) + min);
}
