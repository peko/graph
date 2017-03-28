#include <math.h>

#include "scene.h"
#include "kvec.h"

static vbo_t* vbo;

// interaface
static void 
_init(){
    vbo = vbo_new();    
    // alloc ten parts by ten points
    parts_v parts;
    kv_init(parts);
    for(int i=0; i<33; i++) {
        points_v points;
        kv_init(points);
        float d=8.0;
        for(int j=0; j<d; j++) {
            point_t p = (point_t) {
                sin(j/d*3.141*2.0+i/64.0*3.141)/(i/5.0+1.0), 
                cos(j/d*3.141*2.0+i/64.0*3.141)/(i/5.0+1.0)};
            kv_push(point_t, points, p);
        }
        kv_push(points_v, parts, points);
    }

    // fill vbo
    vbo_fill(vbo, &parts);
    
    // free parts
    for(int i=0; i<10; i++ ) kv_destroy(parts.a[i]);
    kv_destroy(parts);
};

static void 
_update(){};

static void 
_draw(){

};

static void 
_free() {
    vbo_free(vbo);
};

// Interactive handlers
static void on_key         (GLFWwindow* window, int key, int scancode, int action, int mods){};
static void on_mouse_move  (GLFWwindow* window, double xpos, double ypos){};
static void on_scroll      (GLFWwindow* window, double xoffset, double yoffset){};
static void on_mouse_button(GLFWwindow* window, int button, int action, int mods){};

scene_t scene_hexagons = {
    
    &vbo,

    //interface
    _init,
    _update,
    _draw,
    _free,

    // events
    on_key,
    on_mouse_move,
    on_scroll,
    on_mouse_button
};