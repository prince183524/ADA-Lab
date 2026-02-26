#include <iostream>
using namespace std;

#define V 4
#define E 5

struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    int u_set = find(u);
    int v_set = find(v);
    parent[u_set] = v_set;
}

void sortEdges(Edge edges[]) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskalMST(Edge edges[]) {
    sortEdges(edges);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < E; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            cout << edges[i].src << " - " << edges[i].dest
                 << " : " << edges[i].weight << endl;
            unionSet(u, v);
        }
    }
}

int main() {
    Edge edges[E];

    cout << "Enter source, destination and weight for 5 edges:\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges);

    return 0;
}