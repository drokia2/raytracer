//
//  Light.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Light.h"

Light::Light(){
    
}

STColor3f Light::sumComponenent(RayIntersection inter){
    printf(" TODO implement  light sum componenet in child class\n");
    return STColor3f(1.0, 0.0, 0.0);
}

STVector3 *Light::SurfaceToLightDirection(STVector3 surfacePoint) {
    printf("TODO implement SurceToLightDirection\n");
    return NULL;
}
