#include <ProgressBar/Canvas.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>

class MockTerminal final : public ITerminal
{
public:
    MOCK_METHOD(void, MakeCursorInvisible, (), (const));
    MOCK_METHOD(void, MakeCursorVisible, (), (const));
    MOCK_METHOD(void, MoveCursor, (unsigned int row, unsigned int column), (const));
};

TEST(Canvas, Canvas)
{
    MockTerminal mockTerminal;

    EXPECT_CALL(mockTerminal, MakeCursorInvisible()).Times(1);
    EXPECT_CALL(mockTerminal, MakeCursorVisible()).Times(1);
    EXPECT_CALL(mockTerminal, MoveCursor(6, 0)).Times(1);

    std::string input = "Hello, World!";

    Canvas canvas(&mockTerminal);
    canvas.SetBuffer(input);

    std::stringstream output;
    canvas.Draw(output);

    EXPECT_EQ(output.str(), input);
}
