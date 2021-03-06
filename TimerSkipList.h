//
// Created by Aleksander on 07.01.2017.
//

#ifndef AAL_TIMERSKIPLIST_H
#define AAL_TIMERSKIPLIST_H


#include "BaseTimerSkipList.h"

class TimerSkipList : public BaseTimerSkipList{
public:
    TimerSkipList(BaseSkipList &skipList);

    virtual std::string peek() override;
    virtual int getMinKey() const override;
    virtual void insertOrUpdate(int searchKey, const std::string &newValue) override;
    virtual unsigned int size() const override;
    virtual bool isEmpty() const override;
    virtual int keysOnSpecificLevel(unsigned int level) const override;
    virtual int getMaxLevel() override;

    virtual long long int getLastInsertOrUpdateTime() const override;

    virtual double getAverageInsertOrUpdateTime() const override;

    virtual int getMaxKey() const override;

private:
    BaseSkipList &skipList;

    long long int lastInsertOrUpdateTime;
    double averageInsertOrUpdateTime;
};


#endif //AAL_TIMERSKIPLIST_H
