#include "sapper.h"

void Sapper::new_board(const Board &board)
{
    matrixBoard = MyStuff::matrix(board.get_geometry(0), board.get_geometry(1));
    for (int i = 0; i < matrixBoard.get_x(); i++)
    {
        for (int j = 0; j < matrixBoard.get_y(); j++)
        {
            matrixBoard[j][i] = -100;
        }
    }
    clearUncheckedFields = matrixBoard.get_x() * matrixBoard.get_y() - board.get_geometry(2);

    for (int i = 0; i < board.get_geometry(2); i++)
    {
        int pos_x = rand() % matrixBoard.get_x();
        int pos_y = rand() % matrixBoard.get_y();
        if (matrixBoard[pos_y][pos_x] == -100)
        {
            matrixBoard[pos_y][pos_x] = -200;
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < matrixBoard.get_x(); i++)
    {
        for (int j = 0; j < matrixBoard.get_y(); j++)
        {
            if (matrixBoard[j][i] == -200)
            {
                continue;
            }
            vector<int> rows;
            if (i == 0)
            {
                rows.push_back(i);
                rows.push_back(i + 1);
            }
            else if (i == matrixBoard.get_x() - 1)
            {
                rows.push_back(i);
                rows.push_back(i - 1);
            }
            else
            {
                rows.push_back(i - 1);
                rows.push_back(i);
                rows.push_back(i + 1);
            }
            vector<int> columns;
            if (j == 0)
            {
                columns.push_back(j);
                columns.push_back(j + 1);
            }
            else if (j == matrixBoard.get_y() - 1)
            {
                columns.push_back(j);
                columns.push_back(j - 1);
            }
            else
            {
                columns.push_back(j - 1);
                columns.push_back(j);
                columns.push_back(j + 1);
            }

            for (auto &row : rows)
            {
                for (auto &column : columns)
                {
                    if (row != i || column != j)
                    {
                        if (matrixBoard[column][row] == -200)
                            matrixBoard[j][i] += 1;
                    }
                }
            }
            rows.clear();
            columns.clear();
        }
    }
}

void Sapper::print_board()
{
    for (int i = 0; i < matrixBoard.get_y(); i++)
    {
        for (int j = 0; j < matrixBoard.get_x(); j++)
        {
            if (matrixBoard[i][j] < 0)
            {
                cout << " * ";
            }
            else
            {
                cout << " " << matrixBoard[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Sapper::operator()(int x, int y)
{
    if (x >= matrixBoard.get_x() || y >= matrixBoard.get_y())
    {
        cout << "out of range...\n";
        return true;
    }

    if (matrixBoard[y][x] == -200)
    {
        cout << "\n!!!   BOOOOM    !!!\n\tGame Over \n";
        return false;
    }
    else if (matrixBoard[y][x] < 0)
    {
        matrixBoard[y][x] += 100;
        clearUncheckedFields--;
        if (clearUncheckedFields == 0)
        {
            cout << "Good job! You survived!\n";
            return false;
        }

        return true;
    }
    else
    {
        return true;
    }
}