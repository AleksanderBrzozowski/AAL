

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
void test3();

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList);

int main() {
    srand((unsigned int) time(nullptr));

    test3();
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

    Simulation::generateActions(skipList, 1000000);

    Simulation simulation(outTimerSkipList, actions, 1000);
    simulation.run();

    averageInfo(actions, timerSkipList);

    insertOrUpdateOut.close();
}

void test3() {
    SkipList skipList;
    Simulation::generateActions(skipList, 100000);
    TimerSkipList timerSkipList(skipList);

    Simulation simulation(skipList, std::cout);

    simulation.run();

    averageInfo(std::cout, timerSkipList);
}

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList) {
    os << "Average peek time: " << timerSkipList.getAveragePeekTime() << std::endl;
    os << "Average insert or update time: " << timerSkipList.getAverageInsertOrUpdateTime() << std::endl;
}

