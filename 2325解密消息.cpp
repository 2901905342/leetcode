//给你字符串 key 和 message ，分别表示一个加密密钥和一段加密消息。解密 message 的步骤如下：
//使用 key 中 26 个英文小写字母第一次出现的顺序作为替换表中的字母 顺序 。
//将替换表与普通英文字母表对齐，形成对照表。
//按照对照表 替换 message 中的每个字母。
//空格 ' ' 保持不变。
//例如，key = "happy boy"（实际的加密密钥会包含字母表中每个字母 至少一次），
//据此，可以得到部分对照表（'h' -> 'a'、'a' -> 'b'、'p' -> 'c'、'y' -> 'd'、'b' -> 'e'、'o' -> 'f'）。
//返回解密后的消息。
//
//26 <= key.length <= 2000
//key 由小写英文字母及 ' ' 组成
//key 包含英文字母表中每个字符（'a' 到 'z'）至少一次
//1 <= message.length <= 2000
//message 由小写英文字母和 ' ' 组成


//思路：哈希表+模拟
#include "myhead.h"
class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>hash;
        string res;
        char i = 'a';
        for (auto c : key) {
            if (!hash.count(c) && c != ' ') hash[c] = i++;
        }
        for (auto c : message) {
            if (hash.count(c)) res += hash[c];
            else res += c;
        }
        return res;

    }
};