//
// Created by Aleksander on 07.01.2017.
//

#include <cstdlib>
#include <limits>
#include <iostream>
#include "Simulation.h"

Simulation::Simulation(BaseSkipList &skipList, std::ostream &os) : Simulation(skipList, os, ITERATIONS) {}

Simulation::Simulation(BaseSkipList &skipList, std::ostream &os, int iterations) : skipList(skipList), os(os),
                                                                                   minAction(MIN_ACTION),
                                                                                   maxAction(MAX_ACTION),
                                                                                   range(skipList.size()),
                                                                                   showLevels(iterations / 10),
                                                                                   iterations(iterations) {}

void Simulation::run() {
    int iterationsCounter = 0;
    int addedElementsCounter = 0;
    int startElements = skipList.size();

    int i = 0;
    while (!skipList.isEmpty() && iterationsCounter < iterations) {
        std::string value = skipList.peek();

        for (char &c : value) {
            if (i >= showLevels) {
                showStatistics();
                i = 0;
                std::cout << "Done: " << iterationsCounter * 100 / iterations << "%" << std::endl;
            }
            ++i;

            if (iterationsCounter >= iterations)
                break;

            int min = skipList.getMinKey() + range / 3;
            int max = skipList.getMaxKey() + range / 3;

            int key = randomInt(min, max);
            std::string action = std::string(1, randomChar());
            skipList.insertOrUpdate(key, action);

            ++iterationsCounter;
            ++addedElementsCounter;
        }
    }
    showStatistics();
    std::cout << "Done: " << iterationsCounter * 100 / iterations << "%" << std::endl;
    os << "Done actions: " << iterationsCounter << ", added actions: " << addedElementsCounter
       << ", initial capacity: " << startElements << std::endl;
}

void Simulation::showStatistics() const {
    int size = skipList.size();
    for (unsigned int i = 0; i < skipList.getMaxLevel(); ++i) {
        os << "level: " << i << ", elements: " << skipList.keysOnSpecificLevel(i)
           << ", should have: " << size << std::endl;
        size /= 2;
    }
    int maxKey = skipList.getMaxKey();
    int minKey = skipList.getMinKey();
    os << "maxKey: " << maxKey << ", minKey: " << minKey << std::endl;
    os << "diff between keys: " << maxKey - minKey << std::endl;
}

char Simulation::randomChar() const {
    return (char) randomInt(minAction, maxAction);
}

void Simulation::generateActions(BaseSkipList &skipList, int actionsToGenerate) {
    for (int key = std::numeric_limits<int>::min(), i = actionsToGenerate; i > 0; --i) {
        skipList.insertOrUpdate(++key, std::string(1, (char) randomInt(MIN_ACTION, MAX_ACTION)));
    }
}

int Simulation::randomInt(int min, int max) {
    return (std::rand() % (max - min) + min);
}
