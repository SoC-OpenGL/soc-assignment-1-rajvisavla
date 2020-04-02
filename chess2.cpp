#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library
#include <iostream>

 #include <math.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    GLenum err = glewInit();
if (GLEW_OK != err)
{
  // failed to initialize GLEW!;
}
std::cout<< "Using GLEW Version: "; glewGetString(GLEW_VERSION);

// build and compile our shader program
    // ------------------------------------
    // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
bool f=true;
float x=0.0f,y=0.0f;
 float vertices[6*6*64*2];
for ( int i = 0; i < 8; i++)
{  
    for(int j=0;j<8;j++)
{ 

 if(f)
   {  
      vertices[72*8*i + 36*j]=x;
      vertices[72*8*i +36*j+1]=y;
vertices[72*8*i +36*j+2]=0.0f;

      vertices[72*8*i +36*j+3]=1.0;
      vertices[72*8*i +36*j+4]=1.0;
vertices[72*8*i +36*j+5]=1.0;

      vertices[72*8*i +36*j+6]=x;
      vertices[72*8*i +36*j+7]=y+0.1;
vertices[72*8*i +36*j+8]=0.0f;

      vertices[72*8*i +36*j+9]=1.0;
      vertices[72*8*i +36*j+10]=1.0;
vertices[72*8*i +36*j+11]=1.0;

 vertices[72*8*i + 36*j+12]=x+0.1;
      vertices[72*8*i +36*j+13]=y+0.1;
vertices[72*8*i +36*j+14]=0.0f;

      vertices[72*8*i +36*j+15]=1.0;
      vertices[72*8*i +36*j+16]=1.0;
vertices[72*8*i +36*j+17]=1.0;


vertices[72*8*i + 36*j+18]=x+0.1;
      vertices[72*8*i +36*j+19]=y+0.1;
vertices[72*8*i +36*j+20]=0.0f;

      vertices[72*8*i +36*j+21]=1.0;
      vertices[72*8*i +36*j+22]=1.0;
vertices[72*8*i +36*j+23]=1.0;


      vertices[72*8*i +36*j+24]=x+0.1;
      vertices[72*8*i +36*j+25]=y;
vertices[72*8*i +36*j+26]=0.0f;

      vertices[72*8*i +36*j+27]=1.0;
      vertices[72*8*i +36*j+28]=1.0;
vertices[72*8*i +36*j+29]=1.0;

vertices[72*8*i + 36*j+30]=x;
      vertices[72*8*i +36*j+31]=y;
vertices[72*8*i +36*j+32]=0.0f;

      vertices[72*8*i +36*j+33]=1.0;
      vertices[72*8*i +36*j+34]=1.0;
vertices[72*8*i +36*j+35]=1.0;

      f=!f;
      
   }
   else
   { 
        vertices[72*8*i + 36*j]=x;
      vertices[72*8*i +36*j+1]=y;
vertices[72*8*i +36*j+2]=0.0f;

      vertices[72*8*i +36*j+3]=0.0;
      vertices[72*8*i +36*j+4]=0.0;
vertices[72*8*i +36*j+5]=0.0;

      vertices[72*8*i +36*j+6]=x;
      vertices[72*8*i +36*j+7]=y+0.1;
vertices[72*8*i +36*j+8]=0.0f;

      vertices[72*8*i +36*j+9]=0.0;
      vertices[72*8*i +36*j+10]=0.0;
vertices[72*8*i +36*j+11]=0.0;

 vertices[72*8*i + 36*j+12]=x+0.1;
      vertices[72*8*i +36*j+13]=y+0.1;
vertices[72*8*i +36*j+14]=0.0f;

      vertices[72*8*i +36*j+15]=0.0;
      vertices[72*8*i +36*j+16]=0.0;
vertices[72*8*i +36*j+17]=0.0;


vertices[72*8*i + 36*j+18]=x+0.1;
      vertices[72*8*i +36*j+19]=y+0.1;
vertices[72*8*i +36*j+20]=0.0f;

      vertices[72*8*i +36*j+21]=0.0;
      vertices[72*8*i +36*j+22]=0.0;
vertices[72*8*i +36*j+23]=0.0;


      vertices[72*8*i +36*j+24]=x+0.1;
      vertices[72*8*i +36*j+25]=y;
vertices[72*8*i +36*j+26]=0.0f;

      vertices[72*8*i +36*j+27]=0.0;
      vertices[72*8*i +36*j+28]=0.0;
vertices[72*8*i +36*j+29]=0.0;

vertices[72*8*i + 36*j+30]=x;
      vertices[72*8*i +36*j+31]=y;
vertices[72*8*i +36*j+32]=0.0f;

      vertices[72*8*i +36*j+33]=0.0;
      vertices[72*8*i +36*j+34]=0.0;
vertices[72*8*i +36*j+35]=0.0;

      f=!f;
      
   }

y=y+0.1;
}
x = x + 0.1;y = 0.0f;f=!f;
}

   unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

//draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
       // glDrawArrays(GL_LINE_LOOP,0,4*64*2*2);
 glDrawArrays(GL_TRIANGLES,0,72*64);
        // glBindVertexArray(vertices); // no need to unbind it every time 


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
  glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
