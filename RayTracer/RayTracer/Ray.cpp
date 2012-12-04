#include "Ray.h"

Ray::Ray(STVector3 s, STVector3 end )
{
    start = s;
    direction = end - s;
    direction.Normalize();
    minT = 1;
    maxT = 100000;
    
}

bool Ray::invalidT(float t) {
    return t < minT || t > maxT;
}

STVector3 *Ray::InterpolatedRay(float t) {
    if (invalidT(t)) {
        return NULL;
    }
    return new STVector3(start + t * direction);
}