#include <ProgressBar/View.hpp>

#include <algorithm>

using ProgressBar::View;

View::View()
    : mBuffer { "[                ]" }
{}

void View::Update()
{
    
}

std::string View::GetBuffer()
{
    return mBuffer;
}

void View::Draw()
{

}
