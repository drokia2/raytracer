//
//  Intersection.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Intersection__
#define __RayTracer__Intersection__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Shape.h"

class Intersection
{
public:
	Intersection(float time, STVector3 intersect_pt, Shape s);
    
    float t;
    STVector3 pt;
    STVector3 ptNormal;
protected:
    
    
};
#endif /* defined(__RayTracer__Intersection__) */
