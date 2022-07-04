//给你个整数数组 arr，其中每个元素都 不相同。
//请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

//思路：排序+一次遍历
#include "myhead.h"
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int tmin = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            int x = arr[i] - arr[i - 1];
            if (x == tmin) res.push_back({ arr[i - 1],arr[i] });
            if (x < tmin) {
                res.clear();
                res.push_back({ arr[i - 1],arr[i] });
                tmin = x;
            }

        }
        return res;
    }
};