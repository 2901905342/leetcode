//用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。
//箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。
//将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
//将球导向左侧的挡板跨过右上角和左下角，在网格中用 - 1 表示。
//在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。
//如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。
//返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，
//如果球卡在盒子里，则返回 - 1 。

/////思路：简单模拟+有限状态机
// state一共有四个状态,'r','l','d'还有'o',分别代表向右向左向下以及停留在原地
//下一状态next_state由当前状态state和当前网格挡板的朝向决定
#include "myhead.h"
class Solution {
public:
    char change(char state, int& flag) {
        if (state == 'd') return flag > 0 ? 'r' : 'l';
        if (state == 'r') return flag > 0 ? 'd' : 'o';
        if (state == 'l') return flag > 0 ? 'o' : 'd';
        return 'o';
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x = i;
            int y = 0;
            char state = 'd';
            while (1) {
                if (x < 0 || x >= n) {
                    res.push_back(-1);
                    break;
                }
                else if (y == m) {
                    res.push_back(x);
                    break;
                }
                char next_state = change(state, grid[y][x]);
                state = next_state;  //这里不能写成一行char state=change(state,grid[y][x])否则会使得state一直为'o'
                if (state == 'o') {
                    res.push_back(-1);
                    break;
                }
                else if (state == 'r') x++;
                else if (state == 'l') x--;
                else y++;
            }
        }
        return res;
    }
};