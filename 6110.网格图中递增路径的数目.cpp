//给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。
//请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。
//由于答案可能会很大，请将结果对 109 + 7 取余 后返回。
//如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。

///思路：记忆化搜索
//记录 f(i, j) 表示以(i, j) 为结尾的不同路径有几条。
//计算 f(i, j) 时，检查(i, j)上下左右四个格子，若相邻格子里的数比当前格子里的数小，则可以转移给 f(i, j)。
//当然别忘了计算从(i, j) 开始，然后直接在(i, j)结束的路径，也就是 f(i, j)f(i, j) 还要再加 1。
//用记忆化搜索即可在O(nm) 的复杂度内完成。



#include "myhead.h"
class Solution {
public:
    vector<vector<int>>dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int mod = 1000000000 + 7;
    int m;
    int n;
    int dp(int row, int col, vector<vector<int>>& grid, vector<vector<long long>>& temp) {
        if (temp[row][col] > 0) return temp[row][col];
        temp[row][col]++;
        for (int i = 0; i < 4; i++) {
            int nextrow = row + dir[i][0];
            int nextcol = col + dir[i][1];
            if (nextrow >= 0 && nextrow < m && nextcol >= 0 && nextcol < n && grid[nextrow][nextcol] < grid[row][col]) {
                temp[row][col] = (temp[row][col] + dp(nextrow, nextcol, grid, temp)) % mod;
            }
        }
        return temp[row][col];

    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        long long cnt = 0;
        vector<vector<long long>>temp(m, vector<long long>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp(i, j, grid, temp);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt = (cnt + dp(i, j, grid, temp)) % mod;
            }
        }
        return cnt % mod;

    }
};
