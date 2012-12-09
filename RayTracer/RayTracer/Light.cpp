

#include "Light.h"

Light::Light(){
    
}

STColor3f Light::sumTerm(Intersection inter, Material *material, Ray *viewingRay){
    printf(" TODO implement  light sum componenet in child class\n");
    return STColor3f(1.0, 0.0, 0.0);
}

STVector3 *Light::SurfaceToLightDirection(STVector3 surfacePoint) {
    printf("TODO implement SurceToLightDirection\n");
    return NULL;
}
