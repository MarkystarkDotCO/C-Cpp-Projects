#undef GLFW_DLL
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <cmath>

#include "Shader.h"
#include "Window.h"
#include "Mesh.h"

const GLint WIDTH = 800, HEIGHT = 600;
const float toRadians = 3.14159265f / 180.0f;

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader> shaderList;

float triOffset = 0.0f;
float triIncrement = 0.0005f;
float triMaxOffset = 0.7f;
float currWater = 0.0f;
float currMax = 0.7f;

bool direction = true;

//Vertex Shader
static const char* vShader = "Shaders/shader.vert";

//Fragment Shader
static const char* fShader = "Shaders/shader.frag";

void CreateTube(){
    GLfloat vertices[] =
    {
        -0.5f, 1.0f, 0.0f,
        0.5f, 1.0f, 0.0f,
        0.5f, 0.98f, 0.0f,
        -0.5f, 0.98f, 0.0f,
       

    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };
    Mesh* obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj1);

}
void CreateTriangle()
{
    GLfloat vertices[] =
    {
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj1 = new Mesh();
    obj1->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj1);

    Mesh* obj2 = new Mesh();
    obj2->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj2);
}


void CreateSquire()
{
    GLfloat vertices[] =
    {
        0.09f,  0.09f, 0.0f,
        0.09f, -0.09f, 0.0f,
        -0.09f, -0.09f, 0.0f,
        -0.09f, 0.09f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj3 = new Mesh();
    obj3->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj3);

    Mesh* obj4 = new Mesh();
    obj4->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj4);
}
void CreateGlass_1()
{
    GLfloat vertices[] =
    {
        0.7f,  -0.9f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        -0.7f, -0.9f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj5 = new Mesh();
    obj5->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj5);

    
}
void CreateGlass_2()
{
    GLfloat vertices[] =
    {
        0.1f, 0.5f, 0.0f,
        0.1, -0.7f, 0.0f,
        -0.1f, -0.7f, 0.0f,
        -0.1f, 0.5f, 0.0f
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj6 = new Mesh();
    obj6->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj6);


}
void CreateGlass_3()
{
    GLfloat vertices[] =
    {
         1.0f, 1.0f, 0.0f,
         0.05f, 0.0f, 0.0f,
          -0.05f, 0.0f, 0.0f,
         -1.0f, 1.0f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj7 = new Mesh();
    obj7->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj7);


}

void CreateShaders()
{
    Shader* shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(*shader1);
}

void CreateBottom_1(){
    GLfloat vertices[] =
    {
          0.09f,  0.09f, 0.0f,
        0.09f, -0.09f, 0.0f,
        -0.09f, -0.09f, 0.0f,
        -0.09f, 0.09f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj7 = new Mesh();
    obj7->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj7);
}
void CreateBottom_2(){
     GLfloat vertices[] =
    {
          0.09f,  0.09f, 0.0f,
        0.29f, -0.09f, 0.0f,
        -0.29f, -0.09f, 0.0f,
        -0.09f, 0.09f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj7 = new Mesh();
    obj7->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj7);
}
void CreateBottom_3(){
    GLfloat vertices[] =
    {
          0.09f,  0.09f, 0.0f,
        0.09f, -0.09f, 0.0f,
        -0.09f, -0.09f, 0.0f,
        -0.09f, 0.09f, 0.0f,
    };

    unsigned int indices[] =
    {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 1, 2
    };

    Mesh* obj7 = new Mesh();
    obj7->CreateMesh(vertices, indices, 12, 12);
    meshList.push_back(obj7);
}

int main()
{
    mainWindow = Window(WIDTH, HEIGHT);
    mainWindow.initialise();
    CreateGlass_1();
    CreateGlass_2();
    CreateGlass_3();
    CreateSquire();
    CreateTube();
    CreateShaders();
    CreateBottom_1();
    CreateBottom_2();
    CreateBottom_3();
    CreateSquire();
    CreateSquire();//R |

    GLuint uniformModel = 0, uniformProjection = 0;

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);

    //Loop until window closed
    while (!mainWindow.getShouldClose())
    {
        //Get + Handle user input events
        glfwPollEvents();

        if (direction) { 
            currWater += triIncrement/10.0f;
            triOffset += triIncrement; }

        if (abs(triOffset) >= triMaxOffset) {
            triOffset = 0.0005f;
            triIncrement = 0.0005;
    }
        if (abs(currWater) >= currMax) {
            currWater = 0.0f;
        }
        triIncrement += 0.0001;

        //Clear window
        glClearColor(0.5f+triOffset, 0.0f, 0.0f+triOffset, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //draw here
        shaderList[0].UseShader();
        uniformModel = shaderList[0].GetModelLocation();
        uniformProjection = shaderList[0].GetProjectionLocation();

        //Object 1
        glm::mat4 model(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, 0.1f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[0]->RenderMesh();

        //Object 2
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[1]->RenderMesh();

        //Object 3
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, 0.18f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[2]->RenderMesh();

        //Object 4
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, triOffset, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[3]->RenderMesh();

        //Object 5
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.1250f, triOffset/1.5f+0.51f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[4]->RenderMesh();

        //Object 6 Tube
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(-1.0f, 0.55f, -2.5f));
        model = glm::scale(model, glm::vec3(1.4f, 1.4f, 1.0f));
        model = glm::rotate(model, 2.14f, glm::vec3(-1.0f, -1.0f, 0.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[5]->RenderMesh();

        //Object 7 Bottom_1
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.45f, 1.2f, -2.5f));
        model = glm::scale(model, glm::vec3(0.8f, 1.8f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[6]->RenderMesh();

        //Object 7 Bottom_2
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.45f, 0.9f, -2.5f));
        model = glm::scale(model, glm::vec3(0.8f, 1.8f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[7]->RenderMesh();

        //Object 7 Bottom_3
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.45f, 0.25f, -2.5f));
        model = glm::scale(model, glm::vec3(2.52f, 5.5f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[8]->RenderMesh();

        //Object 7 Water
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(-.4f, .5f-currWater, -2.5f));
        model = glm::scale(model, glm::vec3(.05f, 1.5f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[9]->RenderMesh();

        //Object 7 Water
        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(-.4f, .5f - currWater/0.1f, -2.5f));
        model = glm::scale(model, glm::vec3(.05f, 1.5f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        meshList[10]->RenderMesh();

        glUseProgram(0);

        //end draw

        mainWindow.swapBuffers();
    }

    return 0;
}
