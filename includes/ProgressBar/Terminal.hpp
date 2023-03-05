#pragma once

class ITerminal
{
public:
    virtual ~ITerminal() = default;
    virtual void MakeCursorInvisible() const = 0;
    virtual void MakeCursorVisible() const = 0;
    virtual void MoveCursor(unsigned int row, unsigned int column) const = 0;
};

class Terminal final : public ITerminal
{
    void MakeCursorInvisible() const;
    void MakeCursorVisible() const;
    void MoveCursor(unsigned int row, unsigned int column) const;
};
