//����һ���� n x n ��������ɵĳ��У�ÿ������������һ�������彨��������һ���±�� 0 ��ʼ�� n x n �������� grid ������ grid[r][c] ��ʾ������ r �� c �еĽ������ �߶� ��
//���е� ����� �Ǵ�Զ���۲����ʱ�����н������γɵ��ⲿ�������Ӷ����ϡ��������ĸ���Ҫ����۲⵽�� ����� ���ܲ�ͬ��
//���Ǳ�����Ϊ ���������Ľ����� �ĸ߶����� ������������ͬ��������������ܲ�ͬ�� �� �߶�Ϊ 0 �Ľ�����ĸ߶�Ҳ�������ӡ�Ȼ�������ӵĽ�����߶� ����Ӱ�� ���κ���Ҫ����۲���еõ��� ����� ��
//�� ���ı� ���κ���Ҫ����۲⵽�ĳ��� ����� ��ǰ���£����ؽ�����������ӵ� ���߶������ܺ� ��


#include "myhead.h"
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <int> MAXhang(n);//���캯����ʼ����n��0Ԫ��
        vector <int> MAXlie(n);//
        //vector <int> a;  Ĭ�ϲ����г�ʼ��
        //vector <int> a(n);  ���캯����ʼ����n��ֵΪ0��Ԫ��
        //vector <int> a(n,val);   ���캯����ʼ����n��ֵΪval��Ԫ��
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                MAXhang[i] = max(MAXhang[i], grid[i][j]);//�洢ÿ�е����ֵ
                MAXlie[j] = max(MAXlie[j], grid[i][j]);  //�洢ÿ�е����ֵ
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += min(MAXhang[i], MAXlie[j]) - grid[i][j];
            }
        }
        return res;
    }
};