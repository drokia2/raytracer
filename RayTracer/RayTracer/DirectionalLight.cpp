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

STColor3f DirectionalLight::sumComponent(RayIntersection inter){
    printf(" TODO implement directional light sum componenet\n");
    
//    float ks = 1.0;
//    STVector3 sumComp = STVector3(0.0, 0.0, 0.0);
//    sumComp = ks * *color * fmax(STVector3::Dot(, <#const STVector3 &right#>), 0.0);
    
    
    return STColor3f(1.0, 0.0, 0.0);
}
