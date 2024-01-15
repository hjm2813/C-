//
// redcard.cpp -- CPE 212-01, Summer 2023 -- Project02 -- Classes

#include <iostream>
#include <cstdlib>
#include "redcard.h"

RedCard::RedCard(int v) : Card(v)
// Creates a red card with value v and unknown suit
{
	SetColor("red");
}

string RedCard::Description() const
// Outputs card characteristics - value and color as a string
{
	return Card::Description() + ", Color = Red";
}