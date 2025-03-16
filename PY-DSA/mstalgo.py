class DSU:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0]*size
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)
        
        if xroot == yroot:
            return
        
        if self.rank[xroot] < self.rank[yroot]:
            self.parent[xroot] = yroot
        else:
            self.parent[yroot] = xroot
            if self.rank[xroot] == self.rank[yroot]:
                self.rank[xroot] += 1

def kruskal(edges, num_vertices):
    edges.sort(key=lambda x: x[2])
    dsu = DSU(num_vertices)
    mst = []
    
    for u, v, w in edges:
        if dsu.find(u) != dsu.find(v):
            mst.append((u, v, w))
            dsu.union(u, v)
            if len(mst) == num_vertices-1:
                break
    return mst

# Example usage
edges = [(0,1,10), (0,2,6), (0,3,5), (1,3,15), (2,3,4)]
print("MST:", kruskal(edges, 4))  # Output: [(2,3,4), (0,3,5), (0,1,10)]
