//����һ���ַ��� s ��������������ת�ַ�����
//���з�Ӣ����ĸ������ԭ��λ�á�
//����Ӣ����ĸ��Сд���д��λ�÷�ת��
//���ط�ת��� s ��

//��ʾ
//1 <= s.length <= 100
//s ���� ASCII ֵ�ڷ�Χ[33, 122] ���ַ����
//s ���� '\"' �� '\\'

#include "myhead.h"
////////˼��1����ģ��
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res;
        vector<int> index;
        for (int i = 0; i < s.size(); i++) {
            bool flag1 = (s[i] - 'A' >= 0) && (s[i] - 'A' <= 25);
            bool flag2 = (s[i] - 'a' >= 0) && (s[i] - 'a' <= 25);
            if (flag1 || flag2) res += s[i];
            else index.push_back(i);
        }
        reverse(res.begin(), res.end());
        for (auto i : index) {
            res.insert(i, 1, s[i]);
        }
        return res;
    }
};

//////˼��2��˫ָ��
//����ʹ�� left ָ�����߿�ʼɨ���ַ��� s��right ָ����ұ߿�ʼɨ���ַ��� ss���������ָ�붼ɨ�赽��ĸ
//�� left < right����ô����s[left] �� s[right]��Ȼ���������ɨ�裻
// ���������ת���̽��������ش������ַ�����
//ֵ��ע�����ʹ��isalpha���������ж��ַ��Ƿ�Ϊ��ĸ������ctype.hͷ�ļ�����Ҳ������iostreamͷ�ļ���

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // �ж�����Ƿ�ɨ�赽��ĸ
                left++;
            }
            while (right > left && !isalpha(s[right])) { // �ж��ұ��Ƿ�ɨ�赽��ĸ
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

