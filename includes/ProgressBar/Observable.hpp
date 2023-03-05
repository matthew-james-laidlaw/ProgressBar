#pragma once

#include "Subscriber.hpp"

class Observable
{
public:
    virtual void Subscribe(Subscriber& subscriber) = 0;
};
