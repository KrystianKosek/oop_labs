#include "sapper_board.h"

SapperBoard::SapperBoard(int y, int x, int mines)
{
    this->x = x;
    this->y = y;
    this->mines = mines;
    if (x < 5 && y < 5)
    {
        this->x = this->y = 5;
    }
    else if (x < 5)
    {
        this->x = 5;
    }
    else if (y < 5)
    {
        this->y = 5;
    }

    if (x > 20 && y > 20)
    {
        this->x = this->y = 20;
    }
    else if (x > 20)
    {
        this->x = 20;
    }
    else if (y > 20)
    {
        this->y = 20;
    }

    if (mines < 2)
    {
        this->mines = 2;
    }
    else if (mines > ((this->x * this->y) / 3))
    {
        this->mines = ((this->x * this->y) / 3);
    }
}

int SapperBoard::get_geometry(int k) const
{
    switch (k)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return mines;
    default:
        return 0;
    }
}