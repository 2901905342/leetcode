//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
//nums Ϊ���ظ�Ԫ�ص�������������

///////////˼·�� ���͵Ķ��ֲ��ң��ȴ���߽�����
#include "myhead.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (target > nums[right]) return right + 1;
        if (target < nums[0]) return 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;

    }
};