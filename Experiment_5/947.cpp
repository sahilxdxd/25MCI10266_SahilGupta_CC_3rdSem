class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones, vector<bool>& vis) {
        vis[node] = true;

        for (int j = 0; j < stones.size(); j++) {
            if (!vis[j] &&
                (stones[node][0] == stones[j][0] ||
                 stones[node][1] == stones[j][1])) {
                dfs(j, stones, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, stones, vis);
            }
        }

        return n - components;
    }
};
