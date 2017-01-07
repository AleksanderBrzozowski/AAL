//
// Created by Aleksander on 27.12.2016.
//

#ifndef AAL_BASESKIPLIST_H
#define AAL_BASESKIPLIST_H

#include <string>

class BaseSkipList{
public:
    virtual std::string peek() = 0;
    virtual int getMinKey() const = 0;
    virtual void insertOrUpdate(int searchKey, const std::string &newValue) = 0;
    virtual unsigned int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int keysOnSpecificLevel(unsigned int level) const = 0;
    virtual int getMaxLevel() = 0;
};

#endif //AAL_BASESKIPLIST_H
