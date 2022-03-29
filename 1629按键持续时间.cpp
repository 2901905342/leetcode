//LeetCode �����һ����ʽ���̣����ڲ���������ԡ�������Ա������һϵ�м����ܼ� n ������ÿ��һ����
//
//����һ������Ϊ n ���ַ��� keysPressed ������ keysPressed[i] ��ʾ���������е� i �������µļ���releaseTimes ��һ���������е��б����� releaseTimes[i] ��ʾ�ɿ��� i ������ʱ�䡣
// �ַ���������� �±궼�� 0 ��ʼ ���� 0 ������ʱ��Ϊ 0 ʱ�����£�������ÿ������ ǡ�� ��ǰһ�����ɿ�ʱ�����¡�
//
//������Ա��Ҫ�ҳ����� ����ʱ��� �ļ����� i �ΰ����ĳ���ʱ��Ϊ releaseTimes[i] - releaseTimes[i - 1] ���� 0 �ΰ����ĳ���ʱ��Ϊ releaseTimes[0] ��
//
//ע�⣬�����ڼ䣬ͬһ���������ڲ�ͬʱ�̱���ΰ��£���ÿ�εĳ���ʱ�䶼���ܲ�ͬ��
//
//�뷵�ذ��� ����ʱ��� �ļ�������ж�������ļ����򷵻� ����ĸ˳��������� ���Ǹ�����

/// <summary>
/// ˼·  ����ģ��
/// </summary>
#include"myhead.h"


class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.size();
        int res = releaseTimes[0];//��¼�����ʱ��
        int index = 0;
        for (int i = 1; i < n; i++) {
            int temp = releaseTimes[i] - releaseTimes[i - 1];
            bool flag = (temp == res) && ((int)keysPressed[i] > (int)keysPressed[index]);
            if (temp > res || flag) {
                res = temp;
                index = i;
            }

        }
        return keysPressed[index];

    }
};