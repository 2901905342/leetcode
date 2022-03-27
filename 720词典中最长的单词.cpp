//给出一个字符串数组 words 组成的一本英语词典。
//返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。
//若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

////需要注意的是必须从一个字母开始添加

//////思路1：哈希集合
//空字符串是符合要求的单词；
//在符合要求的单词的末尾添加一个字母，得到的新单词是符合要求的单词。
//这道题要求返回数组 words 中的最长的符合要求的单词，如果有多个最长的符合要求的单词则返回其中字典序最小的单词。以下将返回值称为「答案」。
//为了方便处理，需要将数组 words 排序，排序的规则是首先按照单词的长度升序排序，如果单词的长度相同则按照字典序降序排序(这很重要，保证字典序小的一定在后面）。
// 
//排序之后，可以确保当遍历到每个单词时，比该单词短的全部单词都已经遍历过，且每次遇到符合要求的单词一定是最长且字典序最小的单词，可以直接更新答案。
//将答案初始化为空字符串。使用哈希集合存储所有符合要求的单词，初始时将空字符串加入哈希集合。
//遍历数组words，对于每个单词，判断当前单词去掉最后一个字母之后的前缀是否在哈希集合中，
//如果该前缀在哈希集合中则当前单词是符合要求的单词，将当前单词加入哈希集合，并将答案更新为当前单词。
//遍历结束之后，返回答案。
#include "myhead.h"
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            else {
                return a > b;
            }
            });
        string longest = "";
        unordered_set<string> cnt;
        cnt.emplace("");
        for (auto& word : words) {
            if (cnt.count(word.substr(0, word.size() - 1))) {
                cnt.emplace(word);
                longest = word;
            }
        }
        return longest;
    }
};

/////// 思路2：前缀树（详见官方答案）