//给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
//注意：请不要在超过该数组长度的位置写入元素。
//要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

///////思路1：直接用额外的数组，然后再复制回来
#include "myhead.h"
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>res;
        int n = arr.size();
        int i = 0;
        int cnt = 0;
        while (cnt < n) {
            if (arr[i] == 0) {
                res.push_back(0);
                res.push_back(0);
                cnt += 2;
            }
            else {
                res.push_back(arr[i]);
                ++cnt;
            }
            ++i;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = res[i];
        }

    }
};


////思路二：不难发现，位置i左边有几个零，i就要向右移动几位，因为左边的零个数会翻倍
//知道左边零的个数，就能知道最终会落在哪里
//原地修改需要注意的点：
//如果正序遍历，把数字向右覆盖，会导致后面的的数还没遍历到，就被覆盖了
//使用倒序遍历可避免这一点，向右覆盖的都是已经遍历过的数

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        // 先统计零的总数
        for (auto k : arr) {
            if (k == 0) ++cnt;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] == 0) --cnt; // 碰到零就减去，剩余的就是左边零的个数
            if (i + cnt < n) {
                arr[i + cnt] = arr[i]; // A[i] 向右移动 cnt0 位
                if (arr[i] == 0 && cnt + i + 1 < n) {
                    arr[i + cnt + 1] = 0; // 如果 A[i] 是零，移动完之后，后面还要补个零
                }
            }
        }

    }
};