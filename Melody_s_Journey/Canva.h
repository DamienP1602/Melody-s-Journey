#pragma once
#include <iostream>
#include "Widget.h"
#include "IManagable.h"

using namespace std;

class Canva : public IManagable<string>
{
};

