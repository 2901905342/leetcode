//����һ������ n �����㷵������ 0 �� 1 ֮�䣨������ 0 �� 1�������ĸС�ڵ���  n �� ��� ���� ��
//���������� ���� ˳�򷵻ء�

/////˼·������ؼ�������������ԭ������ΪֻҪ��ĸ���ܱ������������У�����ʵ���ԣ�
// ���硰4/6���Ͳ��������������ɻ���Ϊ��2/3��
////��֤������������Ҫ���ӣ���ĸ�����Լ����greatest common divisor��gcd��Ϊ1��
//һ�����շת����������������ȡ�����ظ����������ֱ������Ϊ0ʱ��ǰһ��������Ϊ���Լ����

#include "myhead.h"
class Solution {
public:
    /////////gcd������д��
    int gcd(int a, int b) {
        int r;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if (n == 1) return res;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (gcd(j, i) == 1) {
                    string temp = to_string(i) + "/" + to_string(j);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};