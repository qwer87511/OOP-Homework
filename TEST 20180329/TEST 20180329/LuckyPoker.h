#pragma once
#include <vector>
using std::vector;

class LuckyPoker
{
    public:
        LuckyPoker();

        void Shuffle();
        void Deal();
        int GetResult();
    private:
        vector<int> _cards;

        static const int OPPONENT_CARD_NUM = 2;
        static const int PLAYER_CARD_NUM = 10;

        int _opponentCard[OPPONENT_CARD_NUM];
        int _playerCard[PLAYER_CARD_NUM];
};