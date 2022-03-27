//���� Andy �� Doris �������ʱѡ��һ�Ҳ������������Ƕ���һ����ʾ��ϲ���������б�ÿ���������������ַ�����ʾ��
//����Ҫ�������������ٵ��������ҳ����ǹ�ͬϲ���Ĳ����� 
//����𰸲�ֹһ������������д𰸲��Ҳ�����˳�� ����Լ�������Ǵ��ڡ�

/////˼·�� hash��   ��ʱ�临�Ӷ�o(n1+n2),n1,n2�ֱ��������б�ĳ���
#include "myhead.h"
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hash_table;
        vector<string> res;
        int minsum = list1.size() + list2.size();
        for (int i = 0; i < list1.size(); i++) {
            hash_table.insert(pair<string, int>(list1[i], i));
        }
        for (int i = 0; i < list2.size(); i++) {
            if (hash_table.count(list2[i]) && i + hash_table[list2[i]] <= minsum) {
                if (i + hash_table[list2[i]] < minsum) {
                    res.clear();
                    minsum = i + hash_table[list2[i]];
                }
                res.push_back(list2[i]);

            }
        }
        return res;

    }
};