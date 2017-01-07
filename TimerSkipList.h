//
// Created by Aleksander on 27.12.2016.
//

#ifndef AAL_TIMERSKIPLIST_H
#define AAL_TIMERSKIPLIST_H


#include <fstream>
#include "BaseSkipList.h"
#include "SkipList.h"

class TimerSkipList : public BaseSkipList {
public:
    TimerSkipList(SkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut);
    virtual ~TimerSkipList();

    virtual std::string front() override;
    virtual void insertOrUpdate(int searchKey, const std::string &newValue) override;
    virtual unsigned int size() const override;
    virtual bool isEmpty() const override;
    virtual int keysOnSpecificLevel(unsigned int level) const override;

private:
    SkipList &skipList;
    std::ofstream &frontOut;
    std::ofstream &insertOrUpdateOut;
};


#endif //AAL_TIMERSKIPLIST_H
