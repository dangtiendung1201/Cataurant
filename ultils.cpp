#include "ultils.h"

int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}