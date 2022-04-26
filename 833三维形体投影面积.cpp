//在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。
//每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。
//现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。
//投影 就像影子，将 三维 形体映射到一个 二维 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。
//返回 所有三个投影的总面积 。

//思路：
//xy 平面的投影面积等于网格上非零数值的数目；
//yz 平面的投影面积等于网格上每一列最大数值之和；
//zx 平面的投影面积等于网格上每一行最大数值之和。
//返回上述三个投影面积之和。
#include "myhead.h"
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int up = 0;
        int right = 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            int temp1 = 0;
            int temp2 = 0;
            for (int j = 0; j < n; j++) {
                if (temp1 < grid[i][j]) temp1 = grid[i][j];
                if (temp2 < grid[j][i]) temp2 = grid[j][i];
                if (grid[i][j] != 0) up++;
            }
            right += temp1;
            left += temp2;
        }
        return up + right + left;
    }
};