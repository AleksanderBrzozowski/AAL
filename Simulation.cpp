//
// Created by Aleksander on 07.01.2017.
//

#include <cstdlib>
#include <limits>
#include <iostream>
#include "Simulation.h"

Simulation::Simulation(BaseSkipList &skipList, std::ostream &os) : skipList(skipList), os(os), min('a'), max('z'), range(max - min) {}


Simulation::Simulation(BaseSkipList &skipList, std::ostream &os, int actionsToGenerate) : Simulation(skipList, os) {
    for (int i = actionsToGenerate; i > 0; --i) {
        skipList.insertOrUpdate(i, std::string(1, randomChar()));
    }
}

void Simulation::run() {
    int actionCounter = 0;
    int addedActionCounter = 0;

    const int SHOW_LEVELS = 1000;
    int i = SHOW_LEVELS;

    while (!skipList.isEmpty()) {
        int minKey = skipList.getMinKey();
        std::string value = skipList.peek();

        if (i > SHOW_LEVELS) {
            showLevelsStatistics();
            i = 0;
        }
        ++i;

        for (char &c : value) {
            if(singleAction(minKey, c))
                ++addedActionCounter;
            ++actionCounter;
        }
    }

    os << "Done actions: " << actionCounter <<", added actions: " << addedActionCounter;
}

bool Simulation::singleAction(int actualTime, const char &c) const {
    static int previousActualTime = 0;
    if(previousActualTime > actualTime)
        throw std::runtime_error("key is lower than actual time");
    previousActualTime = actualTime;

    if(c < min || c > max)
        throw std::invalid_argument("Unknown action!");

    char sign = (char) rand() % (max - min) + min;
    bool addAction = sign >= min + 10;

    if (addAction) {
        int key = rand() % (actualTime + 10000 - actualTime) + actualTime;
        std::string action = std::string(1, c);
        skipList.insertOrUpdate(key, action);
    }
    return addAction;
}

void Simulation::showLevelsStatistics() const{
    int size = skipList.size();
    os << std::endl;
    for (unsigned int i = 0; i < skipList.getMaxLevel(); ++i) {
        os << "level: " << i << ", elements: " << skipList.keysOnSpecificLevel(i)
                  << ", should have: " << size << std::endl;
        size /= 2;
    }
    os << std::endl;
}

char Simulation::randomChar() const{
    return (char) (std::rand() % (max - min) + min);
}
