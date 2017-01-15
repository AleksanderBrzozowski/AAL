//
// Created by Aleksander on 07.01.2017.
//

#ifndef AAL_SIMULATION_H
#define AAL_SIMULATION_H

#include "BaseSkipList.h"

class Simulation {
public:
    Simulation(BaseSkipList &skipList, std::ostream &os);
    Simulation(BaseSkipList &skipList, std::ostream &os, int iterations);

    void run();

    static void generateActions(BaseSkipList &skipList, int actionsToGenerate);
    static char constexpr MIN_ACTION = 'a';
    static char constexpr MAX_ACTION = 'z';
    static int constexpr ITERATIONS = 10000;
private:
    BaseSkipList &skipList;

    std::ostream &os;

    const char minAction;
    const char maxAction;
    const int range;
    const int showLevels;
    const int iterations;

    char randomChar() const;
    static int randomInt(int min, int max);
    void showStatistics() const;
};
#endif //AAL_SIMULATION_H
