//����һ������ num������ת��Ϊ 7 ���ƣ������ַ�����ʽ�����

/////˼·����7�����������Ƕ�num��7ȡ�࣬Ȼ��num=num/7�����ѭ��ֱ��num=0;��������ȡ��������
#include "myhead.h"
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return to_string(0);
        string negative;
        string res;
        if (num < 0) {
            num = -num;
            negative = '-';
        }
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        return negative + res;
    }
};