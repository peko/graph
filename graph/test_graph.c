#include <stdio.h>

#include "graph.h"

void transfer(node_t* a, node_t* b) {
}

int main() {
    uint32_t cnt = 9;
    graph_t* g = graph_new();
    for (uint32_t i=0; i<cnt; i++) {
        node_t n = {i};
        graph_add_node(g, n);
    };

    for (uint32_t i=0; i<cnt; i++) {
        for(uint32_t j=i+1; j<cnt; j++) {
            edge_t e = {i, j, (i+0.1)/10.0, 1.0};
            graph_add_edge(g, e);
        }
    }
    graph_print(g);
    printf("=====\n");
    for(uint32_t i=0; i<50; i++ ){
        graph_transfer(g);
        graph_print(g);
    }
    
    return 0;
}