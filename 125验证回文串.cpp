//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

/// <summary>
/// ////////////////////////˼· �� ˫ָ��
/// </summary>
/// 
#include "myhead.h"
class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> all;
        for (int i = 0; i < s.size(); i++) {
            int temp = (int)s[i];
            if ((temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57)) { //Сд��ĸ��������ʵ����
                all.push_back(temp);
            }
            if (temp >= 65 && temp <= 90) {
                all.push_back(temp + 32);
            }
        }
        bool flag = true;
        int i = 0;
        int j = all.size() - 1;
        while (i < j) {
            if (all[i] != all[j]) {
                return !flag;
            }
            i++;
            j--;
        }
        return flag;
    }
};