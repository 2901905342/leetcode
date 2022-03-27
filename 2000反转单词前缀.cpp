//����һ���±�� 0 ��ʼ���ַ��� word ��һ���ַ� ch ��
//�ҳ� ch ��һ�γ��ֵ��±� i ����ת word �д��±� 0 ��ʼ��ֱ���±� i ���������±� i �����Ƕ��ַ���
//��� word �в������ַ� ch ������������κβ�����
//���磬��� word = "abcdefd" �� ch = "d" ����ô��Ӧ�� ��ת ���±� 0 ��ʼ��ֱ���±� 3 ���������±� 3 ����
//����ַ��������� "dcbaefd" ��
//���� ����ַ��� ��

////////˼·����ģ�⣬ע��ٷ���reverse��������������ҿ����÷�

#include "myhead.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int flag = 0;
        int right = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                flag = 1;
                right = i;
                break;
            }
        }
        if (!flag) return word;
        int left = 0;
        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }
        return word;
    }
};


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch); //����ch��һ�γ��ֵ�λ��
        if (index != -1) {
            reverse(word.begin(), word.begin() + index + 1);
        }
        return word;
    }
};

