//你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m* n 的网格 grid 进行了标注。
//每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
//为了使收益最大化，矿工需要按以下规则来开采黄金：
//每当矿工进入一个单元，就会收集该单元格中的所有黄金。
//矿工每次可以从当前位置向上下左右四个方向走。
//每个单元格只能被开采（进入）一次。
//不得开采（进入）黄金数目为 0 的单元格。
//矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。

#include "myhead.h"
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y]) return 0;
        int temp = grid[x][y];
        grid[x][y] = 0; //标记走过的格子，避免重复走
        int res = max(max(dfs(x + 1, y, grid), dfs(x - 1, y, grid)), max(dfs(x, y + 1, grid), dfs(x, y - 1, grid)));
        grid[x][y] = temp;  //回溯，撤销处理节点
        return res + temp;
    };

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> hash(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j, grid)); //多源dfs
                }
            }
        }
        return ans;
    }
};