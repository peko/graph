
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "scene.h"
#include "render.h"

static void on_error       (int error, const char* description);
static void on_key         (GLFWwindow* window, int key, int scancode, int action, int mods);
static void on_mouse_move  (GLFWwindow* window, double xpos, double ypos);
static void on_mouse_button(GLFWwindow* window, int button, int action, int mods);
static void on_scroll      (GLFWwindow* window, double xoffset, double yoffset);

extern render_t render_wire;
extern scene_t scene_hexagons;

static scene_t scene;
static render_t render;

int
main(int argc, char** argv) {

    GLFWwindow* window;

    printf("GLFW %d.%d.%d\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

    glfwSetErrorCallback(on_error);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

    window = glfwCreateWindow(800, 800, "show mesh", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glfwSetKeyCallback        (window, on_key         );
    glfwSetScrollCallback     (window, on_scroll      );
    glfwSetCursorPosCallback  (window, on_mouse_move  );
    glfwSetMouseButtonCallback(window, on_mouse_button);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    render = render_wire;
    render.init();

    scene = scene_hexagons;
    scene.init();

    while (!glfwWindowShouldClose(window)) {

        // float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        scene.update();
        render.draw(&scene);

        glfwPollEvents();

        glfwSwapBuffers(window);
    }
    scene.free();
    render.free();

    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}


static void
on_error(int error, const char* description) {
}

static void
on_key(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(*scene.on_key != NULL) {
        scene.on_key(window, key, scancode, action, mods);
    }

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    // if (key == 46 && action == GLFW_PRESS)
    //     next_country();
    // if (key == 44 && action == GLFW_PRESS)
    //     prev_country();
    // if (key == GLFW_KEY_M && action == GLFW_PRESS)
    //    mesh_country();
}

static void
on_mouse_move(GLFWwindow* window, double xpos, double ypos) {
    if(*scene.on_mouse_move != NULL){ 
        scene.on_mouse_move(window, xpos, ypos) ;
    };
    printf("%f\t%f\n", xpos, ypos);
}

static void 
on_mouse_button(GLFWwindow* window, int button, int action, int mods) {
    if(*scene.on_mouse_button != NULL){ 
        scene.on_mouse_button(window, button, action, mods);
    };
    printf("Button: %d\tAction: %d\tMods: %d\n", button, action, mods);
    
}

static void 
on_scroll(GLFWwindow* window, double xoffset, double yoffset) {
    if(*scene.on_scroll != NULL){ 
        scene.on_scroll(window, xoffset, yoffset);
    };
    printf("%f %f\n", xoffset, yoffset);
}
