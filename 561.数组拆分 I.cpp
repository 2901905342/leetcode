//��������Ϊ 2n ���������� nums ����������ǽ���Щ���ֳ� n ��, ����(a1, b1), (a2, b2), ��,
//(an, bn) ��ʹ�ô� 1 �� n �� min(ai, bi) �ܺ����
//���ظ� ����ܺ�

//����ÿ������������ֻ��ѡ��ǰС��һ�������ۼӡ�
//������ǲ���Ӧ�ôӵ�һ��λ�ý���ѡ��Ȼ���һ��ѡ����һ�����������γɵ����е����ֵ���

#include "myhead.h"
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        for (int i = 1; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};