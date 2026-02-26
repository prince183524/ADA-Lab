#include <iostream>
using namespace std;

#define V 5

int minDistance(int dist[], bool visited[]) {
    int min = 9999, min_index;

    for (int i = 0; i < V; i++) {
        if (visited[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = 9999;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != 9999 &&
                dist[u] + graph[u][v] < dist[v]) {
                    
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int graph[V][V];

    cout << "Enter the adjacency matrix (5x5):\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter source vertex (0 to 4): ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}