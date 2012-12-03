//
//  AmbientLight.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__AmbientLight__
#define __RayTracer__AmbientLight__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Light.h"

class AmbientLight: public Light
{
public:
	AmbientLight(const STColor3f& c);
    STColor3f sumComponenent(RayIntersection inter);

private:
};

#endif /* defined(__RayTracer__AmbientLight__) */
