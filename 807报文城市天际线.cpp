//给你一座由 n x n 个街区组成的城市，每个街区都包含一座立方体建筑。给你一个下标从 0 开始的 n x n 整数矩阵 grid ，其中 grid[r][c] 表示坐落于 r 行 c 列的建筑物的 高度 。
//城市的 天际线 是从远处观察城市时，所有建筑物形成的外部轮廓。从东、南、西、北四个主要方向观测到的 天际线 可能不同。
//我们被允许为 任意数量的建筑物 的高度增加 任意增量（不同建筑物的增量可能不同） 。 高度为 0 的建筑物的高度也可以增加。然而，增加的建筑物高度 不能影响 从任何主要方向观察城市得到的 天际线 。
//在 不改变 从任何主要方向观测到的城市 天际线 的前提下，返回建筑物可以增加的 最大高度增量总和 。


#include "myhead.h"
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <int> MAXhang(n);//构造函数初始化，n个0元素
        vector <int> MAXlie(n);//
        //vector <int> a;  默认不进行初始化
        //vector <int> a(n);  构造函数初始化，n个值为0的元素
        //vector <int> a(n,val);   构造函数初始化，n个值为val的元素
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                MAXhang[i] = max(MAXhang[i], grid[i][j]);//存储每行的最大值
                MAXlie[j] = max(MAXlie[j], grid[i][j]);  //存储每列的最大值
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(MAXhang[i], MAXlie[j]) - grid[i][j];
            }
        }
        return res;
    }
};