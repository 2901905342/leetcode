//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

/////////思路：哈希表+滑动窗口（双指针）
#include "myhead.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_set<char> hash_table;
        while (right < s.size()) {
            if (hash_table.find(s[right]) == hash_table.end()) { //等效于hash_table.count(s[right])==0
                hash_table.insert(s[right]);
                max_len = max(max_len, right - left + 1);
                right++;
            }
            else {
                hash_table.erase(s[left]);
                left++;
            }

        }
        return max_len;
    }
};