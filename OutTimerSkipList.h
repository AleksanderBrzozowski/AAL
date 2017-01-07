//
// Created by Aleksander on 27.12.2016.
//

#ifndef AAL_OUTTIMERSKIPLIST_H
#define AAL_OUTTIMERSKIPLIST_H


#include <fstream>
#include "BaseSkipList.h"
#include "SkipList.h"
#include "BaseTimerSkipList.h"

class OutTimerSkipList : public BaseTimerSkipList {
public:
    OutTimerSkipList(BaseTimerSkipList &skipList, std::ofstream &frontOut, std::ofstream &insertOrUpdateOut);
    virtual ~OutTimerSkipList();

    virtual std::string peek() override;
    virtual void insertOrUpdate(int searchKey, const std::string &newValue) override;
    virtual unsigned int size() const override;
    virtual bool isEmpty() const override;
    virtual int keysOnSpecificLevel(unsigned int level) const override;
    virtual int getMinKey() const override;
    virtual int getMaxLevel() override;
    virtual double getLastInsertOrUpdateTime() const override;
    virtual double getLastPeekTime() const override;
    virtual double getAverageInsertOrUpdateTime() const override;
    virtual double getAveragePeekTime() const override;

private:
    BaseTimerSkipList &timerSkipList;
    std::ofstream &frontOut;
    std::ofstream &insertOrUpdateOut;
};


#endif //AAL_OUTTIMERSKIPLIST_H
