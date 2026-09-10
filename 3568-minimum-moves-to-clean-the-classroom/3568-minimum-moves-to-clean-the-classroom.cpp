class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        // Find starting point and all litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // Every litter is represented by one bit
        // mask = 0 means all litter is collected
        int fullMask = (1 << k) - 1;

        // dist[r][c][energy][mask]
        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    energy + 1, vector<int>(1 << k, -1)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        // Initially no litter is collected
        int startMask = fullMask;

        // If S itself were litter (not normally possible), handle it
        for (int i = 0; i < k; i++) {
            if (litter[i].first == sr && litter[i].second == sc) {
                startMask &= ~(1 << i);
            }
        }

        dist[sr][sc][energy][startMask] = 0;
        q.push({sr, sc, energy, startMask});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask] = q.front();
            q.pop();

            int moves = dist[r][c][e][mask];

            // All litter collected
            if (mask == 0) {
                return moves;
            }

            // No energy -> cannot make another move
            if (e == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside classroom
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Wall
                if (classroom[nr][nc] == 'X')
                    continue;

                int ne = e - 1;

                // Recharge at R
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                int nmask = mask;

                // If we reach a litter, collect it
                for (int i = 0; i < k; i++) {
                    if (litter[i].first == nr &&
                        litter[i].second == nc) {
                        
                        nmask &= ~(1 << i);
                    }
                }

                if (dist[nr][nc][ne][nmask] == -1) {
                    dist[nr][nc][ne][nmask] = moves + 1;
                    q.push({nr, nc, ne, nmask});
                }
            }
        }

        return -1;
    }
};