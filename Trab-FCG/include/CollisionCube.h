#ifndef COLLISIONCUBE_H
#define COLLISIONCUBE_H

// Headers das bibliotecas OpenGL
#include <glad/glad.h>   // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h>  // Criação de janelas do sistema operacional

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class CollisionCube
{
    public:
        void setPoints(glm::vec4 lowerLeftNearEdge,glm::vec4 upperRightFarEdge);
        glm::vec4 getLowerLeftNearEdge();
        glm::vec4 getUpperRightFarEdge();
        glm::vec4 getLowerRightNearEdge();
        glm::vec4 getLowerLeftFarEdge();
        glm::vec4 getLowerRightFarEdge();
        glm::vec4 getUpperLeftNearEdge();
        glm::vec4 getUpperRightNearEdge();
        glm::vec4 getUpperLeftFarEdge();
        bool isPointInCube(glm::vec4 pointToTest);
        bool isObjectInCube(glm::vec4* collisionRectangle);
        CollisionCube(glm::vec4 lowerLeftNearEdge,glm::vec4 upperRightFarEdge);
        virtual ~CollisionCube();


    private:
        glm::vec4 points[2];
};

#endif // COLLISIONCUBE_H
