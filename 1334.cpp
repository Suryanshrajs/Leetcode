class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Set the distance to itself to 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Fill the distance matrix with the given edges
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall algorithm to compute shortest paths between all pairs
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Find the city with the smallest number of neighbors within the distance threshold
    int minCount = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        // Check if we found a city with a smaller count or the same count but a larger city index
        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
    }
};
