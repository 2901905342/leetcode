//珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。
//警卫已经离开了，将在 h 小时后回来。
//珂珂可以决定她吃香蕉的速度 k （单位：根 / 小时）。
//每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
//珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
//返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。

//如果珂珂在 hh 小时内吃掉所有香蕉的最小速度是每小时 kk 个香蕉，
//则当吃香蕉的速度大于每小时 kk 个香蕉时一定可以在 hh 小时内吃掉所有香蕉，
//当吃香蕉的速度小于每小时 kk 个香蕉时一定不能在 hh 小时内吃掉所有香蕉。
//由于吃香蕉的速度和是否可以在规定时间内吃掉所有香蕉之间存在单调性，
//因此可以使用二分查找的方法得到最小速度 kk。

//1 <= piles.length <= 104
//piles.length <= h <= 109
//1 <= piles[i] <= 109

//最难想到的是由于每小时都要吃香蕉，即每小时至少吃 1个香蕉，因此二分查找的下界是 1；

#include "myhead.h"
class Solution {
public:
    bool  minnum(vector<int>& piles, int target, int h) {
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] <= target) h--;
            else {
                if (piles[i] % target == 0) h -= piles[i] / target;
                else  h -= piles[i] / target + 1;
            }
            if (h < 0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(),piles.end());
        int left = 1;
        int right = piles[0];
        int mid;
        for (int i = 0; i < piles.size(); i++) {
            right = max(right, piles[i]);
        }

        mid = (right - left) / 2 + left;
        while (left < right) {
            if (minnum(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
            mid = (right - left) / 2 + left;
        }
        return right;
    }
};