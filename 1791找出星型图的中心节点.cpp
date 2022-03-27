//有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。
//星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。
//给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。
//请你找出并返回 edges 所表示星型图的中心节点。
//提示：
//3 <= n <= 105
//edges.length == n - 1
//edges[i].length == 2
//1 <= ui, vi <= n
//ui != vi
//题目数据给出的 edges 表示一个有效的星型图

/////思路：其实这是数学题：由 n 个节点组成的星型图中，有一个中心节点，有 n−1 条边分别连接中心节点和其余的每个节点。
//因此，中心节点的度是 n−1，其余每个节点的度都是 1。
//那这肯定用哈希表
#include "myhead.h"
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> hash_table;
        for (auto edge : edges) {
            if (hash_table.count(edge[0])) return edge[0];
            if (hash_table.count(edge[1])) return edge[1];
            hash_table.insert(edge[0]);
            hash_table.insert(edge[1]);
        }
        return -1;
    }
};

