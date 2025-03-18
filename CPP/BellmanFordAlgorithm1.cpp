#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void bellmanFord(int graph[][3], int V, int E, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[graph[j][0]] != INT_MAX && 
                dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]]) {
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int graph[][3] = { {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, 
                       {1, 3, 2}, {1, 4, 2}, {3, 2, -2}, 
                       {4, 3, -3}, {4, 2, 3} };
    
    int V = sizeof(graph) / sizeof(graph[0]);
    bellmanFord(graph, V + 1 , sizeof(graph)/sizeof(graph[0]), 0);
    
    return 0;
}
