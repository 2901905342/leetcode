//������������� arr������ÿ��Ԫ�ض� ����ͬ��
//�����ҵ����о�����С���Բ��Ԫ�ضԣ����Ұ������˳�򷵻ء�

//˼·������+һ�α���
#include "myhead.h"
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int tmin = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            int x = arr[i] - arr[i - 1];
            if (x == tmin) res.push_back({ arr[i - 1],arr[i] });
            if (x < tmin) {
                res.clear();
                res.push_back({ arr[i - 1],arr[i] });
                tmin = x;
            }

        }
        return res;
    }
};