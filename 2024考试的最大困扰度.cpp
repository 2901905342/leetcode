//一位老师正在出一场由 n 道判断题构成的考试，每道题的答案为 true （用 'T' 表示）或者 false （用 'F' 表示）。
//老师想增加学生对自己做出答案的不确定性，方法是 最大化 有 连续相同 结果的题数。（也就是连续出现 true 或者连续出现 false）。
//给你一个字符串 answerKey ，其中 answerKey[i] 是第 i 个问题的正确结果。除此以外，还给你一个整数 k ，表示你能进行以下操作的最多次数：
//每次操作中，将问题的正确答案改为 'T' 或者 'F' （也就是将 answerKey[i] 改为 'T' 或者 'F' ）。
//请你返回在不超过 k 次操作的情况下，最大 连续 'T' 或者 'F' 的数目。

///思路：在指定字符的情况下，我们可以计算其最大连续数目。
//具体地，我们使用滑动窗口的方法，从左到右枚举右端点，维护区间中另一种字符的数量为sum，
//当 sum 超过 k，我们需要让左端点右移，直到 sum≤k。移动过程中，我们记录滑动窗口的最大长度，即为指定字符的最大连续数目。
//本题的答案为分别指定字符为 TT 和 FF 时的最大连续数目的较大值。



#include "myhead.h"
class Solution {
public:
    int maxConsecutiveChar(string& answerKey, int& k, char ch) {
        int n = answerKey.size();
        int ans = 0;
        int left = 0;
        int sum_he = 0;
        int longgest = 0;
        for (int right = 0; right < n; right++) {
            ans += answerKey[right] == ch ? 0 : 1;
            while (ans > k) {
                ans -= answerKey[left] == ch ? 0 : 1;
                left++;
            }
            longgest = max(longgest, right + 1 - left);
        }
        return longgest;

    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int T = maxConsecutiveChar(answerKey, k, 'T');
        int F = maxConsecutiveChar(answerKey, k, 'F');
        return max(T, F);
    }
};