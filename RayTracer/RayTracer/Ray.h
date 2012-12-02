//
//  Ray.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Ray__
#define __RayTracer__Ray__

#include <iostream>

#include "st.h"

class Ray
{
public:
	Ray(STVector3 start, STVector3 end );
    
    STVector3 InterpolatedRay(float t);
    
    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays    
private:
    STVector3 startPt;
    STVector3 endPt;
    
    bool invalidT(float t);
    
    
    float minT;
    float maxT;
    
    
};


#endif /* defined(__RayTracer__Ray__) */
