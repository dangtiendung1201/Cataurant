#include "ultils.h"

int random(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}