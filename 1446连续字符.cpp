//����һ���ַ��� s ���ַ����ġ�����������Ϊ��ֻ����һ���ַ�����ǿ����ַ����ĳ��ȡ�
//���㷵���ַ�����������



////////���͵Ŀ���ָ������//////////
#include "myhead.h"
class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        int low = 0;
        int right = 1;
        int res = 1;
        while (right < n) {
            if (s[low] == s[right]) {
                int temp = right - low + 1;
                res = max(res, temp);
            }
            else {
                low = right;
            }
            right++;
        }
        return res;

    }
};