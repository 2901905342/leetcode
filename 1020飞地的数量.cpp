//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
//一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
//返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

////////////思路：多源DFS，我觉得我写的没有问题，但不知道为什么一直超时
#include "myhead.h"
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 0) return 0;
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) return 1;
        grid[x][y] = 0;  // 处理节点
        int flag = dfs(x + 1, y, grid) | dfs(x - 1, y, grid) | dfs(x, y - 1, grid) | dfs(x, y + 1, grid);
        grid[x][y] = 1; //回溯，撤销对节点的操作
        return flag;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!dfs(i, j, grid)) res++;
                }
            }
        }
        return res;

    }
};

//////////官方写法
//根据飞地的定义，如果从一个陆地单元格出发无法移动到网格边界，则这个陆地单元格是飞地。
//因此可以将所有陆地单元格分成两类：第一类陆地单元格和网格边界相连，这些陆地单元格不是飞地；
//第二类陆地单元格不和网格边界相连，这些陆地单元格是飞地。
//
//我们可以从网格边界上的每个陆地单元格开始深度优先搜索，遍历完边界之后，所有和网格边界相连的陆地单元格就都被访问过了。
//然后遍历整个网格，如果网格中的一个陆地单元格没有被访问过，则该陆地单元格不和网格的边界相连，是飞地。

class Solution {
public:
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));
        //只遍历边界的点
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        int enclaves = 0;
        ///只遍历内部的点
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }

    void dfs(const vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col]) {
            return;
        }
        visited[row][col] = true; //标记说明改点已经被访问过了
        for (auto& dir : dirs) { 
            dfs(grid, row + dir[0], col + dir[1]);//递归，四周的点
        }
    }
private:
    int m, n;
    vector<vector<bool>> visited;
};

///////////实际上官方的解题思路用BFS效果意外的好
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
        queue<pair<int, int>> duilie;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) {
                visited[i][0] = 1;
                duilie.push(make_pair(i, 0));
            }
            if (grid[i][n - 1]) {
                visited[i][n - 1] = 1;
                duilie.push(make_pair(i, n - 1));
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j]) {
                visited[0][j] = 1;
                duilie.push(make_pair(0, j));
            }
            if (grid[m - 1][j]) {
                visited[m - 1][j] = 1;
                duilie.push(make_pair(m - 1, j));
            }
        }
        while (!duilie.empty()) {
            auto p = duilie.front();
            duilie.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int next_x = dirs[i][0] + p.first;
                int next_y = dirs[i][1] + p.second;
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] && !visited[next_x][next_y]) {
                    duilie.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] && !visited[i][j]) res++;
            }
        }
        return res;
    }
};