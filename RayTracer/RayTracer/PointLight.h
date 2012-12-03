//
//  PointLight.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__PointLight__
#define __RayTracer__PointLight__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Light.h"

class PointLight: public Light
{
public:
	PointLight(const STPoint3& loc,const STColor3f& c);
    
private:
    STVector3 *location;
};

#endif /* defined(__RayTracer__PointLight__) */
