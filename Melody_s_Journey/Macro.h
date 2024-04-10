#pragma once
#include <iostream>

using namespace std;

typedef unsigned short usV; // unsigned short value
typedef short sV; // short value

#define S_APPEND(name) name + to_string(GetUniqueID())
#define SIZE(vector) static_cast<const int>(vector.size())

static int GetUniqueID()
{
	static int _id = 0;
	return _id++;
}
