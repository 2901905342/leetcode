//树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
//给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），
//其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
//可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。
//请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
//树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。

/// 个人做法：多点BFS，时间复杂度o(n^2),直接超时
#include "myhead.h"
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>lingjie(n);
        vector<int>visited(n);
        vector<int>record;
        for (auto edge : edges) {
            lingjie[edge[1]].push_back(edge[0]);
            lingjie[edge[0]].push_back(edge[1]);
        }
        queue<int> duilie;
        int min = n;
        for (int num = 0; num < n; num++) {
            duilie.push(num);
            visited = vector<int>(n);
            visited[num] = 1;
            int cnt = 0;
            while (!duilie.empty()) {
                int d_size = duilie.size();
                for (int i = 0; i < d_size; i++) {
                    int temp = duilie.front();
                    duilie.pop();
                    for (auto x : lingjie[temp]) {
                        if (visited[x] == 0) {
                            duilie.push(x);
                            visited[x]++;
                        }
                    }
                }
                cnt++;
            }
            if (cnt == min) record.push_back(num);
            else if (cnt < min) {
                min = cnt;
                record.clear();
                record.push_back(num);
            }
            //record.push_back(cnt);
        }
        return record;
    }
};

////////官方解法：https://leetcode-cn.com/problems/minimum-height-trees/solution/zui-xiao-gao-du-shu-by-leetcode-solution-6v6f/
//设 dist[x][y] 表示从节点 xx 到节点 yy 的距离，假设树中距离最长的两个节点为 (x,y)，
//它们之间的距离为 maxdist = dist[x][y]，则可以推出以任意节点构成的树最小高度一定为 H = [maxdist / 2]​;[]表示向下取整
//且最小高度的树根节点一定在 节点 x 到节点 y 的路径上。

//在此我们利用广度优先搜索来找到节点的最长路径，首先找到距离节点 0 的最远节点 x，
//然后找到距离节点 x 的最远节点 y，然后找到节点 x 与节点 y 的路径，然后找到根节点。
//假设P=u....v是树的一条最长生成路，则0第一次一定能找到生成路的端点（可以用反证法证明，分0在P上和0不在P上两种情况）

class Solution {
public:
    int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto& v : adj[curr]) {
                if (!visit[v]) {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> parent(n, -1);
        /* 找到与节点 0 最远的节点 x */
        int x = findLongestNode(0, parent, adj);
        /* 找到与节点 x 最远的节点 y */
        int y = findLongestNode(x, parent, adj);
        /* 求出节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return { path[m / 2 - 1], path[m / 2] };
        }
        else {
            return { path[m / 2] };
        }
    }
};

