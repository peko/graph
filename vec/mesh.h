#pragma once

#include <stdint.h>

#include "kvec.h"

typedef uint32_t pnt_i;
typedef struct {
    pnt_i a, b, c;
} tri_t;

typedef uint32_t tri_i;
typedef struct {
    float x, y, z;
} pnt_t;

typedef kvec_t(tri_t) tri_v;
typedef kvec_t(pnt_t) pnt_v;

typedef struct {
    tri_v triangles;
    pnt_v points;
} mesh_t;
typedef mesh_t* mesh_p;

mesh_p mesh_new();
void mesh_destroy(mesh_p mesh);

pnt_i mesh_push_pnt(mesh_p mesh, pnt_t pnt);
tri_i mesh_push_tri(mesh_p mesh, tri_t tri);
