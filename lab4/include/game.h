#pragma once
#include <string>
#include "board.h"

using namespace std;

class Game
{
public:
    // tworzymy nowego gracza o podanej nazwie
    void new_player(string player_name)
    {
        player = player_name;
    }
    // tworzymy nową plansze o parametrach zapisanych w obiekcie Board
    virtual void new_board(const Board &) = 0;

    // rysuje plansze
    virtual void print_board() = 0;

    // przeładowany operator () okrywający podane pole
    virtual bool operator()(int x, int y) = 0;

    // destruktor
    virtual ~Game() = default;

private:
    string player;
};