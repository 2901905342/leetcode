//����һ�� m* n �ľ��󣬾����е����� ������ͬ���㰴����˳�򷵻ؾ����е�������������
//��������ָ����������ͬʱ��������������Ԫ�أ�
//��ͬһ�е�����Ԫ������С
//��ͬһ�е�����Ԫ�������

/////////˼·���������󣬼�¼ÿһ�е���СԪ�غ�ÿһ�е����Ԫ��
////ֻҪ������Ⱦ�˵������������
///���⻰��(���������д�������ѧ֤��������Ҫôֻ��һ��Ҫôû�У�
#include "myhead.h"
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 100000); //��¼ÿһ�е���СԪ��
        vector<int> col(n, 0);     //��¼ÿһ�е����Ԫ��
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < row[i]) row[i] = matrix[i][j];
                if (matrix[i][j] > col[j]) col[j] = matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j]) res.push_back(row[i]);
            }
        }
        return res;
    }
};