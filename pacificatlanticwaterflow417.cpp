#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        deque<vector<int>> queue;
        vector<vector<bool>> atlantic, pacific; 
        atlantic = pacific =  vector<vector<bool>>(m, vector<bool>(n, false));
        //Multi source BFS for pacific ocean
        //Iniitialization
        for (int i = 0; i < m; i++) {
            vector<int> node = {i, 0, heights[i][0]};
            pacific[i][0] = true;
            queue.push_back(node);
        }
        for (int i = 1; i < n; i++) {
            vector<int> node = {0, i, heights[0][i]};
            pacific[0][i] = true;
            queue.push_back(node);
        }
        //Run BFS
        while (!queue.empty()) {
            vector<int> node = queue.front();
            queue.pop_front();
            vector<vector<int>> idx = {{0, -1}, {0,1}, {1, 0}, {-1,0}};
            for(int i = 0; i < idx.size(); i++) {
                    int posRow = node[0] + idx[i][0], posCol = node[1] + idx[i][1], val = node[2];
                    if (posRow < m && posRow >=0 && posCol >=0 && posCol < n && (pacific[posRow][posCol] != true) && (val <= heights[posRow][posCol])) {
                        pacific[posRow][posCol] = true;
                        vector<int> newNode = {posRow, posCol, heights[posRow][posCol]};
                        queue.push_back(newNode);
                    }
                
            }
        }
        //Multi source BFS for atlantic
        for (int i = 0; i < m; i++) {
            vector<int> node = {i, n-1, heights[i][n-1]};
            atlantic[i][n-1] = true;
            queue.push_back(node);
        }
        for (int i = 0; i < n-1; i++) {
            vector<int> node = {m-1, i, heights[m-1][i]};
            atlantic[m-1][i] = true;
            queue.push_back(node);
        }
        //Run BFS
        while (!queue.empty()) {
            vector<int> node = queue.front();
            queue.pop_front();
            vector<vector<int>> idx = {{0, -1}, {0,1}, {1, 0}, {-1,0}};
            for(int i = 0; i < idx.size(); i++) {
                    int posRow = node[0] + idx[i][0], posCol = node[1] + idx[i][1], val = node[2];
                    if (posRow < m && posRow >=0 && posCol >=0 && posCol < n && atlantic[posRow][posCol] != true && val <= heights[posRow][posCol]) {
                        atlantic[posRow][posCol] = true;
                        vector<int> newNode = {posRow, posCol, heights[posRow][posCol]};
                        queue.push_back(newNode);
                    }
                }
            
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

//Alternative
// class Solution {
// public:
//     int m, n;
//     vector<vector<int> > ans;
//     vector<vector<bool> > atlantic, pacific;
//     queue<pair<int, int> > q;
//     vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
//         if(!size(mat)) return ans;
//         m = size(mat), n = size(mat[0]);
//         atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
//         for(int i = 0; i < m; i++) bfs(mat, pacific, i, 0), bfs(mat, atlantic, i, n - 1);
//         for(int i = 0; i < n; i++) bfs(mat, pacific, 0, i), bfs(mat, atlantic, m - 1, i);             
//         return ans;
//     }
//     void bfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
//         q.push({i, j});
//         while(!q.empty()){
//             tie(i, j) = q.front(); q.pop();
//             if(visited[i][j]) continue;
//             visited[i][j] = true;
//             if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
//             if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) q.push({i + 1, j});
//             if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) q.push({i - 1, j});
//             if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) q.push({i, j + 1});
//             if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) q.push({i, j - 1});
//         }
//     }
// };