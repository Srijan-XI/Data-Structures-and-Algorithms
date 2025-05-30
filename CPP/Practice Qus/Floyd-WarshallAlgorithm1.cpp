#include <iostream>
#include <limits.h>

#define VERTICES_COUNT 4
#define INF INT_MAX

using namespace std;

void floydWarshall(int graph[VERTICES_COUNT][VERTICES_COUNT]) {
    int dist[VERTICES_COUNT][VERTICES_COUNT];

    for (int i = 0; i < VERTICES_COUNT; i++)
        for (int j = 0; j < VERTICES_COUNT; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < VERTICES_COUNT; k++) {
        for (int i = 0; i < VERTICES_COUNT; i++) {
            for (int j = 0; j < VERTICES_COUNT; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < VERTICES_COUNT; i++) {
        for (int j = 0; j < VERTICES_COUNT; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[VERTICES_COUNT][VERTICES_COUNT] = { {0,   INF, -2, INF},
                                                  {4,   0,   INF, INF},
                                                  {INF, -1 ,   0 , INF},
                                                  {INF , INF , -3 ,   0} };

    floydWarshall(graph);
    
    return 0;
}
