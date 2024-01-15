//
// heart.cpp -- CPE 212-01, Summer 2023 -- Project02 -- Classes

#include <iostream>
#include <cstdlib>
#include "heart.h"

Heart::Heart(int v) : RedCard(v)
// Creates a red heart card with value v
{
	SetSuit('H');
}

string Heart::Description() const
// Outputs card characteristics - value, color, suit
{
	return RedCard::Description() + ", Suit = Heart";
}