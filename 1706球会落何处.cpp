//��һ����СΪ m x n �Ķ�ά���� grid ��ʾһ�����ӡ����� n �������ӵĶ����͵ײ����ǿ��ŵġ�
//�����е�ÿ����Ԫ����һ���Խ��ߵ��壬�����Ԫ��������ǣ����Խ������������Ҳࡣ
//�������Ҳ�ĵ��������ϽǺ����½ǣ����������� 1 ��ʾ��
//���������ĵ��������ϽǺ����½ǣ����������� - 1 ��ʾ��
//������ÿһ�еĶ��˸���һ����ÿ���򶼿��ܿ����������ӵײ���������
//�����ǡ�ÿ������鵲��֮��� "V" ��ͼ�������߱�һ�鵲�������ӵ�����һ����ϣ��ͻῨס��
//����һ����СΪ n ������ answer ������ answer[i] ������ڶ����ĵ� i �к�ӵײ�����������һ�ж�Ӧ���±꣬
//������ں�����򷵻� - 1 ��

/////˼·����ģ��+����״̬��
// stateһ�����ĸ�״̬,'r','l','d'����'o',�ֱ�����������������Լ�ͣ����ԭ��
//��һ״̬next_state�ɵ�ǰ״̬state�͵�ǰ���񵲰�ĳ������
#include "myhead.h"
class Solution {
public:
    char change(char state, int& flag) {
        if (state == 'd') return flag > 0 ? 'r' : 'l';
        if (state == 'r') return flag > 0 ? 'd' : 'o';
        if (state == 'l') return flag > 0 ? 'o' : 'd';
        return 'o';
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int x = i;
            int y = 0;
            char state = 'd';
            while (1) {
                if (x < 0 || x >= n) {
                    res.push_back(-1);
                    break;
                }
                else if (y == m) {
                    res.push_back(x);
                    break;
                }
                char next_state = change(state, grid[y][x]);
                state = next_state;  //���ﲻ��д��һ��char state=change(state,grid[y][x])�����ʹ��stateһֱΪ'o'
                if (state == 'o') {
                    res.push_back(-1);
                    break;
                }
                else if (state == 'r') x++;
                else if (state == 'l') x--;
                else y++;
            }
        }
        return res;
    }
};