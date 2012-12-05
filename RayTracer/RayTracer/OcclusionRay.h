//
//  OcclusionRay.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__OcclusionRay__
#define __RayTracer__OcclusionRay__

#include <iostream>
#include "Ray.h"

class OcclusionRay: public Ray
{
public:
	OcclusionRay(STVector3 start, STVector3 end, float ep );
    OcclusionRay TransformRay(STTransform4 transMatrix);

    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays
private:
    
    
};

#endif /* defined(__RayTracer__OcclusionRay__) */
