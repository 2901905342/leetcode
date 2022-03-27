//��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣
//���磬ԭ���� nums = [0, 1, 4, 4, 5, 6, 7] �ڱ仯����ܵõ���
//����ת 4 �Σ�����Եõ�[4, 5, 6, 7, 0, 1, 4]
//����ת 7 �Σ�����Եõ�[0, 1, 4, 4, 5, 6, 7]
//ע�⣬����[a[0], a[1], a[2], ..., a[n - 1]] ��תһ�� �Ľ��Ϊ����[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] ��
//����һ�����ܴ��� �ظ� Ԫ��ֵ������ nums ��
//��ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�� ��

#include "myhead.h"

/// <summary>
/// /////////˼·1��ֱ�����������һ��������ʱ�临�Ӷ�o��nlogn)
/// </summary>
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


///////���ף� ��������ʱ��O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return nums[i];  //�����ٽ��
        }
        return nums[0];  //û���ٽ��˵��������������������
    }
};


///����:���ֲ��ҽ�ϱ�������ʱ�� 0(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else  right--;
        }
        return nums[left];
    }
};