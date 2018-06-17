#include "CollisionSphere.h"
#include <iostream>
#include "float.h"

void CollisionSphere::setCenter(glm::vec4 centerInput){
    center=centerInput;
}

void CollisionSphere::setRadius(float radiusInput){
    radius=radiusInput;
}

glm::vec4 CollisionSphere::getCenter(){
    return center;
}

float CollisionSphere::getRadius(){
    return radius;
}

CollisionSphere::CollisionSphere(glm::vec4 centerInput,float radiusInput)
{
    setCenter(centerInput);
    setRadius(radiusInput);
}

CollisionSphere::~CollisionSphere()
{
    //dtor
}

bool CollisionSphere::isPointInSphere(glm::vec4 pointToTest){
    float pointDistance=glm::length(getCenter()-pointToTest);
    if(pointDistance>0&&pointDistance <= DBL_MAX)
        //std::cout<<pointDistance<<std::endl;
    if(pointDistance<0){
        pointDistance=pointDistance*(-1);
    }
    if(pointDistance<getRadius()){
        return true;
    }else return false;

}


bool CollisionSphere::isObjectInSphere(std::vector<glm::vec4> collisionRectangle){
    /*
    for(int i=0;i<4;i++){
        if(isPointInSphere(collisionRectangle[i])){
            return true;
        }
    }*/
     if(isPointInSphere(collisionRectangle[0])){
        //std::cout<<std::endl<<"0:";
        return true;
     }
    if(isPointInSphere(collisionRectangle[1])){
        //std::cout<<std::endl<<"1:";
        return true;
     }
    if(isPointInSphere(collisionRectangle[2])){
        //std::cout<<std::endl<<"2:";
        return true;
     }
    if(isPointInSphere(collisionRectangle[3])){
        //std::cout<<std::endl<<"3:";
        return true;
     }

    return false;
}
