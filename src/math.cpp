
#include "math.h"

constexpr float FLOAT_NORM = 1.0f / LONG_MAX;

// [0.0, 1.0)
float randomFloat()
{
    return FLOAT_NORM * random();
}

// from [min,max)
float randomBoundFloat(const float &min, const float &max)
{
    float t = randomFloat();
    return min + t * (max - min);
}