// Note -> If we want to store more than 2 values, then instead of using pair<int,pair<int,int>> -> we can use struct and store as many variables as we want in that.
struct triplet{
  int x, y, k;  
};
class Solution {
public:

    vector<int> delx = {0, 0, -1, 1};
    vector<int> dely = {-1, 1, 0, 0};
    
    bool isValid(int x, int y, vector<vector<int>> &grid){
        int row = grid.size();
        int col = grid[0].size();
        if(x<0 || y<0 || x>=row || y>=col)
            return false;
        return true;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int row = grid.size(), col = grid[0].size();
        queue<triplet> q;
        q.push({0,0,k});
        int steps = 0;
        unordered_set<string> visited;

        while(!q.empty()){
            int queueSize = q.size();

            while(queueSize--){
                triplet cell = q.front();
                int x = cell.x;
                int y = cell.y;
                int k = cell.k;
                q.pop();
                if(x == row-1 && y==col-1)
                    return steps;
                for(int i=0; i<delx.size(); i++){
                    int adjx = x + delx[i];
                    int adjy = y + dely[i];
                    if(isValid(adjx, adjy, grid)){
                        int newk = k - grid[adjx][adjy];
                        // Note -> state is basically working as visited.
                        string state = to_string(adjx)+","+to_string(adjy)+","+to_string(newk);
                        if(newk>=0 and visited.find(state) == visited.end()){
                            q.push({adjx, adjy, newk});
                            visited.insert(state);
                        }
                    }
                }
            }
            // Note -> Basically step is the no of levels.
            steps++;
        }
        return -1;
    }
};

Approach
--------
1. Since we have to find the shortest path, Hence, we are using bfs.
2. Here we are storing k for each cell.
3. In this question, only visited[i][j] will not work -> you will have to store visited[i][j][k] (otherwise tle will come).
  For that purpose I have used ( string state = to_string(adjx)+","+to_string(adjy)+","+to_string(newk) ) -> this is same as visited[i][j][k]
4. Our final answer will be the no of level if we will be able to reach till (row-1)(col-1), otherwise -1.


Time Complexity
O(m*n*k) time complexity
This is because for every cell (m*n), in the worst case we have to put that cell into the queue/bfs k times.
  
Space Complexity
O(m*n*k) space complexity
This is because for every cell (m*n), in the worst case we have to put that cell into the queue/bfs k times 
which means we need to worst case store all of those steps/paths in the visited set.

  
  
  
  
  
