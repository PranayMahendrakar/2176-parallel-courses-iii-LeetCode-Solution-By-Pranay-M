class Solution {
    public:
        int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
                vector<vector<int>> graph(n + 1);
                        vector<int> indegree(n + 1, 0), dist(n + 1, 0);
                                for (auto& r : relations) {
                                            graph[r[0]].push_back(r[1]);
                                                        indegree[r[1]]++;
                                                                }
                                                                        queue<int> q;
                                                                                for (int i = 1; i <= n; i++) {
                                                                                            if (indegree[i] == 0) {
                                                                                                            q.push(i);
                                                                                                                            dist[i] = time[i - 1];
                                                                                                                                        }
                                                                                                                                                }
                                                                                                                                                        while (!q.empty()) {
                                                                                                                                                                    int u = q.front(); q.pop();
                                                                                                                                                                                for (int v : graph[u]) {
                                                                                                                                                                                                dist[v] = max(dist[v], dist[u] + time[v - 1]);
                                                                                                                                                                                                                if (--indegree[v] == 0) q.push(v);
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            return *max_element(dist.begin(), dist.end());
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                };