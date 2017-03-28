#pragma once

#include <stdint.h>

#include "kvec.h"

typedef struct {
    double v;
} node_t;

typedef struct {
    uint32_t a;
    uint32_t b;
    double c;
    double k;
} edge_t;

typedef kvec_t(node_t) node_v;
typedef kvec_t(edge_t) edge_v;

typedef struct {
    node_v nodes;
    edge_v edges;
} graph_t;

graph_t* graph_new();
void graph_free(graph_t*);

void graph_add_node(graph_t* g, node_t n);
void graph_add_edge(graph_t* g, edge_t n);

void graph_transfer(graph_t* g);
void graph_print(graph_t* g);
