//
//  Material.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__Material__
#define __RayTracer__Material__

#include <iostream>
#include "stgl.h"
#include "st.h"

class Material
{
public:
	Material(const STColor3f& amb, const STColor3f& diff, const STColor3f& spec, const STColor3f& mirr, float shine);
    STColor3f amb, diff, spec, mirr;
    float shine;
    
private:
    
};
#endif /* defined(__RayTracer__Material__) */
