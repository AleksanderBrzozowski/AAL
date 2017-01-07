//
// Created by Aleksander on 06.11.2016.
//

#include <limits>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "SkipList.h"

SkipList::Node::Node(int key, const std::string &value, unsigned int level) :
        key(key), value(value), forward(level, nullptr){}

SkipList::SkipList() : SkipList(DEFAULT_PROBABILITY, DEFAULT_MAX_LEVEL){}

SkipList::SkipList(const float probability, const unsigned int maxLevel) :
        probability(probability), maxLevel(maxLevel) {
    head = new Node(std::numeric_limits<int>::min(), HEAD_VALUE, maxLevel);
    tail = new Node(std::numeric_limits<int>::max(), TAIL_VALUE, maxLevel);
    std::fill(head->forward.begin(), head->forward.end(), tail);
}

SkipList::~SkipList() {
    auto node = head;
    // forward[0] is the lowest level which contains all elements in list
    while (node->forward[0]) {
        auto temp = node;
        node = node->forward[0];
        delete temp;
    }
    // delete tail
    delete node;
}


void SkipList::insertOrUpdate(int searchKey, const std::string &newValue) {
    std::vector<Node *> update(maxLevel, nullptr);
    auto x = head;
    for (int i = maxLevel - 1 ; i >= 0; i--) {
        //find last node which key is higher than searchKey
        while (x->forward[i]->key < searchKey)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[0];
    //update value if key exists
    if(x->key == searchKey)
        x->value += newValue;

    else{
        auto lvl = randomLevel();
        x = new Node(searchKey, newValue, lvl);
        for (auto i = 0; i < lvl; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

unsigned int SkipList::randomLevel()  {
    unsigned int level = 1;
    while ((float)std::rand() / RAND_MAX < probability && level < maxLevel)
        ++level;
    return level;
}

unsigned int SkipList::size() const {
    auto node = head->forward[0];
    unsigned int counter = 0;
    while (node != tail) {
        ++counter;
        node = node->forward[0];
    }
    return counter;
}

bool SkipList::isEmpty() const {
    return head->forward[0] == tail;
}

std::string SkipList::front() {
    if(isEmpty())
        throw std::runtime_error("No elements in skip list");

    auto node = head->forward[0];
    std::string value = node->value;
    for (unsigned int i = 0; i < node->forward.size(); ++i)
        head->forward[i] = node->forward[i];
    delete node;
    return value;
}

int SkipList::keysOnSpecificLevel(unsigned int level) const {
    if(level < maxLevel){
        int counter = 0;
        auto node = head->forward[level];
        while(node != tail) {
            ++counter;
            node = node->forward[level];
        }
        return counter;
    }
    return 0;
}

