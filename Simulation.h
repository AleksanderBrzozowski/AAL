//
// Created by Aleksander on 07.01.2017.
//

#ifndef AAL_SIMULATION_H
#define AAL_SIMULATION_H

#include "BaseSkipList.h"

class Simulation {
public:
    Simulation(BaseSkipList &skipList, std::ostream &os);
    Simulation(BaseSkipList &skipList, std::ostream &os, int actionsToGenerate);
    void run();

    static void generateActions(BaseSkipList &skipList, int actionsToGenerate);
    static char constexpr MIN_ACTION = 'a';
    static char constexpr MAX_ACTION = 'z';
private:
    BaseSkipList &skipList;

    std::ostream &os;

    const char minAction;
    const char maxAction;
    const int range;

    char randomChar() const;
    static char randomChar(char min, char max);
    void showLevelsStatistics() const;
    bool singleAction(int actualTime, const char &c) const;
};
#endif //AAL_SIMULATION_H
