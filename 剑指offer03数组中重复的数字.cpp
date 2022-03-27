//�ҳ��������ظ������֡�
//��һ������Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�

///////˼·��  ����������hash��
////����ʹ��set������hash��
///��һ���Ż������ڳ���Ϊ n ������ nums ����������ֶ��� 0��n - 1 �ķ�Χ�ڣ�����������hash��������������


#include "myhead.h"
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hash;  //ʹ��ununordered_set��ʹ��set��ʱҪ�ٺܶ�
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i])) return nums[i];
            hash.insert(nums[i]);
        }
        return -1;
    }
};

//���Ż��� ��˵�����壺����Ԫ�ص� ���� �� ֵ �� һ�Զ� �Ĺ�ϵ��
//��ˣ��ɱ������鲢ͨ������������ʹԪ�ص� ���� �� ֵ һһ��Ӧ���� nums[i] = i����
//���������ͨ������ӳ���Ӧ��ֵ�������ֵ�ȼ۵����á�
//�����У���һ���������� x ʱ�����佻�������� x ���������ڶ����������� x ʱ��һ���� nums[x] = x ��
//��ʱ���ɵõ�һ���ظ����֡�
//�㷨���̣�
//�������� nums ����������ʼֵΪ i = 0:
//�� nums[i] = i �� ˵�����������ڶ�Ӧ����λ�ã����轻�������������
//�� nums[nums[i]] = nums[i] �� �������� nums[i] �������� i ����Ԫ��ֵ��Ϊ nums[i] �����ҵ�һ���ظ�ֵ�����ش�ֵ nums[i] ��
//���� ��������Ϊ ii�� nums[i]��Ԫ��ֵ���������ֽ�������Ӧ����λ�á�
//�����������δ���أ��򷵻� - 1 ��


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

