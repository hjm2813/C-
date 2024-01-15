//
// spade.cpp -- CPE 212-01, Summer 2023 -- Project02 -- Classes

#include <iostream>
#include <cstdlib>
#include "spade.h"

Spade::Spade(int v) : BlackCard(v)
// Creates a black card with value v and unknown suit
{
	SetSuit('C');
}

string Spade::Description() const
// Outputs card characteristics - value and color as a string
{
	return BlackCard::Description() + ", Suit = Spade";
}