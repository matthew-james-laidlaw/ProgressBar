#pragma once

#include "Terminal.hpp"

#include <ostream>
#include <string>

class Canvas
{
public:
    explicit Canvas(ITerminal* terminal);
    void SetBuffer(std::string const& buffer);
    void Draw(std::ostream& outstream);
private:
    std::string mBuffer;
    ITerminal* mTerminal;
};
