//����һ������Ϊ n ���������� score ������ score[i] �ǵ� i λ�˶�Ա�ڱ����еĵ÷֡����е÷ֶ� ������ͬ ��
//
//�˶�Ա�����ݵ÷� �������� ���������ε� 1 ���˶�Ա�÷���ߣ����ε� 2 ���˶�Ա�÷ֵ� 2 �ߣ��������ơ��˶�Ա�����ξ��������ǵĻ������
//
//���ε� 1 ���˶�Ա����� "Gold Medal" ��
//���ε� 2 ���˶�Ա������ "Silver Medal" ��
//���ε� 3 ���˶�Ա��ͭ�� "Bronze Medal" ��
//�����ε� 4 ���� n ���˶�Ա��ֻ�ܻ�����ǵ����α�ţ��������ε� x ���˶�Ա��ñ�� "x"����
//ʹ�ó���Ϊ n ������ answer ���ػ񽱣����� answer[i] �ǵ� i λ�˶�Ա�Ļ������



#include "myhead.h"


//����һ  ����
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order;
        for (int i = 0; i < nums.size(); i++)
            order.push_back(i);
        sort(order.begin(), order.end(), [&nums](const int& a, const int& b) {return nums[a] > nums[b]; });
        vector<string> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            switch (i)
            {
            case 0:res[order[i]] = "Gold Medal"; break;
            case 1:res[order[i]] = "Silver Medal"; break;
            case 2:res[order[i]] = "Bronze Medal"; break;
            default:res[order[i]] = to_string(i + 1); break;
            }
        }
        return res;
    }
};

//������  hash��