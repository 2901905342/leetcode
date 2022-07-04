//在第 1 天，有一个人发现了一个秘密。
//给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人 分享 秘密。同时给你一个整数 forget ，表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。
//一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。
//给你一个整数 n ，请你返回在第 n 天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对 109 + 7 取余 后返回。
//2 <= n <= 1000
//1 <= delay < forget <= n


////思路：递推
//记 f[i] 表示第 i天新知道秘密的人数。根据题意有初始条件 f[1] = 1。
//根据题意，在第 i 天，只有(i−forget, i−delay] 这个区间里新知道秘密的人才会告诉其它人,（可用前缀和计算区间内的人数）
//实现的时候注意i−forget + 1 和 i - delayi−delay 可能超出[1, n]的范围，需要处理一下边界。




#include "myhead.h"
class Solution {
    const int MOD = 1000000007;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> f(n + 1), g(n + 1);
        f[1] = g[1] = 1;
        for (int i = 2; i <= n; i++) {
            int L = max(0, i - forget);
            int R = max(0, i - delay);
            f[i] = (g[R] - g[L] + MOD) % MOD;
            g[i] = (g[i - 1] + f[i]) % MOD;  //g是f的前缀和
        }
        return (g[n] - g[max(0, n - forget)] + MOD) % MOD;
    }
};