#include "Ray.h"

Ray::Ray(){
    
}

Ray::Ray(STVector3 s, STVector3 e )
{
    start = s;
    direction = e - s;
    end = e;
    direction.Normalize();
    minT = 1;
    maxT = 100000;
    
}

Ray Ray::TransformRay(STTransform4 transMatrix){
    STTransform4 invTransMatrix = transMatrix.Inverse();
    STVector3 startTransformed = STVector3(invTransMatrix * STPoint3(start));
    STVector3 endTransformed = STVector3(invTransMatrix * STPoint3(end));
    Ray newRay = Ray(startTransformed, endTransformed);
    return newRay;
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