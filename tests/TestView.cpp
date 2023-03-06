#include <ProgressBar/View.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ProgressBar::View;

TEST(View, NewViewHasEmptyBuffer)
{
    View view;
    EXPECT_EQ(view.GetBuffer(), "[                ]");
}

TEST(View, UpdateAddsCorrectNumberOfShadedBlocks)
{
    View view;
    std::string expectedBuffer = "[                ]";
    double percentComplete = 0.0;
    for (int i = 0; i < 16; ++i)
    {
        percentComplete += 6.25;
        view.Update();
        expectedBuffer[i + 1] = '=';
        EXPECT_EQ(view.GetBuffer(), expectedBuffer);
    }
}
