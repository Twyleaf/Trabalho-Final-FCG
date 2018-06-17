#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H
// Headers das bibliotecas OpenGL
#include <glad/glad.h>   // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h>  // Criação de janelas do sistema operacional

// Headers da biblioteca GLM: criação de matrizes e vetores.
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class CollisionSphere
{
    public:
        void setCenter(glm::vec4 centerInput);
        void setRadius(float radiusInput);
        glm::vec4 getCenter();
        float getRadius();
        CollisionSphere(glm::vec4 centerInput,float radiusInput);
        virtual ~CollisionSphere();
        bool isPointInSphere(glm::vec4 pointToTest);
        bool isObjectInSphere(std::vector<glm::vec4> collisionRectangle);

    protected:

    private:
        glm::vec4 center;
        float radius;
};

#endif // COLLISIONSPHERE_H
