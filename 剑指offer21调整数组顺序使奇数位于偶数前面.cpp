//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����������������ǰ�벿�֣�����ż��������ĺ�벿�֡�
///˼·��˫ָ��
#include "myhead.h"
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            while (nums[left] % 2 && left < right) {
                left++;
            }
            while (nums[right] % 2 == 0 && left < right) {
                right--;
            }
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
    }
};