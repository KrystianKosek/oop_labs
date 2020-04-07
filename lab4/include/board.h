#pragma once

class Board
{
public:
    // funckja zwracajacy k-ty parametr planszy
    virtual int get_geometry(int k) const = 0;

    // funkcja zwracająca k-ty zmiennoprzecinkowy parametr planszy ( do dowolnej implementacji )
    virtual double get_params(int k) = 0;

    virtual ~Board() = default;
};