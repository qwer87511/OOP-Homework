#include "LuckyPoker.h"
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
using std::cout;
using std::shuffle;
using std::default_random_engine;

LuckyPoker::LuckyPoker()
{
    srand(time(NULL));
    _cards.resize(52);

    for (int i = 0; i < 52; ++i)
    {
        _cards[i] = (i / 4) + 1;
    }
}

void LuckyPoker::Shuffle()
{
    shuffle(_cards.begin(), _cards.end(), default_random_engine(time(NULL)));
}

void LuckyPoker::Deal()
{
    int i = 0;

    for (int j = 0; j < OPPONENT_CARD_NUM; ++j)
    {
        _opponentCard[j] = _cards[i];
        ++i;
    }

    for (int j = 0; j < PLAYER_CARD_NUM; ++j)
    {
        _playerCard[j] = _cards[i];
        ++i;
    }
}

int LuckyPoker::GetResult()
{
    int result = 0;

    for (int i = 0; i < OPPONENT_CARD_NUM; ++i)
    {
        /*cout << "opponent cards : " << _opponentCard[i] << '\n';
        cout << "player cards" << '\n';*/

        for (int j = 0; j < PLAYER_CARD_NUM; ++j)
        {

            /*cout << _playerCard[j] << '\n';*/

            if (_playerCard[j] > _opponentCard[i])
                result++;
        }
    }

    return result;
}