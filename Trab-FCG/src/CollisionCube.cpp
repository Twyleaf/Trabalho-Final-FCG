#include "CollisionCube.h"

void CollisionCube::setPoints(glm::vec4 lowerLeftNearEdge,glm::vec4 upperRightFarEdge){
    points[0]=lowerLeftNearEdge;
    points[1]=upperRightFarEdge;
}
glm::vec4 CollisionCube::getLowerLeftNearEdge(){
    return points[0];
}

glm::vec4 CollisionCube::getUpperRightFarEdge(){
    return points[1];
}

glm::vec4 CollisionCube::getLowerRightNearEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(upperRightFarEdge.x,lowerLeftNearEdge.y,lowerLeftNearEdge.z,1.0f);
}

glm::vec4 CollisionCube::getLowerLeftFarEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(lowerLeftNearEdge.x,lowerLeftNearEdge.y,upperRightFarEdge.z,1.0f);
}

glm::vec4 CollisionCube::getLowerRightFarEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(upperRightFarEdge.x,lowerLeftNearEdge.y,upperRightFarEdge.z,1.0f);
}


//Upper

glm::vec4 CollisionCube::getUpperLeftNearEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(lowerLeftNearEdge.x,getUpperRightFarEdge.y,lowerLeftNearEdge.z,1.0f);
}

glm::vec4 CollisionCube::getUpperRightNearEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(getUpperRightFarEdge.x,getUpperRightFarEdge.y,lowerLeftNearEdge.z,1.0f);
}

glm::vec4 CollisionCube::getUpperLeftFarEdge(){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    return glm::vec4(lowerLeftNearEdge.x,getUpperRightFarEdge.y,getUpperRightFarEdge.z,1.0f);
}

bool CollisionCube::isPointInCube(glm::vec4 pointToTest){
    glm::vec4 lowerLeftNearEdge=getLowerLeftNearEdge();
    glm::vec4 upperRightFarEdge=getUpperRightFarEdge();
    bool isWithinX=(pointToTest.x>lowerLeftNearEdge&&pointToTest.x<upperRightFarEdge);
    bool isWithinY=(pointToTest.y>lowerLeftNearEdge&&pointToTest.y<upperRightFarEdge);
    bool isWithinZ=(pointToTest.z>lowerLeftNearEdge&&pointToTest.z<upperRightFarEdge);
    return(isWithinX&&isWithinY&&isWithinZ);
}


CollisionCube::CollisionCube(glm::vec4 lowerLeftNearEdge,glm::vec4 upperRightFarEdge)
{
    setPoints(lowerLeftNearEdge,upperRightFarEdge);
}

CollisionCube::~CollisionCube()
{
    //dtor
}
