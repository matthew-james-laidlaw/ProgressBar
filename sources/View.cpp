#include <ProgressBar/Terminal.hpp>
#include <ProgressBar/View.hpp>
#include <algorithm>
#include <iostream>

using ProgressBar::View;
using std::cout, std::endl, std::fill;

View::View()
    : mBuffer { "[                ]" }
    , mCurrentItem { 0 }
{}

void View::Update()
{
    mBuffer[(mCurrentItem++) + 1] = '=';
    Draw();
}

std::string View::GetBuffer()
{
    return mBuffer;
}

void View::Draw()
{
    mTerminal.MakeCursorInvisible();
    mTerminal.MoveCursor(2, 0);
    cout << mBuffer << endl;
    mTerminal.MakeCursorVisible();
}
