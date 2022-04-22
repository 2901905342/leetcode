//给定一个长度为 n 的整数数组 nums 。
//假设 arrk 是数组 nums 顺时针旋转 k 个位置后的数组，我们定义 nums 的 旋转函数  F 为：
//F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]
//返回 F(0), F(1), ..., F(n - 1)中的最大值 。
//生成的测试用例让答案符合 32 位 整数。
//n == nums.length
//1 <= n <= 105
//- 100 <= nums[i] <= 100


//思路：求出一个Fi,则下一个F(i+1)=F(i)-all+nums[i]*n;其中 all 为nums的元素和
// 取F(i)中最大的一个，时间复杂度O(N）

#include "myhead.h"
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int all = 0;
        int maxt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            all += nums[i];
            maxt += i * nums[i];
        }
        int res = maxt;
        int temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = maxt - all + nums[i] * n;
            res = max(res, temp); 
            maxt = temp;
        }
        return res;
    }
};