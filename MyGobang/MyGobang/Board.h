#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#define SIZE 15
using namespace std;

typedef enum { empty, black, white } Chess;
class Board
{
    public:
        Board();
        void PutChess(int, int, Chess);
        void PrintBoard() const;
        void PrintChess(Chess) const;
    private:
        vector<vector<Chess> > _board;
};