#include <stdlib.h>

#include "mesh.h"

/////////////////////////////////////////////

mesh_p mesh_new(){
    mesh_p mesh = malloc(sizeof(mesh_t));
    kv_init(mesh->points);
    kv_init(mesh->triangles);
    return mesh;
}

void mesh_destroy(mesh_p mesh) {
    kv_destroy(mesh->triangles);
    kv_destroy(mesh->points);
}

/////////////////////////////////////////////

pnt_i mesh_push_pnt(mesh_p mesh, pnt_t pnt) {
    pnt_i n = mesh->points.n;
    kv_push(pnt_t, mesh->points, pnt);
    return n;
}


tri_i mesh_push_tri(mesh_p mesh, tri_t tri) {
    tri_i n = mesh->triangles.n;
    kv_push(tri_t, mesh->triangles, tri);
    return n;
}


