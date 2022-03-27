//����һ���������� nums ��
//������ΨһԪ������Щֻ���� ǡ��һ�� ��Ԫ�ء�
//���㷵�� nums ��ΨһԪ�ص� �� ��
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
/////˼·����ϣ����Ҫע��ͳ��Ԫ�س��ֵĴ���
/// ע��ٷ���д��

#include "myhead.h"
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> hash_table(101, 0);  //����������ϣ��
        for (int num : nums) {
            hash_table[num]++;
        }
        int res = 0;
        for (int num : nums) {
            if (hash_table[num] == 1) res += num;
        }
        return res;
    }
};

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num]; //�����д��������˼
        }
        int ans = 0;
        for (auto& it : cnt) {
            if (it.second == 1) {
                ans += it.first; //ע�������д��
            }
        }
        return ans;
    }
};

