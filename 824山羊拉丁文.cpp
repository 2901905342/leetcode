﻿//给你一个由若干单词组成的句子 sentence ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。
//请你将句子转换为 “山羊拉丁文（Goat Latin）”（一种类似于 猪拉丁文  - Pig Latin 的虚构语言）。山羊拉丁文的规则如下：
//如果单词以元音开头（'a', 'e', 'i', 'o', 'u'），在单词后添加"ma"。
//例如，单词 "apple" 变为 "applema" 。
//如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
//例如，单词 "goat" 变为 "oatgma" 。
//根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从 1 开始。
//例如，在第一个单词后添加 "a" ，在第二个单词后添加 "aa" ，以此类推。
//返回将 sentence 转换为山羊拉丁文后的句子。

#include "myhead.h"
#include <istream>
#include<sstream>
class Solution {
public:
    unordered_set<char>hash = { 'A','E','I','O','U','a','e','i','o','u' };
    string toGoatLatin(string sentence) {
        vector<string>temp;
        string str;
        string res;
        stringstream sss(sentence);
        while (getline(sss, str, ' ')) {
            temp.push_back(str);
        }
        for (int i = 0; i < temp.size(); i++) {
            if (hash.count(temp[i][0]) == 0) {
                temp[i] += temp[i][0];
                temp[i] = temp[i].substr(1, temp[i].size() - 1);
            }
            temp[i] += "ma" + string(i + 1, 'a');
            res += temp[i] + ' ';
        }
        return res.substr(0, res.size() - 1);
    }
};