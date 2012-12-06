#ifndef __RayTracer__DirectionalLight__
#define __RayTracer__DirectionalLight__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Light.h"
#include "Utils.h"

class DirectionalLight: public Light
{
public:
	DirectionalLight(const STVector3& dir, const STColor3f& col);
    STColor3f sumTerm(Intersection inter, Material *material, Ray *viewingRay);
    STVector3 *direction;
    
private:

};
    
    
#endif /* defined(__RayTracer__DirectionalLight__) */
