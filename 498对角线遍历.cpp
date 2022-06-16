/*给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素*/
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 104
//1 <= m * n <= 104
//- 105 <= mat[i][j] <= 105

//思路：
//根据题意进行模拟即可。
//当前所在位置为(x, y)，遍历方向使用 dir 代指（当 dir = 1 代表往右上方进行遍历，当 dir = -1 代表往左下方进行遍历），使用 idx记录当前处理到的答案下标。
//每次除了将当前格子放入答案（ans[idx++] = g[x][y]）以外，还需要结合 dir 找到当前位置的右上方格子(x−1, y + 1) 或是左下方格子(x + 1, y−1)，
//若下一目标位置「越界」并且还没搜索完整个矩阵，我们需要根据优先级来找「下一个发起点」的位置，并且翻转遍历方向。
//具体的找「下一个发起点」的优先级为：
//若当前遍历方向为往右上角，即 dir = 1，优先找(x, y + 1)作为下一发起点，若越界，则找(x + 1, y) 作为下一发起点；
//若当前遍历方向为往左下角，即 dir = -1，优先找(x + 1, y) 作为下一发起点，若越界，则找(x, y + 1)(x, y + 1) 作为下一发起点。


#include "myhead.h"
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res;
        int x = 0;
        int y = 0;
        int m = mat.size();
        int n = mat[0].size();
        int cnt = m * n;
        int x_next;
        int y_next;
        int falgx = -1;
        int falgy = 1;
        while (cnt--) {
            res.push_back(mat[x][y]);
            x_next = x + falgx;
            y_next = y + falgy;
            if (y_next < 0 || y_next >= n || x_next < 0 || x_next >= m) {
                if (falgx == -1 && falgy == 1) {
                    if (y + 1 >= n) {
                        x_next = x + 1;
                        y_next = y;
                    }
                    else {
                        x_next = x;
                        y_next = y + 1;
                    }
                }
                else {
                    if (x + 1 >= m) {
                        x_next = x;
                        y_next = y + 1;
                    }
                    else {
                        x_next = x + 1;
                        y_next = y;
                    }
                }
                falgx *= -1;
                falgy *= -1;
            }
            x = x_next;
            y = y_next;
        }
        return res;

    }
};