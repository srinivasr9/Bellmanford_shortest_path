#include "bellman_ford.h"

void bellman_ford(node_index source, Edge edges[EDGES], weight_type dist[NODES]) {

    #pragma HLS INTERFACE s_axilite port=source
    #pragma HLS INTERFACE s_axilite port=edges
    #pragma HLS INTERFACE s_axilite port=dist
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS ARRAY_PARTITION variable=dist cyclic factor=4 dim=1

    node_index i, j;
    init_loop: for (i = 0; i < NODES; i++) {
        dist[i] = BELLMAN_FORD_INFINITY;
    }
    dist[source] = 0;

    weight_type updated_dist[NODES];
    #pragma HLS ARRAY_PARTITION variable=updated_dist complete

    relaxed_loop: for (i = 0; i < NODES - 1; i++) {

        for (j = 0; j < NODES; j++) {
            updated_dist[j] = dist[j];
        }

        edge_loop: for (j = 0; j < EDGES; j++) {
            #pragma HLS PIPELINE II=1
            node_index u = edges[j].u;
            node_index v = edges[j].v;
            weight_type weight = edges[j].w;

            if (dist[u] != BELLMAN_FORD_INFINITY) {
                weight_type new_dist = dist[u] + weight;
                if (new_dist < updated_dist[v]) {
                    updated_dist[v] = new_dist;
                }
            }
        }

        for (j = 0; j < NODES; j++) {
            #pragma HLS PIPELINE II=1
            dist[j] = updated_dist[j];
        }
    }
}