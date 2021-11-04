#pragma once
#include "include.h"

enum card_suit
{
    spades, clubs, tambourines, hearts
};

enum card_dignity {
    ace1 = 1,
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    king = 10,
    queen = 10,
    jack = 10 ,
    ace11 = 11
};

class Card
{
private:
    card_suit suit;
    card_dignity dignity;
    bool side;

public:
    bool Flip()
    {
        return side ? false : true;
    }
    card_dignity GetValue()
    {
        return dignity;
    }
    Card(card_dignity cDignity):dignity(cDignity)
    {}
};

void bj()
{
    Card s (queen);
    std::cout << s.GetValue();
}
