#ifndef BELL_MAN_FORD_H
#define BELL_MAN_FORD_H

#include <hls_stream.h>
#include <ap_int.h>

#define NODES 128
#define EDGES 128
#define BELLMAN_FORD_INFINITY 10000

typedef ap_uint<8> node_index;
typedef int weight_type;

struct Edge {
    node_index u;
    node_index v;
    weight_type w;
};

void bellman_ford(node_index source, Edge edges[EDGES], weight_type dist[NODES]);

#endif
