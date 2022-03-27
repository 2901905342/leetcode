//假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
//你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 
//如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。

/////思路： hash表   ，时间复杂度o(n1+n2),n1,n2分别是两个列表的长度
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