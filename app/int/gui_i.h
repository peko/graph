#pragma once

#include <GLFW/glfw3.h>

// gui interface
typedef struct {
    void (*init)(GLFWwindow* window);
    void (*update)(void);
    void (*draw)(void);
    void (*free)(void);
} gui_i;