#include <iostream>
#include "st.h"
#include "stgl.h"
#include "stglut.h"
#include "Scene.h"

std::string sceneFileName;
Scene *scene;


void usage()
{
	printf("usage: raytracer sceneFileName\n");
	exit(0);
}

void GenerateImage() {
    // set width and height based on the fovy of the image
    printf("generate image\n");
    
    
    for (int j = 0; j < scene->imagePlane->GetHeight(); j++) {
        for (int i=0; i< scene->imagePlane->GetWidth(); i++) {
            STVector2 pt_on_plane = STVector2(i, j);
            STVector3 world_pt_plane = scene->imagePlane->ConvertToWorld(pt_on_plane);
            Ray *viewing_ray = scene->camera->GetViewingRay(world_pt_plane);
            Shape *min_shape = NULL;
            float min_dist = -1;
            RayIntersection * min_intersect = NULL;
            for (int k=0;  k < scene->shapes.size(); k++) {
                Shape *s = (scene->shapes)[k];
                RayIntersection *inter = s->IntersectsRay(*viewing_ray);
                if (inter){
                    float dist = inter->t;//abs((*intersectVect - world_pt_plane).Length());
                    if (dist < min_dist || min_dist == -1) {
                        min_dist = dist;
                        min_shape = s;
                        min_intersect = inter;
                    }
                }
            }
            
            if (min_intersect) { // if camera can see it 
                scene->imagePlane->image->SetPixel(i, j, STColor4ub(255, 0.0, 0.0, 255));
            }
            // TODO iterate through all of the lights to figure out the shading
            
            
            
        }
    }
    std::string str = scene->imagePlane->outputFilename;
    
    scene->imagePlane->image->Save("adriana.jpg");
    
}


int main(int argc, const char * argv[])
{
    if (argc != 2)
		usage();
    sceneFileName = argv[1];
    scene = new Scene(sceneFileName);

    
    printf (" about to generate image\n");
    
    GenerateImage();
    
    
    
    
    
    // set Camera Position C
    
    // iter through pixels
        //compute viewing ray
            //
        //find first object/ intersections
        //set pixel color
    //

    std::cout << "Hello, World!\n";
    return 0;
}

