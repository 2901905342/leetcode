//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

/////ֱ��ģ��
#include "myhead.h"
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                res += "%20";
            }
            else res += s[i];
        }
        return res;
    }
};