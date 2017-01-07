

#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "TimerSkipList.h"

int main() {
    std::ofstream frontOut("frontOut.txt");
    std::ofstream insertOrUpdateOut("insertOrUpdate.txt");
    SkipList skipList;
    TimerSkipList timerSkipList(skipList, frontOut, insertOrUpdateOut);

    for (int i = 20000; i > 0; --i) {
        skipList.insertOrUpdate(i, "a");
    }

    int size = skipList.size();
    for (unsigned int i = 0; i < 15; ++i) {
        int valuesOnLevel = skipList.keysOnSpecificLevel(i);
        std::cout << valuesOnLevel << " percent: " << (float) valuesOnLevel / size * 100 << "%" << std::endl;

    }


    timerSkipList.insertOrUpdate(1205410, "a");
    timerSkipList.insertOrUpdate(12054504, "a");
    timerSkipList.insertOrUpdate(1534524504, "a");


    frontOut.close();
    insertOrUpdateOut.close();
    return 0;
}