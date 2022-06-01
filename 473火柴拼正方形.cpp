//你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。
//你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须使用一次 。
//如果你能使这个正方形，则返回 true ，否则返回 false 。
//首先计算所有火柴的总长度 totalLen，如果 totalLen 不是 4 的倍数，那么不可能拼成正方形，返回 false。
//当 totalLen 是 4 的倍数时，每条边的边长为 len =totalLen/4
//​edges 来记录 4条边已经放入的火柴总长度。对于第index 火柴，尝试把它放入其中一条边内且满足放入后该边的火柴总长度不超过 len
//然后继续枚举第 1index + 1 根火柴的放置情况，如果所有火柴都已经被放置，那么说明可以拼成正方形。
//为了减少搜索量，需要对火柴长度从大到小进行排序。

#include "myhead.h"
class Solution {
public:

    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int target) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= target && dfs(index + 1, matchsticks, edges, target)) return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        int  target;
        vector<int>edges(4);
        for (auto i : matchsticks) {
            sum += i;
        }
        if (sum % 4) return false;
        target = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量,降序排列
        return dfs(0, matchsticks, edges, target);

    }
};