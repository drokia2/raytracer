
//
//  ImagePlane.cpp
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#include "ImagePlane.h"
ImagePlane::ImagePlane(Camera *cam)
{
    camera = cam;
    
    STVector3 *w = camera->w;
    STVector3 *b = camera->up;
    
    camera->u = new STVector3(STVector3::Cross(*b, *w));
    (*(camera->u)).Normalize();
    camera->v = new STVector3(STVector3::Cross(*w, *(camera->u)));
    
    STVector3 C = *(camera->eye) + *w;
    
    float y = tan(camera->fovy/2);
    float x = tan(camera->aspect * camera->fovy/2);
    
    STVector3 u, v;
    u = *(camera->u);
    v = *(camera->v);
    
    LL = C + x* u - y* v;
    UL = C + x* u + y* v;
    LR = C - x* u - y* v;
    UR = C - x* u + y* v;
    

    
}

STVector3 ImagePlane::ConvertToWorld(STVector2 pt) {
    float u, v;
    u = pt.x/image->GetWidth();
    v = pt.y/image->GetHeight();
    if (pt.x == 155 && pt.y == 155){
        printf(" yo\n");
    }
    
    STVector3 world = (1.0 - u)*((1.0-v)*LL + v* UL) + u * ((1.0-v)*LR + v*UR);
    return world;
}

void ImagePlane::setWidthNHeight(int w, int h) {
    image = new STImage(w, h);
}

int ImagePlane::GetWidth() {
    return image->GetWidth();
}

int ImagePlane::GetHeight() {
    return image->GetHeight();
}

void ImagePlane::SetPixel(int x, int y, Pixel value) {
    image->SetPixel(x,y,value);
}

ImagePlane::Pixel ImagePlane::GetPixel(int x, int y){
    return image->GetPixel(x, y);
}

STStatus ImagePlane::Save(const std::string& filename) const
{
    return image->Save(filename);
}



