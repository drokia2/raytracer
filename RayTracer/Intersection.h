

#ifndef __RayTracer__Intersection__
#define __RayTracer__Intersection__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Ray.h"


class Intersection
{
public:
	Intersection(float time, STVector3 intersect_pt, STVector3 normal, Ray vRay);
    
    STVector3 pt;
    STVector3 normal;
    Ray incomingRay;
protected:
    
    
};

#endif /* defined(__RayTracer__Intersection__) */
