class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = time[i];
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + time[v]);

                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
