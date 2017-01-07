

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include "OutTimerSkipList.h"
#include "Simulation.h"
#include "TimerSkipList.h"

void test2();

void test1();

int main() {
    srand((unsigned int) time(nullptr));

    test2();
    return 0;
}

void test1() {
    SkipList skipList;

    Simulation simulation(skipList, std::cout, 100000);
    simulation.run();
}

void test2() {
    std::ofstream frontOut("frontOut.txt");
    std::ofstream insertOrUpdateOut("insertOrUpdate.txt");
    std::ofstream actions("actions.txt");

    SkipList skipList;
    TimerSkipList timerSkipList(skipList);
    OutTimerSkipList outTimerSkipList(timerSkipList, frontOut, insertOrUpdateOut);

    Simulation::generateActions(skipList, 100000);

    Simulation simulation(outTimerSkipList, actions);
    simulation.run();

    actions << "Average peek time: " << timerSkipList.getAveragePeekTime() << std::endl;
    actions << "Average insert or update time: " << timerSkipList.getLastInsertOrUpdateTime() << std::endl;

    frontOut.close();
    insertOrUpdateOut.close();
}