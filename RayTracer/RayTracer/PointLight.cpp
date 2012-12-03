//
//  PointLight.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "PointLight.h"
PointLight::PointLight(const STPoint3& loc,const STColor3f& c){
    color = new STColor3f(c);
    location = new STVector3(loc);
}