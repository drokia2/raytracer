//
//  Light.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Light__
#define __RayTracer__Light__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Intersection.h"
#include "Material.h"
#include "Ray.h"
#include "SceneObject.h"

class Light
{
public:
	Light();
    
    STVector3 *SurfaceToLightDirection(STVector3 surfacePoint);
    virtual STColor3f sumTerm(Intersection inter, Material *material, Ray *viewingRay) = 0;
    
protected:
    STColor3f *color;
    
    
};

#endif /* defined(__RayTracer__Light__) */
