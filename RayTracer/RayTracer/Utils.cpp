#include "Utils.h"

STVector3 Utils::reflectVector(STVector3 normal, STVector3 lightSource) {
    STVector3 x = STVector3::Dot(normal, lightSource) * normal;
    STVector3 y = lightSource - x;
    
    STVector3 R =  y -x;
    R.Normalize();
    return R;
}

