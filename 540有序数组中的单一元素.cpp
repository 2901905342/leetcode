//给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
//请你找出并返回只出现一次的那个数。
//你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

////////思路：其实看到 O(log n) 就想到二分法，看到每个元素都会出现两次，唯有一个数只会出现一次就联想到异或
/////但是二分法实在不会写，就写了一遍遍历 O(n) 
#include "myhead.h"
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        if (nums.size() == 1) return res;
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

/// <summary>
/// 官方写法，二分查找
/// </summary>
/// 这道题的「二段性」分析需要一点点「脑筋急转弯」。
//由于给定数组有序 且 常规元素总是两两出现，因此如果不考虑“特殊”的单一元素的话，
//我们有结论：成对元素中的第一个所对应的下标必然是偶数，成对元素中的第二个所对应的下标必然是奇数。
//然后再考虑存在单一元素的情况，假如单一元素所在的下标为 x，那么下标 x 之前（左边）的位置仍满足上述结论，
//而下标 xx 之后（右边）的位置由于 xx 的插入，导致结论翻转。
//存在这样的二段性，指导我们根据当前二分点 mi 的奇偶性进行分情况讨论：
//midmid 为偶数下标：根据上述结论，正常情况下偶数下标会与下一值相同，因此如果满足该条件，可以确保 midmid 之前并没有插入单一元素。
//正常情况下，此时应该更新 l = mid，否则应当让 r = mid - 1，但需要注意这样的更新逻辑，会因为更新 r 时否决 mid而错过答案，
//我们可以将否决 mid的动作放到更新 ll的一侧，即需要将更新逻辑修改为 l = mid + 1 和r = mid ；
//mid为奇数下标：同理，根据上述结论，正常情况下偶数下标会与上一值相同，
//因此如果满足该条件，可以确保 mid 之前并没有插入单一元素，相应的更新 l 和 r。
//利用按位异或的性质，可以得到 mid 和相邻的数之间的如下关系，其中 ⊕ 是按位异或运算符：
//当 mid 是偶数时，mid + 1 = mid⊕1；
//当 mid 是奇数时，1mid−1 = mid⊕1。
//因此在二分查找的过程中，不需要判断mid 的奇偶性，mid 和 mid⊕1 即为每次需要比较元素的两个下标。

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};


