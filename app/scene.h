#pragma once
#include <GLFW/glfw3.h>

#include "vbo.h"

typedef struct {

    vbo_t** vbo;

    // interaface
    void (*init  )();
    void (*update)();
    void (*draw  )();
    void (*free  )();

    // Interactive handlers
    void (*on_key         ) (GLFWwindow* window, int key, int scancode, int action, int mods);
    void (*on_mouse_move  ) (GLFWwindow* window, double xpos, double ypos);
    void (*on_scroll      ) (GLFWwindow* window, double xoffset, double yoffset);
    void (*on_mouse_button) (GLFWwindow* window, int button, int action, int mods);

} scene_t;