//
//  AmbientLight.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "AmbientLight.h"

AmbientLight::AmbientLight(const STColor3f& c){
    color = new STColor3f(c);
}

STColor3f AmbientLight::sumComponenent(RayIntersection inter){
    printf(" TODO implement ambient light sum componenet\n");
//    float ka = 1.0; // dont know what k is 
//    STColor3f sumComp = STColor3f(0.0, 0.0, 0.0);
//    sumComp = ka * *color;
//    return sumComp;
    return STColor3f(1.0, 0.0, 0.0);
}