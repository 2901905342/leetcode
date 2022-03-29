//给你一个字符串 licensePlate 和一个字符串数组 words ，请你找出并返回 words 中的 最短补全词 。
//补全词 是一个包含 licensePlate 中所有的字母的单词。在所有补全词中，最短的那个就是 最短补全词 。
//在匹配 licensePlate 中的字母时：
//忽略 licensePlate 中的 数字和空格 。
//不区分大小写。
//如果某个字母在 licensePlate 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。
//例如：licensePlate = "aBc 12c"，那么它的补全词应当包含字母 'a'、'b' （忽略大写）和两个 'c' 。可能的 补全词 有 "abccdef"、"caaacab" 以及 "cbca" 。
//请你找出并返回 words 中的 最短补全词 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 words 中 最靠前的 那个。

//提示：
//1 <= licensePlate.length <= 7
//licensePlate 由数字、大小写字母或空格 ' ' 组成
//1 <= words.length <= 1000
//1 <= words[i].length <= 15
//words[i] 由小写英文字母组成

///////////////////////思路  hash表////////////////////////
#include "myhead.h"
class Solution {
public:
    bool compare(int hash[26], string word) {
        int temp[26] = { 0 };
        for (int i = 0; i < word.size(); i++) {
            temp[word[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] > temp[i]) return false;
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int hash[26] = { 0 };
        for (int i = 0; i < licensePlate.size(); i++) {
            int ascii = (int)licensePlate[i];
            if (ascii >= 65 && ascii <= 90) {  //对应大写字母的ascii值
                hash[ascii - 65]++;
            }
            if (ascii >= 97 && ascii <= 122) { //对应小写字母的ascii值
                hash[ascii - 97]++;
            }
        }
        int MAXsize = 16;
        int index = -1;
        for (int i = 0; i < words.size(); i++) {
            if (compare(hash, words[i])) {
                if (words[i].size() < MAXsize) {
                    index = i;
                    MAXsize = words[i].size();
                }
            }
        }
        return words[index];
    }
};