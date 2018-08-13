/*
 *    Copyright 2016 Anand Muralidhar
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "myShader.h"
#include "myCube.h"

/**
 * Class constructor
 */
MyCube::MyCube() {

    MyLOGD("MyCube::MyCube");
//    initsDone = false;

    // create MyGLCamera object and set default position for the object
    myGLCamera = new MyGLCamera();
    float pos[]={0.,0.,0.,1,1,0.};
    std::copy(&pos[0], &pos[5], std::back_inserter(modelDefaultPosition));
    myGLCamera->SetModelPosition(modelDefaultPosition);
}

MyCube::~MyCube() {

    MyLOGD("MyCube::~MyCube");
    if (myGLCamera) {
        delete myGLCamera;
    }
}


void MyCube::initCubeShaderData()
{
    /* Cube */
    GLfloat cubeVertices[] =
            {
                    // In OpenGL counter-clockwise winding is default. This means that when we look at a triangle,
                    // if the points are counter-clockwise we are looking at the "front". If not we are looking at
                    // the back. OpenGL has an optimization where all back-facing triangles are culled, since they
                    // usually represent the backside of an object and aren't visible anyways.

                    // Front face
                    -1.0f, 1.0f, 1.0f,
                    -1.0f, -1.0f, 1.0f,
                    1.0f, 1.0f, 1.0f,
                    -1.0f, -1.0f, 1.0f,
                    1.0f, -1.0f, 1.0f,
                    1.0f, 1.0f, 1.0f,

                    // Right face
                    1.0f, 1.0f, 1.0f,
                    1.0f, -1.0f, 1.0f,
                    1.0f, 1.0f, -1.0f,
                    1.0f, -1.0f, 1.0f,
                    1.0f, -1.0f, -1.0f,
                    1.0f, 1.0f, -1.0f,

                    // Back face
                    1.0f, 1.0f, -1.0f,
                    1.0f, -1.0f, -1.0f,
                    -1.0f, 1.0f, -1.0f,
                    1.0f, -1.0f, -1.0f,
                    -1.0f, -1.0f, -1.0f,
                    -1.0f, 1.0f, -1.0f,

                    // Left face
                    -1.0f, 1.0f, -1.0f,
                    -1.0f, -1.0f, -1.0f,
                    -1.0f, 1.0f, 1.0f,
                    -1.0f, -1.0f, -1.0f,
                    -1.0f, -1.0f, 1.0f,
                    -1.0f, 1.0f, 1.0f,

                    // Top face
                    -1.0f, 1.0f, -1.0f,
                    -1.0f, 1.0f, 1.0f,
                    1.0f, 1.0f, -1.0f,
                    -1.0f, 1.0f, 1.0f,
                    1.0f, 1.0f, 1.0f,
                    1.0f, 1.0f, -1.0f,

                    // Bottom face
                    1.0f, -1.0f, -1.0f,
                    1.0f, -1.0f, 1.0f,
                    -1.0f, -1.0f, -1.0f,
                    1.0f, -1.0f, 1.0f,
                    -1.0f, -1.0f, 1.0f,
                    -1.0f, -1.0f, -1.0f,
            };

    // R, G, B, A
    GLfloat cubeFaceColors[] =
            {
                    // Front face (red)
                    1.0f, 0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f, 1.0f,
                    1.0f, 0.0f, 0.0f, 1.0f,

                    // Right face (green)
                    0.0f, 1.0f, 0.0f, 1.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,
                    0.0f, 1.0f, 0.0f, 1.0f,

                    // Back face (blue)
                    0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f, 0.0f, 1.0f, 1.0f,

                    // Left face (yellow)
                    1.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f, 1.0f,
                    1.0f, 1.0f, 0.0f, 1.0f,

                    // Top face (cyan)
                    0.0f, 1.0f, 1.0f, 1.0f,
                    0.0f, 1.0f, 1.0f, 1.0f,
                    0.0f, 1.0f, 1.0f, 1.0f,
                    0.0f, 1.0f, 1.0f, 1.0f,
                    0.0f, 1.0f, 1.0f, 1.0f,
                    0.0f, 1.0f, 1.0f, 1.0f,

                    // Bottom face (magenta)
                    1.0f, 0.0f, 1.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 1.0f,
                    1.0f, 0.0f, 1.0f, 1.0f
            };

    // X, Y, Z
    // The normal is used in light calculations and is a vector which points
    // orthogonal to the plane of the surface. For a cube model, the normals
    // should be orthogonal to the points of each face.
    GLfloat cubeFaceNormals[] =
            {
                    // Front face
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,
                    0.0f, 0.0f, 1.0f,

                    // Right face
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,
                    1.0f, 0.0f, 0.0f,

                    // Back face
                    0.0f, 0.0f, -1.0f,
                    0.0f, 0.0f, -1.0f,
                    0.0f, 0.0f, -1.0f,
                    0.0f, 0.0f, -1.0f,
                    0.0f, 0.0f, -1.0f,
                    0.0f, 0.0f, -1.0f,

                    // Left face
                    -1.0f, 0.0f, 0.0f,
                    -1.0f, 0.0f, 0.0f,
                    -1.0f, 0.0f, 0.0f,
                    -1.0f, 0.0f, 0.0f,
                    -1.0f, 0.0f, 0.0f,
                    -1.0f, 0.0f, 0.0f,

                    // Top face
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,

                    // Bottom face
                    0.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f,
                    0.0f, -1.0f, 0.0f
            };






    /******* Cube ***/
    // Generate a vertex buffer and load the vertices into it
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    // Generate a vertex buffer and load the colors into it
    glGenBuffers(1, &colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeFaceColors), cubeFaceColors, GL_STATIC_DRAW);

    // Generate a vertex buffer and load the normals into it
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeFaceNormals),cubeFaceNormals , GL_STATIC_DRAW);
    // shader related setup
    std::string vertexShader    = "shaders/cubeMVP.vsh";
    std::string fragmentShader  = "shaders/cubeMVP.fsh";

    // compile the vertex and fragment shaders, and link them together
    facesShaderProgramID = LoadShaders(vertexShader, fragmentShader);
    // fetch the locations of "vertexPosition" and "vertexColor" from the shader & "vertexNormal"
    vertexAttribute = GetAttributeLocation(facesShaderProgramID, "vertexPosition");
    normalAttribute  = GetAttributeLocation(facesShaderProgramID, "vertexNormal");
    colorAttribute  = GetAttributeLocation(facesShaderProgramID, "vertexColor");
    MVPLocation     = GetUniformLocation(facesShaderProgramID, "mvpMat");
    lightDirectionLocation  = GetUniformLocation(facesShaderProgramID, "lightDirection");
    diffuseLightIntensityLocation = GetUniformLocation(facesShaderProgramID, "diffuseLightIntensity");
}
/**
 * Perform inits and load the triangle's vertices/colors to GLES
 */
