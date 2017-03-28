#include <stdio.h>
#include <math.h>

#include "mesh.h"

#define PI2 2.0*3.141592654

mesh_p mesh;

void build();
void load();
void calc();
float rnd();

int main(int argc, char* argv) {
    build();
    load();
    calc();
}

void build(pnt_i n) {
    mesh = mesh_new();
    for(pnt_i i=0; i<n; i++) {
        pnt_i a, b, c;
        float x = 10.0 * cosf(PI2*i/n);
        float y = 10.0 * sinf(PI2*i/n);

        a = mesh_push_pnt(mesh, (pnt_t){x+rnd(), y+rnd(), rnd()});
        b = mesh_push_pnt(mesh, (pnt_t){x+rnd(), y+rnd(), rnd()});
        c = mesh_push_pnt(mesh, (pnt_t){x+rnd(), y+rnd(), rnd()});
    }
    for(tri_i i=0; i<103; i++) {
        mesh_push_tri(mesh, (tri_t){i%100, (i+1)%100, (i+2)%100});
    }
}

void load() {

}

void calc() {

}

void destroy() {
    mesh_destroy(mesh);
}

float rnd() {
    return (0.5-(float)random()/RAND_MAX)*2.0;
}
