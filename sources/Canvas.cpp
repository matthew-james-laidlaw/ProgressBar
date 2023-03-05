#include <ProgressBar/Canvas.hpp>
#include <ProgressBar/Terminal.hpp>

#include <iostream>
#include <memory>

Canvas::Canvas(ITerminal* terminal)
    : mTerminal { terminal }
{}

void Canvas::SetBuffer(std::string const& buffer)
{
    mBuffer = buffer;
}

void Canvas::Draw(std::ostream& outstream)
{
    mTerminal->MakeCursorInvisible();
    outstream << mBuffer;
    mTerminal->MakeCursorVisible();
    mTerminal->MoveCursor(6, 0);
}
