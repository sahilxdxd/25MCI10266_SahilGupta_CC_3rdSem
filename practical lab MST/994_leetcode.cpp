class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue <pair<int,int>> q;
        int fresh = 0;

        for(int i=0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time =0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty() && fresh > 0){
            int size = q.size();
            while(size--){
                auto[r,c] = q.front();
                q.pop();

                for(int d=0; d < 4; d++){
                    int nr = r + dx[d];
                    int nc = c + dy[d];

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }
        if(fresh == 0)
            return time;
        else
            return -1;
    }
};
