#pragma once
#include "game.h"
#include "matrix.h"
#include <vector>
#include <iostream>

class Sapper : public Game
{
public:
    Sapper() = default;
    virtual ~Sapper() = default;

    void new_board(const Board &board) override;
    void print_board() override;
    bool operator()(int x, int y) override;

private:
    int clearUncheckedFields;
    MyStuff::matrix matrixBoard;
};