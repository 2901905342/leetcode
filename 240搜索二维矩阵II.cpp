//编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
//每行的元素从左到右升序排列。
//每列的元素从上到下升序排列。

#include "myhead.h"

//////////////思路1： 直接在每行进行二分查找时间复杂度：O(mlogn)。
//对一行使用二分查找的时间复杂度为O(logn)，最多需要进行 m 次二分查找。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target)  left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};

/////////// 思路二：
//数组从左到右和从上到下都是升序的，如果从右上角出发开始遍历呢？
//会发现每次都是向左数字会变小，向下数字会变大，有点和二分查找树相似。
//二分查找树的话，是向左数字变小，向右数字变大。
//所以我们可以把 target 和当前值比较。
//如果 target 的值大于当前值，那么就向下走。
//如果 target 的值小于当前值，那么就向左走。
//如果相等的话，直接返回 true 。
//  时间复杂度  O(m+n)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        int m = matrix.size();
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};