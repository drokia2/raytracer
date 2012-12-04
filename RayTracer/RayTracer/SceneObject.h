#ifndef __RayTracer__SceneObject__
#define __RayTracer__SceneObject__

#include <iostream>

#include "stgl.h"
#include "st.h"
#include "Shape.h"
#include "Material.h"

class SceneObject
{
public:
    SceneObject(Shape *shape, Material *material);
    Shape *shape;
    Material *material;
    
protected:

    
    
};

#endif /* defined(__RayTracer__SceneObject__) */
