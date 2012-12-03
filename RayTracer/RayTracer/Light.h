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

class Light
{
public:
	Light();
    
    STVector3 *SurfaceToLightDirection(STVector3 surfacePoint);
    
protected:
    STColor3f *color;
    
    
};

#endif /* defined(__RayTracer__Light__) */
