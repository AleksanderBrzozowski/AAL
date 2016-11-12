//
// Created by Aleksander on 06.11.2016.
//

#ifndef AAL_SKIPLIST_H
#define AAL_SKIPLIST_H

#include <string>
#include <vector>

class SkipList {
public:
    SkipList();

    SkipList(const float probability, const unsigned int maxLevel);

    ~SkipList();

    std::string* find(int searchKey) const;

    void insert(int searchKey, const std::string &newValue);

    void print() const;

    std::vector<int> getKeysOnSpecificLevel(unsigned int level) const;

    bool erase(int searchKey);
private:
    static constexpr auto DEFAULT_MAX_LEVEL = 16;
    static constexpr auto DEFAULT_PROBABILITY = 0.5F;
    static constexpr auto HEAD_VALUE = "head";
    static constexpr auto TAIL_VALUE = "NIL";

    struct Node{
        int key;
        std::string value;
        std::vector<Node*> forward;

        Node(int key, const std::string &value, unsigned int level);
    };
    Node* head;
    Node* tail;
    const float probability;
    const unsigned int maxLevel;

    unsigned int randomLevel();
};


#endif //AAL_SKIPLIST_H
