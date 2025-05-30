#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int minDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[6][6], int src) {
    int dist[6];
    bool visited[6];

    for (int i = 0; i < 6; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < 5; count++) {
        int u = minDistance(dist, visited, 6);
        visited[u] = true;

        for (int v = 0; v < 6; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < 6; i++) {
        char ver = 'A' + i;
        cout << ver << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int graph[6][6] = { {0, 1, 2, 0, 0, 0},
                        {1, 0, 1, 0, 3, 0},
                        {2, 1, 0, 2, 2, 0},
                        {0, 0, 2, 0, 1, 1},
                        {0, 3, 2, 1, 0, 2},
                        {0, 0, 0, 1, 2, 0} };
    
    dijkstra(graph, 0);
    return 0;
}
