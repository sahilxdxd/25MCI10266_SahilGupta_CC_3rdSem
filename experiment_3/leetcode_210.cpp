class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        int cnt = 0;

        while(!q.empty()) {

            int currNode = q.front();
            q.pop();

            cnt++;
            ans.push_back(currNode);

            for(int adj_node : adj[currNode]) {

                inDegree[adj_node]--;

                if(inDegree[adj_node] == 0) {
                    q.push(adj_node);
                }
            }
        }

        // Cycle exists
        if(cnt != numCourses) {
            return {};
        }

        return ans;
    }
};
