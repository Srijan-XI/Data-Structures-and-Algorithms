<<<<<<< HEAD
import sys

def prim_mst(graph):
    V = len(graph)
    key = [sys.maxsize] * V
    parent = [-1] * V
    key[0] = 0
    mst_set = [False] * V
    
    for _ in range(V):
        u = min((val, idx) for idx, val in enumerate(key) if not mst_set[idx])[1]
        mst_set[u] = True
        
        for v in range(V):
            if graph[u][v] > 0 and not mst_set[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u
    
    total = 0
    for i in range(1, V):
        total += graph[i][parent[i]]
    return total

# Example usage
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]
print("MST Weight:", prim_mst(graph))  # Output: 16
=======
import sys

def prim_mst(graph):
    V = len(graph)
    key = [sys.maxsize] * V
    parent = [-1] * V
    key[0] = 0
    mst_set = [False] * V
    
    for _ in range(V):
        u = min((val, idx) for idx, val in enumerate(key) if not mst_set[idx])[1]
        mst_set[u] = True
        
        for v in range(V):
            if graph[u][v] > 0 and not mst_set[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u
    
    total = 0
    for i in range(1, V):
        total += graph[i][parent[i]]
    return total

# Example usage
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]
print("MST Weight:", prim_mst(graph))  # Output: 16
>>>>>>> bc7dcdb (Initial commit)
