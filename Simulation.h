//
// Created by Aleksander on 07.01.2017.
//

#ifndef AAL_SIMULATION_H
#define AAL_SIMULATION_H


#include <map>
#include "BaseSkipList.h"

class Simulation {
public:
    Simulation(BaseSkipList &skipList, std::ostream &os);
    Simulation(BaseSkipList &skipList, std::ostream &os, int actionsToGenerate);
    void run();

private:
    BaseSkipList &skipList;

    std::ostream &os;

    const char min;
    const char max;
    const int range;

    char randomChar() const;

    void showLevelsStatistics() const;

    bool singleAction(int actualTime, const char &c) const;
};


#endif //AAL_SIMULATION_H
