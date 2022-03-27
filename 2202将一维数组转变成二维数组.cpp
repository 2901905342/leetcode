//给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。
//original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。
//请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

///////思路：简单模拟，注意i,j遍历时的取值//////////////

#include "myhead.h"
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int osize = m * n;
        vector<vector<int>> res;
        vector<int> temp;
        if (original.size() != osize) return res;
        for (int i = 0; i < original.size(); i += n) {
            for (int j = i; j < i + n; j++) {
                temp.push_back(original[j]);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};