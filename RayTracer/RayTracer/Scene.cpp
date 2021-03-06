#include "Scene.h"
#include <fstream>
#include <sstream>
#include <iostream.h>

STColor3f Scene::CalcColor(Intersection surfaceIntersection, SceneObject *min_object, int depthLevel) {
    Ray *viewingRay = new Ray(surfaceIntersection.incomingRay);
    STColor3f calcColor = STColor3f(0, 0, 0);
    for (int i = 0; i < lights.size(); i++) {
        Light *l = lights[i];
        if(Occluded(min_object, surfaceIntersection, l) && (typeid(AmbientLight) != typeid(*l))) continue;
        calcColor = calcColor + l->sumTerm(surfaceIntersection, min_object->material, viewingRay);
    }
    
    STVector3 R = Utils::reflectVector(surfaceIntersection.normal, viewingRay->direction);
    Ray *newBounceRay = new Ray(surfaceIntersection.pt, surfaceIntersection.pt - R);
    
    SceneObject *intersectedObject = NULL;
    Intersection *intersectionPoint = NULL;
    
    if (!Intersect(newBounceRay, &intersectedObject, &intersectionPoint) || depthLevel == bounceDepth) {
        return calcColor;
    }
    
    return calcColor + min_object->material->mirr * CalcColor(*intersectionPoint, intersectedObject, depthLevel + 1);
}

bool Scene::Occluded(SceneObject *ob, Intersection surface_pt, Light *l) {
    if (typeid(PointLight) == typeid(*l)) {
        PointLight *light = (PointLight *)l;
        OcclusionRay *surfaceLightRay = new OcclusionRay(surface_pt.pt, *(light->location), epsilon);
        
        for (int i = 0; i < objects.size(); i++) {
            SceneObject *o = objects[i];
            OcclusionRay transformedRay = surfaceLightRay->TransformRay(o->transMatrix);
            if (o->shape->IntersectsRay(transformedRay, o->transMatrix)) {
                free(surfaceLightRay);
                return true;
            }
        }
        
        free(surfaceLightRay);
        
    } else if (typeid(DirectionalLight) == typeid(*l)) {
        DirectionalLight *light = (DirectionalLight *)l;
        OcclusionRay *surfaceLightRay = new OcclusionRay(surface_pt.pt,surface_pt.pt - *(light->direction), epsilon);
        
        for (int i = 0; i < objects.size(); i++) {
            SceneObject *o = objects[i];
            OcclusionRay transformedRay = surfaceLightRay->TransformRay(o->transMatrix);
            if (o->shape->IntersectsRay(transformedRay, o->transMatrix)) {
                free(surfaceLightRay);
                return true;
            }
        }
        
        free(surfaceLightRay);
    }
    
    return false;
}

bool Scene::Intersect(Ray *ray, SceneObject **intersectedObject, Intersection **intersectionPoint) {
    float min_dist = -1;
    bool hasIntersection = false;
    for (int k=0;  k < objects.size(); k++) {
        SceneObject *o = objects[k];
        
        Ray transformedRay = ray->TransformRay(o->transMatrix);        
        Intersection *inter = o->shape->IntersectsRay(transformedRay, o->transMatrix);
        
        if (inter){
            
            //retransform point
            inter = new Intersection(0.0, STVector3(o->transMatrix * STPoint3(inter->pt)), o->transMatrix.Inverse().Transpose() * inter->normal, *ray);
            
            STVector3 worldPointPlane = ray->start + ray->direction;
            float dist = abs((inter->pt - worldPointPlane).Length());  /// maybe t
            if (dist < min_dist || min_dist == -1) {
                min_dist = dist;
                *intersectedObject = o;
                *intersectionPoint = inter;
                hasIntersection = true;
            } else {
                free(inter);
            }
        }
    }
    return hasIntersection;
}

