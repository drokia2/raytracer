//
//  Shape.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Shape.h"

Shape::Shape(){
    
}

STVector3 * Shape::IntersectsRay(Ray r) {
    printf("TODO: implement it in child class\n");
    
//    pow(( A + t* D - C), 2) - pow(r, 2) = 0
    return NULL;
}

STVector3  Shape::CalcNormal(STVector3 surface_pt) {
    printf("TODO: implement it in child class\n");
    
    //    pow(( A + t* D - C), 2) - pow(r, 2) = 0
    return NULL;
}
