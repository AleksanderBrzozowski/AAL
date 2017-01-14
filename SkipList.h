//
// Created by Aleksander on 06.11.2016.
//

#ifndef AAL_SKIPLIST_H
#define AAL_SKIPLIST_H

#include <string>
#include <vector>
#include "BaseSkipList.h"

class SkipList : public BaseSkipList{
public:
    SkipList();
    SkipList(const float probability, const unsigned int maxLevel);
    ~SkipList();

    virtual void insertOrUpdate(int key, const std::string &newValue) override;
    virtual unsigned int size() const override;
    virtual bool isEmpty() const override;
    virtual std::string peek() override;
    virtual int keysOnSpecificLevel(unsigned int level) const override;
    virtual int getMinKey() const override;
    virtual int getMaxLevel() override;
    virtual int getMaxKey() const override;

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
    int minKey;
    int maxKey;

    unsigned int randomLevel() const;
    void checkIsNotEmpty() const;
};


#endif //AAL_SKIPLIST_H
