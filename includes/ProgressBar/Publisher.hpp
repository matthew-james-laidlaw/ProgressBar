#pragma once

#include "Subscriber.hpp"

class Publisher
{
public:
    virtual void Subscribe(Subscriber& subscriber) = 0;
};
