//
// blackcard.cpp -- CPE 212-01, Summer 2023 -- Project02 -- Classes

#include <iostream>
#include <cstdlib>
#include "blackcard.h"

BlackCard::BlackCard(int v) : Card(v)
// Creates a black card with value v and unknown suit
{
	SetColor("black");
}

string BlackCard::Description() const
// Outputs card characteristics - value and color as a string
{
	return Card::Description() + ", Color = Black";
}