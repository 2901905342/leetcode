//为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。
//给你一个赎金信(ransomNote) 字符串和一个杂志(magazine)字符串，判断 ransomNote 能不能由 magazines 里面的字符构成。
//如果可以构成，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。
//1 <= ransomNote.length, magazine.length <= 105
//ransomNote 和 magazine 由小写英文字母组成


/////明显的hash表，由于字符串只含有小写字母，可用数组来作为hash表

#include "myhead.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) return false;
        int hash[26] = { 0 };
        for (int i = 0; i < magazine.size(); i++) {
            hash[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            hash[ransomNote[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] < 0)  return false;
        }
        return true;
    }
};


