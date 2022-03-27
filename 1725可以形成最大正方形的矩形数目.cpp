//给你一个数组 rectangles ，其中 rectangles[i] = [li, wi] 表示第 i 个矩形的长度为 li 、宽度为 wi 。
//如果存在 k 同时满足 k <= li 和 k <= wi ，就可以将第 i 个矩形切成边长为 k 的正方形。
//例如，矩形[4, 6] 可以切成边长最大为 4 的正方形。
//设 maxLen 为可以从矩形数组 rectangles 切分得到的 最大正方形 的边长。
//请你统计有多少个矩形能够切出边长为 maxLen 的正方形，并返回矩形 数目 。

////////思路：简单模拟
#include "myhead.h"
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> temp;
        int maxLen = 0;
        int res = 0;
        for (auto rec : rectangles) {
            int rlen = min(rec[0], rec[1]);
            if (maxLen < rlen) {
                maxLen = rlen;
                res = 1;
            }
            else if (maxLen == rlen) res++;
        }
        return res;
    }
};