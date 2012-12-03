//
//  DirectionalLight.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "DirectionalLight.h"
DirectionalLight::DirectionalLight(const STVector3& dir,const STColor3f& c){
    color = new STColor3f(c);
    direction = new STVector3(dir);
}

STColor3f DirectionalLight::sumComponenent(RayIntersection inter){
    printf(" TODO implement directional light sum componenet\n");
    return STColor3f(1.0, 0.0, 0.0);
}
