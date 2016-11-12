//
// Created by Aleksander on 06.11.2016.
//

#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
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

std::string* SkipList::find(int searchKey) const {
    auto x = head;

    //start from the top of head nodes
    for (auto i = maxLevel - 1; i > 0; i--) {
        //find last node which key is higher than searchKey
        while(x->forward[i]->key < searchKey)
            x = x->forward[i];
    }
    //next node after last node with lower key than searchKey
    //is our searchKey or it is higher than searchKey
    x = x->forward[0];
    return x->key == searchKey ? &(x->value) : nullptr;
}


void SkipList::insert(int searchKey, const std::string &newValue) {
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
        x->value = newValue;

    else{
        auto lvl = randomLevel();
        x = new Node(searchKey, newValue, lvl);
        for (auto i = 0; i < lvl; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

bool SkipList::erase(int searchKey) {
    std::vector<Node *> update(maxLevel, nullptr);
    auto x = head;
    for (int i = maxLevel - 1 ; i >= 0; i--) {
        //find last node which key is higher than searchKey
        while (x->forward[i]->key < searchKey)
            x = x->forward[i];
        update[i] = x;
    }

    x = x->forward[0];

    if (x->key == searchKey) {
        for (auto i = 0; i < x->forward.size() ; i++)
            update[i]->forward[i] = x->forward[i];
        delete x;
        return true;
    }
    return false;
}

unsigned int SkipList::randomLevel()  {
    unsigned int level = 1;
    while ((float)std::rand() / RAND_MAX < probability && level < maxLevel)
        ++level;
    return level;
}

void SkipList::print() const {
    auto node = head;
    while (node != tail) {
        auto first = node->forward[0];
        for(auto nestedNode : node->forward) {
            if(nestedNode == first)
                std::cout << nestedNode->key << " ";
        }
        std::cout << std::endl;
        node = node->forward[0];
    }
}

std::vector<int> SkipList::getKeysOnSpecificLevel(unsigned int level) const {
    std::vector<int> keys;
    if(level < maxLevel) {
        auto node = head;
        while (node != tail) {
            keys.push_back(node->key);
            node = node->forward[level];
        }
    }
    return keys;
}

