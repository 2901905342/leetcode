//�������� n����˳���ӡ���� 1 ������ n λʮ��������
//�������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

///////��ģ��
#include "myhead.h"
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int count = 0;  //�洢����nλ��
        int i = 9;
        while (n) {
            count += i;
            i *= 10;
            n--;
        }
        for (int i = 1; i <= count; i++) {
            res.push_back(i);
        }
        return res;
    }
};