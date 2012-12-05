#ifndef __RayTracer__PointLight__
#define __RayTracer__PointLight__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Light.h"
#include "Utils.h"


class PointLight: public Light
{
public:
	PointLight(const STPoint3& loc,const STColor3f& c);
    STColor3f sumTerm(RayIntersection inter, Material *material, Ray *viewingRay);
    STVector3 *location;
    
private:
};

#endif /* defined(__RayTracer__PointLight__) */