void MyCube::PerformGLInits() {

    MyLOGD("MyCube::PerformGLInits");

    MyGLInits();
    initCubeShaderData();

    CheckGLError("Cube::PerformGLInits");
//    initsDone = true;
}

/**
 * Render our colorful cube
 */
void MyCube::RenderCube() {
    // use the shader
    glUseProgram(facesShaderProgramID);

    glm::mat4 mvpMat = myGLCamera->GetMVP();
    glUniformMatrix4fv(MVPLocation, 1, GL_FALSE, (const GLfloat *) &mvpMat);

    // set light direction
    glm::vec3 lightDirection = glm::vec3(0.0, 1.0, -1.0);
    glUniform3fv(lightDirectionLocation, 1, (const GLfloat *) &lightDirection);
    // set light diffuse
    glm::vec3 diffuseLightIntensity = glm::vec3(1.0, 1.0, 1.0);
    glUniform3fv(diffuseLightIntensityLocation, 1, (const GLfloat *) &diffuseLightIntensity);

    // enable the vertex buffer
    glEnableVertexAttribArray(vertexAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer( vertexAttribute, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

    // enable the color buffer
    glEnableVertexAttribArray(colorAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer( colorAttribute, 4, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    // enable the normal buffer
    glEnableVertexAttribArray(normalAttribute);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glVertexAttribPointer( normalAttribute, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );

    // Draw the colorful triangle
    glDrawArrays(GL_TRIANGLES, 0, 36); // cube has 12 triangles = 36 vertices.

    glDisableVertexAttribArray(vertexAttribute);
    glDisableVertexAttribArray(colorAttribute);
    glDisableVertexAttribArray(normalAttribute);
}

/**
 * Render to the display
 */
void MyCube::Render() {

    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    RenderCube();
    CheckGLError("Cube::Render");

}

/**
 * set the viewport, function is also called when user changes device orientation
 */
void MyCube::SetViewport(int width, int height) {

    screenHeight = height;
    screenHeight = height;
    screenWidth = width;
    glViewport(0, 0, width, height);
    CheckGLError("Cube::SetViewport");

    myGLCamera->SetAspectRatio((float) width / height);
}


/**
 * reset model's position in double-tap
 */
void MyCube::DoubleTapAction() {

    myGLCamera->SetModelPosition(modelDefaultPosition);

}

/**
 * rotate the model if user scrolls with one finger
 */
void MyCube::ScrollAction(float distanceX, float distanceY, float positionX, float positionY) {

    myGLCamera->RotateModel(distanceX, distanceY, positionX, positionY);
}

/**
 * pinch-zoom: move the model closer or farther away
 */
void MyCube::ScaleAction(float scaleFactor) {

    myGLCamera->ScaleModel(scaleFactor);
}

/**
 * two-finger drag: displace the model by changing its x-y coordinates
 */
void MyCube::MoveAction(float distanceX, float distanceY) {

    myGLCamera->TranslateModel(distanceX, distanceY);
}