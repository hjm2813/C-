//
// diamond.cpp -- CPE 212-01, Summer 2023 -- Project02 -- Classes

#include <iostream>
#include <cstdlib>
#include "diamond.h"

Diamond::Diamond(int v) : RedCard(v)
// Creates a red diamond card with value v
{
	SetSuit('D');
}

string Diamond::Description() const
// Outputs card characteristics - value, color, suit
{
	return RedCard::Description() + ", Suit = Diamond";
}