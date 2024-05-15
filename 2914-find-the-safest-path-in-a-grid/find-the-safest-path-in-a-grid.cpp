class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Step 1: Calculate minimum distance to the nearest thief for each cell using BFS
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        vector<int> dir = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dir[k];
                int nc = c + dir[k + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] > dist[r][c] + 1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Use modified Dijkstra to find the path with the maximum safeness factor
        priority_queue<tuple<int, int, int>> pq; // (safeness factor, r, c)
        pq.push({dist[0][0], 0, 0});
        vector<vector<int>> maxSafeness(n, vector<int>(n, -1));
        maxSafeness[0][0] = dist[0][0];
        
        while (!pq.empty()) {
            auto [safeness, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return safeness;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dir[k];
                int nc = c + dir[k + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newSafeness = min(safeness, dist[nr][nc]);
                    if (newSafeness > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = newSafeness;
                        pq.push({newSafeness, nr, nc});
                    }
                }
            }
        }
        
        return -1; // If no path found, although problem guarantees a path exists
    }
};