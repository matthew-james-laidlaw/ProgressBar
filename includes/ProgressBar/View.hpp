#pragma once

#include "Subscriber.hpp"

#include <string>

namespace ProgressBar
{

class View final : public Subscriber
{
public:
    static const int BAR_LENGTH = 16;
    View();
    void Update();
    std::string GetBuffer();
private:
    void Draw();
    std::string mBuffer;
};

};
