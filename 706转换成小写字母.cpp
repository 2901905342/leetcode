//����һ���ַ��� s �������ַ����еĴ�д��ĸת������ͬ��Сд��ĸ�������µ��ַ���

#include "myhead.h"
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            int k = (int)s[i];
            if (k >= 65 && k <= 90) {
                s[i] = (char)(k + 32);
            }
        }
        return s;
    }
};