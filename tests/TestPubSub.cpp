#include <gtest/gtest.h>

#include <ProgressBar/Publisher.hpp>
#include <ProgressBar/Subscriber.hpp>
#include <ProgressBar/Terminal.hpp>

#include <string>
#include <thread>
#include <chrono>

class Progress final : public Publisher
{
public:
    void Subscribe(Subscriber& s)
    {
        for (int i = 0; i < 16; ++i)
        {
            s.Update();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

class View final : public Subscriber
{
public:

    View()
        : mBuffer { "[                ]" }
        , mCurrentItem { 1 }
        , mTerminal {}
    {}

    void Update()
    {
        mBuffer[mCurrentItem++] = '=';
        Draw();
    }

private:

    void Draw()
    {
        mTerminal.MakeCursorInvisible();
        mTerminal.MoveCursor(0, 0);
        std::cout << mBuffer;
        mTerminal.MakeCursorVisible();
    }

    std::string mBuffer;
    int mCurrentItem;
    Terminal mTerminal;

};

TEST(PubSub, PubSub)
{
    Progress progress;
    View view;

    progress.Subscribe(view);
}
