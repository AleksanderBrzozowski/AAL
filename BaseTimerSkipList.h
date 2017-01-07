//
// Created by Aleksander on 07.01.2017.
//

#ifndef AAL_BASETIMERSKIPLIST_H
#define AAL_BASETIMERSKIPLIST_H

#include "BaseSkipList.h"

class BaseTimerSkipList : public BaseSkipList{
    virtual double getLastInsertOrUpdateTime() const = 0;
    virtual double getLastPeekTime() const = 0;
    virtual double getAverageInsertOrUpdateTime() const = 0;
    virtual double getAveragePeekTime() const = 0;
};

#endif //AAL_BASETIMERSKIPLIST_H
