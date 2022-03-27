//Alice 和 Bob 再次设计了一款新的石子游戏。现有一行 n 个石子，每个石子都有一个关联的数字表示它的价值。
//给你一个整数数组 stones ，其中 stones[i] 是第 i 个石子的价值。
//Alice 和 Bob 轮流进行自己的回合，Alice 先手。每一回合，玩家需要从 stones 中移除任一石子。
//如果玩家移除石子后，导致 所有已移除石子 的价值 总和 可以被 3 整除，那么该玩家就 输掉游戏 。
//如果不满足上一条，且移除后没有任何剩余的石子，那么 Bob 将会直接获胜（即便是在 Alice 的回合）。
//假设两位玩家均采用 最佳 决策。如果 Alice 获胜，返回 true ；如果 Bob 获胜，返回 fals

/////////// 思路：  典型的博弈论问题，最重要的是对石子的值以3取模分为三类
////  具体过程请看https://leetcode-cn.com/problems/stone-game-ix/solution/gong-shui-san-xie-fen-qing-kuang-tao-lun-h1oa/


#include "myhead.h"

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>cnt(3, 0);
        for (int i : stones) {
            cnt[i % 3]++;
        }
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        return abs(cnt[1] - cnt[2]) > 2;
    }
};