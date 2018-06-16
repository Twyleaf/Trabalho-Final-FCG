#ifndef COLLISIONCUBE_H
#define COLLISIONCUBE_H

#include <vector>

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
        CollisionCube(glm::vec4 lowerLeftNearEdge,glm::vec4 upperRightFarEdge);
        virtual ~CollisionCube();


    private:
        glm::vec4 points[2];
};

#endif // COLLISIONCUBE_H
