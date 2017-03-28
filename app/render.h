#pragma once

#include "scene.h"

typedef struct {

    // interface
    void (*init)();
    void (*free)();

    void (*draw)(scene_t* scene);

} render_t;