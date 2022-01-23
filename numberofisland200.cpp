#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        deque<pair<int, int>> q;
        
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                pair<int, int> init = {i, j};
                q.push_back(init);
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> loc = q.front(); q.pop_front();
                    int x = loc.first, y = loc.second;
                    if (x-1 >= 0 && !visited[x-1][y] && grid[x-1][y]=='1') {
                        visited[x-1][y] = true;
                        q.push_back({x-1,y});
                    }
                    if (x+1 < m && !visited[x+1][y] && grid[x+1][y]=='1') {
                        visited[x+1][y] = true;
                        q.push_back({x+1,y});
                    }
                    if (y-1 >=0 && !visited[x][y-1] && grid[x][y-1]=='1') {
                        visited[x][y-1] = true;
                        q.push_back({x,y-1});
                    }
                    if (y+1 < n && !visited[x][y+1] && grid[x][y+1]=='1') {
                        visited[x][y+1] = true;
                        q.push_back({x,y+1});
                    }
                }
                count++;
            }
        }
        return count;
        
    }
};