#include <ProgressBar/View.hpp>

#include <algorithm>

using namespace ProgressBar;

View::View()
    : mBuffer { "[                ]" }
{}

void View::Update(double percentComplete)
{
    int shadedBarLength = (int)((double)BAR_LENGTH * (percentComplete / 100));
    mBuffer = "[                ]";
    std::fill(mBuffer.begin() + 1, mBuffer.begin() + shadedBarLength, '=');
}

std::string View::GetBuffer()
{
    return mBuffer;
}

void View::Draw()
{

}