void Scene::Render() {
    for (int j = 0; j < imagePlane->GetHeight(); j++) {
        for (int i=0; i< imagePlane->GetWidth(); i++) {
            STVector2 pt_on_plane = STVector2(i, j);
            STVector3 world_pt_plane = imagePlane->ConvertToWorld(pt_on_plane);
            Ray *viewing_ray = camera->GetViewingRay(world_pt_plane);
            
            //Intersection
            SceneObject *intersectedObject = NULL;
            Intersection *intersectionPoint = NULL;
            
            if (i == 350 && j == 240) {
                printf("yo");
            }
            
            if (Intersect(viewing_ray, &intersectedObject, &intersectionPoint)) {
                STColor3f calculatedColor = CalcColor(*intersectionPoint, intersectedObject, 0);
                
                imagePlane->image->SetPixel(i, j, STColor4ub(calculatedColor));
            } else {
                
               imagePlane->image->SetPixel(i, j, STColor4ub(0, 0, 0, 255));

            }
            if (i == 350 && j == 240) {
                imagePlane->image->SetPixel(i, j, STColor4ub(255, 0, 0, 255));

            }
            
            free(viewing_ray);
            
        }
    }
    
    std::string str = imagePlane->outputFilename;
    cout << str << endl;
    imagePlane->image->Save("gen" +str);
    
    
}



Scene::Scene(std::string sceneFilename)
{
	Parse(sceneFilename);
}


void Scene::Parse(std::string sceneFilename)
{
	BeganParsing();
	std::ifstream sceneFile(sceneFilename.c_str());
    
	// Die if we couldn't find the file
	if (sceneFile.fail())
	{
		printf("Scene::Parse - Could not find input scene file '%s'\n", sceneFilename.c_str());
		exit(1);
	}
    
	char line[1024];
	while (!sceneFile.eof())
	{
		sceneFile.getline(line, 1023);
        
		std::stringstream ss;
		ss.str(line);
		std::string command;
		ss >> command;
        
		if (command == "Camera")
		{
			float ex, ey, ez, ux, uy, uz, lx, ly, lz, f, a;
			ss >> ex >> ey >> ez >> ux >> uy >> uz >> lx >> ly >> lz >> f >> a;
			STPoint3 eye(ex, ey, ez);
			STVector3 up(ux, uy, uz);
			STPoint3 lookAt(lx, ly, lz);
			ParsedCamera(eye, up, lookAt, f, a);
		}
		else
            if (command == "Output")
            {
                int w, h;
                std::string fname;
                ss >> w >> h >> fname;
                ParsedOutput(w, h, fname);
            }
            else
                if (command == "BounceDepth")
                {
                    int depth;
                    ss >> depth;
                    ParsedBounceDepth(depth);
                }
                else if (command == "ShadowBias")
                {
                    float bias;
                    ss >> bias;
                    ParsedShadowBias(bias);
                }
                else
                    if (command == "PushMatrix")
                    {
                        ParsedPushMatrix();
                    }
                    else
                        if (command == "PopMatrix")
                        {
                            ParsedPopMatrix();
                        }
                        else
                            if (command == "Rotate")
                            {
                                float rx, ry, rz;
                                ss >> rx >> ry >> rz;
                                ParsedRotate(rx, ry, rz);
                            }
                            else
                                if (command == "Scale")
                                {
                                    float sx, sy, sz;
                                    ss >> sx >> sy >> sz;
                                    ParsedScale(sx, sy, sz);
                                }
                                else
                                    if (command == "Translate")
                                    {
                                        float tx, ty, tz;
                                        ss >> tx >> ty >> tz;
                                        ParsedTranslate(tx, ty, tz);
                                    }
                                    else
                                        if (command == "Sphere")
                                        {
                                            float cx, cy, cz, r;
                                            ss >> cx >> cy >> cz >> r;
                                            STPoint3 center(cx, cy, cz);
                                            ParsedSphere(center, r);
                                        }
                                        else
                                            if (command == "Triangle")
                                            {
                                                float x1, y1, z1, x2, y2, z2, x3, y3, z3;
                                                ss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
                                                STPoint3 v[3];
                                                v[0] = STPoint3(x1, y1, z1);
                                                v[1] = STPoint3(x2, y2, z2);
                                                v[2] = STPoint3(x3, y3, z3);
                                                ParsedTriangle(v[0], v[1], v[2]);
                                            }
                                            else
                                                if (command == "AmbientLight")
                                                {
                                                    float r, g, b;
                                                    ss >> r >> g >> b;
                                                    STColor3f col(r, g, b);
                                                    ParsedAmbientLight(col);
                                                }
                                                else
                                                    if (command == "PointLight")
                                                    {
                                                        float px, py, pz, r, g, b;
                                                        ss >> px >> py >> pz >> r >> g >> b;
                                                        STPoint3 pos(px, py, pz);
                                                        STColor3f col(r, g, b);
                                                        ParsedPointLight(pos, col);
                                                    }
                                                    else
                                                        if (command == "DirectionalLight")
                                                        {
                                                            float dx, dy, dz, r, g, b;
                                                            ss >> dx >> dy >> dz >> r >> g >> b;
                                                            STVector3 dir(dx, dy, dz);
                                                            STColor3f col(r, g, b);
                                                            ParsedDirectionalLight(dir, col);
                                                        }
                                                        else
                                                            if (command == "Material")
                                                            {
                                                                float ra, ga, ba, rd, gd, bd, rs, gs, bs, rr, gr, br, shine;
                                                                ss >> ra >> ga >> ba >> rd >> gd >> bd >> rs >> gs >> bs >> rr >> gr >> br >> shine;
                                                                STColor3f amb(ra, ga, ba);
                                                                STColor3f diff(rd, gd, bd);
                                                                STColor3f spec(rs, gs, bs);
                                                                STColor3f mirr(rr, gr, br);
                                                                ParsedMaterial(amb, diff, spec, mirr, shine);
                                                            }
	}
	sceneFile.close();
    
	FinishedParsing();
}

