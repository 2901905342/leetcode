//�����ַ��� key �� message ���ֱ��ʾһ��������Կ��һ�μ�����Ϣ������ message �Ĳ������£�
//ʹ�� key �� 26 ��Ӣ��Сд��ĸ��һ�γ��ֵ�˳����Ϊ�滻���е���ĸ ˳�� ��
//���滻������ͨӢ����ĸ����룬�γɶ��ձ�
//���ն��ձ� �滻 message �е�ÿ����ĸ��
//�ո� ' ' ���ֲ��䡣
//���磬key = "happy boy"��ʵ�ʵļ�����Կ�������ĸ����ÿ����ĸ ����һ�Σ���
//�ݴˣ����Եõ����ֶ��ձ�'h' -> 'a'��'a' -> 'b'��'p' -> 'c'��'y' -> 'd'��'b' -> 'e'��'o' -> 'f'����
//���ؽ��ܺ����Ϣ��
//
//26 <= key.length <= 2000
//key ��СдӢ����ĸ�� ' ' ���
//key ����Ӣ����ĸ����ÿ���ַ���'a' �� 'z'������һ��
//1 <= message.length <= 2000
//message ��СдӢ����ĸ�� ' ' ���


//˼·����ϣ��+ģ��
#include "myhead.h"
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>hash;
        string res;
        char i = 'a';
        for (auto c : key) {
            if (!hash.count(c) && c != ' ') hash[c] = i++;
        }
        for (auto c : message) {
            if (hash.count(c)) res += hash[c];
            else res += c;
        }
        return res;

    }
};