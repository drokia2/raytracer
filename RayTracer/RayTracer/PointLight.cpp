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

STColor3f PointLight::sumComponent(RayIntersection inter){
    printf(" TODO implement point light sum componenet\n");
//    float kd = 1.0; // what are these k's supposed to be
//    STColor3f sumComp = STColor3f(0.0, 0.0, 0.0);
//    sumComp = kd * *color * fmax(0.0, STVector3::Dot(inter.ptNormal, (inter.pt - *location)));
//    return sumComp;
    return STColor3f(1.0, 0.0, 0.0);

}