void Scene::BeganParsing()
{
    printf("BeganParsing");
    
    // push identity matrix on
    // set current matrix to identity matrix
    transStack.push(STTransform4::Identity());
    curTransformation = transStack.top();

}

void Scene::FinishedParsing()
{
    printf("FinishedParsing");
}


void Scene::ParsedCamera(const STPoint3& eye, const STVector3& up, const STPoint3& lookAt, float fovy, float aspect)
{
    camera = new Camera(eye, up, lookAt, fovy, aspect);
    imagePlane = new ImagePlane(camera);
    
    
}

void Scene::ParsedOutput(int imgWidth, int imgHeight, const std::string& outputFilename)
{
    imagePlane->setWidthNHeight(imgWidth, imgHeight);
    imagePlane->outputFilename = outputFilename;
}

void Scene::ParsedBounceDepth(int depth)
{
    bounceDepth = depth;
}

void Scene::ParsedShadowBias(float bias)
{
    epsilon = bias;
}

void Scene::ParsedPushMatrix()
{
    //push current matrix
    transStack.push(curTransformation);
    
}

void Scene::ParsedPopMatrix()
{
    // pop top and set current matrix to top of the stack
    curTransformation = transStack.top();

    transStack.pop();
}

void Scene::ParsedRotate(float rx, float ry, float rz)
{
    //multiply current matrix by rotation matrix
    rx = (rx/360) * 2 * M_PI;
    ry = (ry/360) * 2 * M_PI;
    rz = (rz/360) * 2 * M_PI;
    curTransformation =   curTransformation * STTransform4::Rotation(rx, ry, rz) ;
    
}

void Scene::ParsedScale(float sx, float sy, float sz)
{
    // multiply current matrix by scale matrix
    curTransformation =  curTransformation * STTransform4::Scaling (sx, sy, sz);

}

void Scene::ParsedTranslate(float tx, float ty, float tz)
{
    // multiply current matrix by translate matrix
    curTransformation =  curTransformation *STTransform4::Translation(tx, ty, tz) ;

}

void Scene::ParsedSphere(const STPoint3& center, float radius)
{
    Sphere *s = new Sphere(radius, center);
    shapes.push_back(s);
    
    SceneObject *o = new SceneObject(s,lastDeclaredMaterial);
    o->transMatrix = curTransformation;
    objects.push_back(o);
    
}

void Scene::ParsedTriangle(const STPoint3& v1, const STPoint3& v2, const STPoint3& v3)
{
    Triangle *t = new Triangle(v1, v2, v3);
    shapes.push_back(t);
    
    SceneObject *o = new SceneObject(t,lastDeclaredMaterial);
    o->transMatrix = curTransformation;
    objects.push_back(o);
}

void Scene::ParsedAmbientLight(const STColor3f& col)
{
    AmbientLight *a = new AmbientLight(col);
    lights.push_back(a);
}

void Scene::ParsedPointLight(const STPoint3& loc, const STColor3f& col)
{
    STPoint3 newLoc = curTransformation * loc;
    PointLight *p = new PointLight(newLoc, col);
    lights.push_back(p);
}

void Scene::ParsedDirectionalLight(const STVector3& dir, const STColor3f& col)
{
    DirectionalLight *d = new DirectionalLight(dir, col);
    lights.push_back(d);
}

void Scene::ParsedMaterial(const STColor3f& amb, const STColor3f& diff, const STColor3f& spec, const STColor3f& mirr, float shine)
{
    lastDeclaredMaterial = new Material(amb,diff,spec,mirr,shine);
}
