//��������һ�������������ư�������ļ�¼Ա���ⳡ���������ɻغ���ɣ���ȥ���غϵĵ÷ֿ��ܻ�Ӱ���Ժ󼸻غϵĵ÷֡�
//������ʼʱ����¼�ǿհ׵ġ����õ�һ����¼�������ַ����б� ops������ ops[i] ������Ҫ��¼�ĵ� i �������ops ��ѭ��������
//���� x - ��ʾ���غ��»�÷��� x
//"+" - ��ʾ���غ��»�õĵ÷���ǰ���ε÷ֵ��ܺ͡���Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���������Ч�ķ�����
//"D" - ��ʾ���غ��»�õĵ÷���ǰһ�ε÷ֵ���������Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//"C" - ��ʾǰһ�ε÷���Ч������Ӽ�¼���Ƴ�����Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
//���㷵�ؼ�¼�����е÷ֵ��ܺ͡�


/////˼·����ģ��
#include "myhead.h"
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        vector<int> temp;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "C") {
                temp.pop_back();
                continue;
            }
            if (ops[i] == "+") {
                temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);
                continue;
            }
            if (ops[i] == "D") {
                temp.push_back(2 * temp[temp.size() - 1]);
                continue;
            }

            temp.push_back(stoi(ops[i]));
        }
        for (auto x : temp) {
            res += x;
        }
        return res;
    }
};