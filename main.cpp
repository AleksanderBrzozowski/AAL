

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include "OutTimerSkipList.h"
#include "Simulation.h"
#include "TimerSkipList.h"

void extendedSimulation(int elements);

void outputExtendedSimulation(int elements, std::ofstream &os);

unsigned int calculateSkipListLevel(int elements);

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList);

void simpleSimulation(int elements);

void simulate(int elements, BaseSkipList &skipList);

int main(int argc, char *argv[]) {
    srand((unsigned int) time(nullptr));

    const int ELEMENTS_SIZE = 1000;

    if (argc < 2)
        simpleSimulation(ELEMENTS_SIZE);
    else {
        std::unordered_map<std::string, std::string> options;
        bool isOption = true;
        std::string option;
        for (int i = 1; i < argc; ++i) {
            std::string value(argv[i]);
            if (isOption) {
                if (value == "-t") {
                    options.insert(std::pair<std::string, std::string>("-t", ""));
                    continue;
                }
                option = value;
            } else
                options.insert(std::pair<std::string, std::string>(option, value));

            isOption = !isOption;
        }

        int elements = options.count("-e") ? std::stoi((*options.find("-e")).second) : ELEMENTS_SIZE;
        bool isExtended = options.count("-t") > 1;

        if (options.count("-o")) {
            std::ofstream os((*options.find("-o")).second);
            outputExtendedSimulation(elements, os);
            os.close();
        } else {
            isExtended ? simpleSimulation(elements) : extendedSimulation(elements);
        }
    }

    return 0;
}

void simpleSimulation(int elements) {
    SkipList skipList(0.5F, calculateSkipListLevel(elements));
    Simulation::generateActions(skipList, elements);

    simulate(elements, skipList);
}

void extendedSimulation(int elements) {
    SkipList skipList(0.5F, calculateSkipListLevel(elements));
    TimerSkipList timerSkipList(skipList);

    simulate(elements, timerSkipList);

    averageInfo(std::cout, timerSkipList);
}

void outputExtendedSimulation(int elements, std::ofstream &os) {
    SkipList skipList(0.5F, calculateSkipListLevel(elements));
    TimerSkipList timerSkipList(skipList);
    OutTimerSkipList outTimerSkipList(timerSkipList, os);

    simulate(elements, outTimerSkipList);
    averageInfo(std::cout, timerSkipList);
}

void simulate(int elements, BaseSkipList &skipList) {
    Simulation::generateActions(skipList, elements);
    Simulation simulation(skipList, std::cout);
    simulation.run();
}

void averageInfo(std::ostream &os, const TimerSkipList &timerSkipList) {
    os << "Average insert or update time: " << timerSkipList.getAverageInsertOrUpdateTime() << std::endl;
}

unsigned int calculateSkipListLevel(int elements) {
    unsigned int level = 1;
    unsigned int i = 1;
    while (i / elements < 1) {
        i *= 2;
        ++level;
    }
    return level;
}

