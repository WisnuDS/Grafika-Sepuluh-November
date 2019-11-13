    cmake_minimum_required(VERSION 3.10) # common to every CLion project
    project(OpenGLLinuxTest) # project name

    set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.

    ################################################

    add_executable(OpenGLLinuxTest1 main.cpp Bom.cpp Bom.h Pesawat.cpp Pesawat.h) #common to all clion project

    target_link_libraries(OpenGLLinuxTest1 ${OpenGlLinkers}) # linking opengl libraries to the project

    #################################################