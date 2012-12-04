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

STColor3f AmbientLight::sumTerm(RayIntersection inter, Material *material, Ray *viewingRay){
    return material->amb * (*color);
}