//���� �������ַ�����ʾ����ѭ "ʵ��+�鲿i" ����ʽ������������������
//ʵ�� ��һ��������ȡֵ��Χ��[-100, 100]
//�鲿 Ҳ��һ��������ȡֵ��Χ��[-100, 100]
//���������ַ�����ʾ�ĸ��� num1 �� num2 ��������ѭ������ʾ��ʽ�����ر�ʾ���ǳ˻����ַ�����

///////˼·�� ���ҵ��Ӻŵ�λ�ã��ӿ�ʼ��+��ǰһԪ��Ϊʵ������+����һ��λ�õ�i֮ǰΪ�鲿
///ֵ��ע�����stoi������to_string���������Ƕ�������ͷ�ļ�<string>��
////to_string ���� ����ֵ������int��double��long��ת��Ϊstringת��������
/// stoi ���� �����ǽ��ַ���ת��Ϊint��
#include "myhead.h"
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pos1 = num1.find('+', 0);  //�ҵ�i��λ��
        int pos2 = num2.find('+', 0);
        int r1 = stoi(num1.substr(0, pos1));  //ʵ��
        int r2 = stoi(num2.substr(0, pos2));
        int v1 = stoi(num1.substr(pos1 + 1, num1.size() - 1 - pos1)); //�鲿
        int v2 = stoi(num2.substr(pos2 + 1, num2.size() - 1 - pos2));
        return to_string(r1 * r2 - v1 * v2) + '+' + to_string(r1 * v2 + v1 * r2) + 'i';

    }
};