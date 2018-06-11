#ifndef COLLISIONWALL_H
#define COLLISIONWALL_H

// Headers das bibliotecas OpenGL
#include <glad/glad.h>   // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h>  // Criação de janelas do sistema operacional

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>

class CollisionWall
{
    public:
        CollisionWall(glm::vec4 pointsInput[4]);
        void setPoints(glm::vec4 pointsInput[4]);
        void setFrontFace(glm::vec4 faceInput[2]);
        void setBackFace(glm::vec4 faceInput[2]);
        void setFrontLeft(glm::vec4 pointInput);
        void setFrontRight(glm::vec4 pointInput);
        void setBackLeft(glm::vec4 pointInput);
        void setBackRight(glm::vec4 pointInput);
        glm::vec4 getFrontLeft();
        glm::vec4 getFrontRight();
        glm::vec4 getBackLeft();
        glm::vec4 getBackRight();
        bool isInWall(glm::vec4 points[4]);

        virtual ~CollisionWall();

    protected:

    private:
        glm::vec4 points[4];

        float edgeEquation(glm::vec3 pontoA,glm::vec3 pontoB,glm::vec3 toTest);


};

#endif // COLLISIONWALL_H
