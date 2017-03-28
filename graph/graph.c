#include <stdio.h>
#include <string.h>

#include "graph.h"

graph_t* graph_new() {
    graph_t* g = malloc(sizeof(graph_t));
    kv_init(g->nodes);
    kv_init(g->edges);
    return g;
}

void graph_free(graph_t* g) {
    kv_destroy(g->edges);
    kv_destroy(g->nodes);
    free(g);
}

void graph_add_node(graph_t* g, node_t n) {
    kv_push(node_t, g->nodes, n);
}

void graph_add_edge(graph_t* g, edge_t e) {
    kv_push(edge_t, g->edges, e);
}

/*
void graph_transfer_func(graph_t* g, void (*func)(node_t*, node_t*)) {

}
*/

void graph_print(graph_t* g) {
    double sum = 0.0;
    for(uint32_t i=0; i<g->nodes.n; i++) {
        sum += g->nodes.a[i].v;
        char* sp = (i+1)%10 ? "  " : "\n";
        printf("%3.1f%s", g->nodes.a[i].v, sp);
    }

    // printf("\n");
    // for(uint32_t i=0; i<g->edges.n; i++) {
    //     edge_t e = g->edges.a[i];
    //     printf("%d-%d[%03.1f]  ", e.a, e.b, e.c);
    // }
    // printf("\n");    
    
    printf("sum: %3.1f\n", sum);
}

/*  
    G - edge conductivity
    n[i] =  (n1*c1+ ... +nk*ck) / (c1+c2+ ... +ck)
    
    A - c1 - B - c2 - D

     
*/

void graph_transfer(graph_t* g) {
    
    double* N = calloc(g->nodes.n, sizeof(double));
    
    for(uint32_t i=0; i<g->edges.n; i++) {

        edge_t* e = &(g->edges.a[i]);

        uint32_t a = e->a;
        uint32_t b = e->b;
        
        double c = e->c;
        double A = g->nodes.a[a].v;
        double B = g->nodes.a[b].v;
        
        N[a] += (B-A)*c/2.0;
        N[b] += (A-B)*c/2.0;
    }
    for(uint32_t i=0; i<g->nodes.n; i++) {
        node_t* n = &(g->nodes.a[i]);
        n->v += N[i];
    }
    free(N);
}
/*
node_t* node_new() {
    node_t* = malloc(sizeof(node_t));
    kv_init(node_t->link_v);
    node_t->data = NULL;
}

void node_free(node_t* n) {
    kv_destroy(*n);
    free(n);
}

edge_t* link_new(node_t* a, node_t* b) {
    edge_t* l = malloc(edge_t);
}

void link_free(edge_t* l) {
    free(l);
}
*/