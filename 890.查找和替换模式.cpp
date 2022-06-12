//你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。
//如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。
//（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）
//返回 words 中与给定模式匹配的单词列表。
//你可以按任何顺序返回答案。

//思路：
//我们可以逐个判断words 中的每个单词 word 是否与 pattern 匹配。
//根据题意，我们需要构造从字母到字母的双射，即 word 的每个字母需要映射到 pattern 的对应字母，并且 pattern 的每个字母也需要映射到word 的对应字母。
//我们可以编写一个函数 match(word, pattern)，仅当 word 中相同字母映射到 pattern 中的相同字母时返回 true。
//我们可以在遍历这两个字符串的同时，用一个哈希表记录word 的每个字母 x 需要映射到 pattern 的哪个字母上，如果 x 已有映射，则需要检查对应字母是否相同。
//如果 match(word, pattern) 和 match(pattern, word) 均为 \texttt{ true }true，则表示word 与 pattern 匹配。
#include "myhead.h"

class Solution {
    bool match(string& word, string& pattern) {
        unordered_map<char, char> mp;
        for (int i = 0; i < word.length(); ++i) {
            char x = word[i], y = pattern[i];
            if (!mp.count(x)) {
                mp[x] = y;
            }
            else if (mp[x] != y) { // word 中的同一字母必须映射到 pattern 中的同一字母上
                return false;
            }
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
        vector<string> ans;
        for (auto& word : words) {
            if (match(word, pattern) && match(pattern, word)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};

