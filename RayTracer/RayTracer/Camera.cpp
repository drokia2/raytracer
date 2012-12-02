//
//  Camera.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "Camera.h"

Camera::Camera(const STPoint3& e, const STVector3& u, const STPoint3& lA, float f, float a)
{
    eye = new STVector3(e);
    up = new STVector3(u);
    lookAt= new STVector3(lA);
    fovy = f;
    aspect = a;
    w = new STVector3(*lookAt - *eye);
    (*w).Normalize();

}

STVector3 Camera::ConvertToWorld(STVector2 pt) {
    STVector3 world = pt.x * (*u) + pt.y * (*v) + (*w);
    return world;    
}

Ray *Camera::GetViewingRay(STVector2 img_plane_pt){
    //convert img_plane_pt to world coordinates
    STVector3 world_img_plane_pt = ConvertToWorld(img_plane_pt);
    STVector3 normalizedDirection = world_img_plane_pt - *eye;
    
    Ray *r = new Ray(world_img_plane_pt, world_img_plane_pt + normalizedDirection);
    
    return r;
}


