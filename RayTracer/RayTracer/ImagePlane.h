//
//  ImagePlane.h
//  RayTracer
//
//  Created by Adriana Diakite on 12/1/12.
//  Copyright (c) 2012 Adriana Diakite. All rights reserved.
//

#ifndef __RayTracer__ImagePlane__
#define __RayTracer__ImagePlane__

#include <iostream>
#include "st.h"
#include "Camera.h"
#include "stgl.h"

class ImagePlane
{
public:
    typedef STColor4ub Pixel;

	ImagePlane(Camera *cam);
    std::string outputFilename;
    
    // supposed to be using bilinear interpolation
    
    
	/** CS 148 TODO: Add methods for the scene to render itself, etc. **/
    
    // gen viewing rays
    void SetPixel(int x, int y, Pixel value);

    Pixel GetPixel(int x, int y);
    
    int GetWidth();
//
    int GetHeight();
    
    void setWidthNHeight(int w, int h);

    STVector3 ConvertToWorld(STVector2 pt);

    STStatus Save(const std::string& filename) const;
    
    STVector3 LL;
    STVector3 UL;
    STVector3 LR;
    STVector3 UR;
    
    STImage *image;

private:

    int width;
    int height;
    
    Camera *camera;
    
};

#endif /* defined(__RayTracer__ImagePlane__) */
