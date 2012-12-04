//
//  Material.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/3/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Material.h"
Material::Material(const STColor3f& a, const STColor3f& d, const STColor3f& s, const STColor3f& m, float sh) {
    amb = a;
    diff = d;
    spec = s;
    mirr = m;
    shine = sh;
}