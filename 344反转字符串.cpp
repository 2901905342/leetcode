//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣



////˫ָ�뷨
//�����ַ��������Ƕ�������ָ�루Ҳ����˵�������±���
//һ�����ַ���ǰ�棬һ�����ַ������棬����ָ��ͬʱ���м��ƶ���������Ԫ��

#include "myhead.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int left = 0;
        int right = n - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

    }
};