//������һ��m��n�еķ��񣬴�����[0, 0] ������[m - 1, n - 1] ��
//һ�������˴�����[0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
//Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//���磬��kΪ18ʱ���������ܹ����뷽��[35, 37] ����Ϊ3 + 5 + 3 + 7 = 18��
//�������ܽ��뷽��[35, 38]����Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ�������ٸ����ӣ�

//////////˼·��������ȱ�����BFS��
//�ɷ�Ϊ����������
//1.��������
//2.�����׽ڵ����չ�ĵ���ӣ�ֱ��û�п���չ�ĵ㣬Ȼ�󽣶��׽ڵ����
// 3.�ظ��ò���ֱ������Ϊ�գ�����¼������
//ֵ��ע������Ѿ��߹��ĸ�����Ҫ��hash���¼����ֹ�ظ����㣬
//���ڴ�������⣬���������鵱hash����set�������ӽ�Լʱ��

#include "myhead.h"
class Solution {
public:
    // ������λ�ͺ���
    int csum(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x = x / 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int> > record; //���У�Ԫ��Ϊ��������
        vector<vector<int>> hash(m, vector<int>(n, 0));  //�����vector<int>��û�б�����
        record.push(make_pair(0, 0)); //�����������
        hash[0][0] = 1; //��¼[0,0]�Ѿ��߹�
        int ans = 1;//��¼������
        // ������(i=0)�Լ�������(i=1)��
        int dx[2] = { 0,1 };
        int dy[2] = { 1,0 };
        while (!record.empty()) {
            pair<int, int>position = record.front();
            record.pop();
            for (int i = 0; i < 2; i++) {
                int x_next = dx[i] + position.first; //��¼��һ�������
                int y_next = dy[i] + position.second; //��¼��һ��������
                //���ڳ����߽�����Ѿ��߹��ĵ���߲�������ĵ��������
                if (x_next >= m || y_next >= n || hash[x_next][y_next] || csum(x_next) + csum(y_next) > k) continue;
                hash[x_next][y_next] = 1;  //��¼�õ��Ѿ��߹�
                record.push(make_pair(x_next, y_next));//����չ�����
                ans++;//������+1
            }
        }
        return ans;

    }
};
