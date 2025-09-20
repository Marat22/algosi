// https://leetcode.com/problems/clone-graph/

#include<stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* copy_node(struct Node *node, struct Node** processed_nodes) {
    if (processed_nodes[node->val] != NULL) {
        return processed_nodes[node->val];
    }

    struct Node** current_neighbors = malloc(sizeof(struct Node) * node->numNeighbors);
    struct Node *node_copy = malloc(sizeof(struct Node));
    processed_nodes[node->val] = node_copy;
    node_copy->val = node->val;
    node_copy->numNeighbors = node->numNeighbors;
    node_copy->neighbors = current_neighbors;

    for (int i = 0; i < node->numNeighbors; i++) {
        processed_nodes[node->val]->neighbors[i] = copy_node(node->neighbors[i], processed_nodes);
    }

    return processed_nodes[node->val];
}

struct Node *cloneGraph(struct Node *s) {
	if (s == NULL) {
        return NULL;
    }

    struct Node *processed_nodes[101] = {NULL};

    return copy_node(s, processed_nodes);
}
