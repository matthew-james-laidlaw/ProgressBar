#include <ProgressBar/Terminal.hpp>

#include <iostream>

void Terminal::MakeCursorInvisible() const
{
    std::cout << "\x1B[?25l";
}

void Terminal::MakeCursorVisible() const
{
    std::cout << "\x1B[?25h";
}

void Terminal::MoveCursor(unsigned int row, unsigned int column) const
{
    std::cout << "\x1B[" << std::to_string(row) << ";" << std::to_string(column) << "H";
}
