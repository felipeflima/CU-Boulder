class Graph(): 

    def __init__(self, adjacency_matrix): 
        self.size = len(adjacency_matrix)
        self.graph = adjacency_matrix
	
    def findMinKey(self, key, tree_check): 
        min = float('inf')
        for i in range(self.size): 
            if tree_check[i] == False and key[i] < min:
                min_index = i 
                min = key[i] 
        return min_index 

    def Prim(self): 

        key = [float('inf')] * self.size
        parent = [None] * self.size 
        key[0] = 0
        tree_check = [False] * self.size 
        weight_total = 0
        parent[0] = -1

        for c in range(self.size): 
            u = self.findMinKey(key, tree_check) 
            tree_check[u] = True
            for v in range(self.size): 
                if self.graph[u][v] > 0 and tree_check[v] == False and self.graph[u][v] < key[v]: 
                        key[v] = self.graph[u][v] 
                        parent[v] = u 

        for i in range(1, self.size): 
            weight_total += self.graph[i][ parent[i] ] 
        return weight_total

G = Graph([[0, 10, 11, 33, 60],
           [10, 0, 22, 14, 57],
           [11, 22, 0, 11, 17],
           [33, 14, 11, 0, 9],
           [60, 57, 17, 9, 0]])

print (G.Prim())