#include "Board.h"

Board::Board()
    : _board(SIZE, vector<Chess>(SIZE, Chess::white))
{ }
void Board::PutChess(int x, int y, Chess chess)
{
    this->_board[x][y] = chess;
}
void Board::PrintChess(Chess chess) const
{
    switch (chess)
    {
        case black:
            cout << "¡´";
            break;

        case white:
            cout << "¡³";

        case Chess::empty:
            cout << "  ";
    }
}
void Board::PrintBoard() const
{
    for (int i = 0; i < SIZE; ++i)
    {
        cout << setw(4) << i;
    }

    cout << endl;

    for (int i = 0; i < SIZE; ++i)
    {
        cout << setw(2) << i;

        for (int j = 0; j < SIZE; ++j)
            PrintChess(this->_board[i][j]);

        cout << endl;
    }

    cout << endl;
}
