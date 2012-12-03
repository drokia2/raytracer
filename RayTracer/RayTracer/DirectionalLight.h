//
//  DirectionalLight.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__DirectionalLight__
#define __RayTracer__DirectionalLight__

#include <iostream>
#include "stgl.h"
#include "st.h"
#include "Light.h"

class DirectionalLight: public Light
{
public:
	DirectionalLight(const STVector3& dir, const STColor3f& col);
    
private:
    STVector3 *direction;
};
    
    
#endif /* defined(__RayTracer__DirectionalLight__) */
