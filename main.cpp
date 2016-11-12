#include <iostream>
#include <sstream>
#include <map>
#include "SkipList.h"


int main() {
    SkipList skipList;
    const unsigned long SIZE = 10000000L;
    for (auto i = 0; i < SIZE; i++) {
        std::ostringstream os;
        os << i;
        skipList.insert(i, os.str());
    }
    for (unsigned int i = 0; i <= 15; i++)
        std::cout << skipList.getKeysOnSpecificLevel(i).size() << std::endl;
    return 0;
}