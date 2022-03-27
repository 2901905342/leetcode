//����һ���������� nums ���������Ǵ��� Ψһ�� һ��������� ��
//�����ҳ������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ��
//����ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� - 1 ��
#include "myhead.h"

////////////////////////����  ��hash������¼���ֵ��λ�ã�����ʱ��8ms
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)  return 0;
        unordered_map<int, int> hash;
        int temp = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (temp < nums[i]) {
                hash[nums[i]] = i;
                temp = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        int num2 = 2 * nums[nums.size() - 2];
        if (temp < num2) return -1;
        else  return hash[temp];
    }
};

/// <summary>
/// //////////////////�ٰ�  ��������Ҫʹ����������ʡ�´���ʱ�䣬����0ms
/// </summary>
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)  return 0;
        int temp = -1;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (temp < nums[i]) {
                index = i;
                temp = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        int num2 = 2 * nums[nums.size() - 2];
        if (temp < num2) return -1;
        else  return index;
    }
};

/// <summary>
/// /////////////////�ٷ�д������ʱӦ������̵�
/// </summary>

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1 = -1, m2 = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                index = i;
            }
            else if (nums[i] > m2) {
                m2 = nums[i];
            }
        }
        return m1 >= m2 * 2 ? index : -1;
    }
};

