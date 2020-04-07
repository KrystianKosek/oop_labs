#pragma once
#include "board.h"

class SapperBoard : public Board
{
public:
    SapperBoard(int y, int x, int mines);

    int get_geometry(int k) const override;
    double get_params(int k) override
    {
        return 0;
    }

private:
    int x;
    int y;
    int mines;
};