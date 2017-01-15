

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include "OutTimerSkipList.h"
#include "Simulation.h"
#include "TimerSkipList.h"

void test1();
void test2();
void test3(int elements);

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList);

int main() {
    srand((unsigned int) time(nullptr));

    test3(1000000);
    return 0;
}

void test1() {
    SkipList skipList;

    Simulation::generateActions(skipList, 100000);

    Simulation simulation(skipList, std::cout);
    simulation.run();
}

void test2() {
    std::ofstream insertOrUpdateOut("insertOrUpdate.txt");
    std::ofstream actions("actions.txt");

    SkipList skipList;
    TimerSkipList timerSkipList(skipList);
    OutTimerSkipList outTimerSkipList(timerSkipList, insertOrUpdateOut);

    Simulation::generateActions(skipList, 100000);

    Simulation simulation(outTimerSkipList, actions, 1000);
    simulation.run();

    averageInfo(actions, timerSkipList);

    insertOrUpdateOut.close();
}

void test3(int elements) {
    SkipList skipList;
    Simulation::generateActions(skipList, elements);
    TimerSkipList timerSkipList(skipList);

    Simulation simulation(timerSkipList, std::cout);

    simulation.run();

    averageInfo(std::cout, timerSkipList);
}

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList) {
    os << "Average insert or update time: " << timerSkipList.getAverageInsertOrUpdateTime() << std::endl;
}

