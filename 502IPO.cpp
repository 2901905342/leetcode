//假设 力扣（LeetCode）即将开始 IPO 。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。
//由于资源有限，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。
//给你 n 个项目。对于每个项目 i ，它都有一个纯利润 profits[i] ，和启动该项目需要的最小资本 capital[i] 。
//最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。
//总而言之，从给定项目中选择 最多 k 个不同项目的列表，以 最大化最终资本 ，并输出最终可获得的最多资本。
//答案保证在 32 位有符号整数范围内。

///思路：贪心+优先级队列
//由于每完成一个任务都会使得总资金 w 增加或不变。因此对于所选的第 i 个任务而言，应该在
//所有「未被选择」且启动资金不超过 w 的所有任务里面选利润最大的。
//当知道了「每次都应该在所有可选择的任务里选利润最大」的推论之后，再看看算法的具体流程。
//由于每完成一个任务总资金都会 增大 /不变，因此所能覆盖的任务集合数量也随之增加 / 不变 。
//因此算法核心为「每次决策前，将启动资金不超过当前总资金的任务加入集合，再在里面取利润最大的任务」。
//「取最大」的过程可以使用优先队列（根据利润排序的大根堆），而「将启动资金不超过当前总资金的任务加入集合」的操作，
//可以利用总资金在整个处理过程递增，而先对所有任务进行预处理排序来实现。

#include "myhead.h"
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>duile;
        vector<pair<int, int>>record;
        int cur = 0;  //保证了优先级队列中不会重复添加任务
        int n = capital.size();
        for (int i = 0; i < capital.size(); i++) {
            record.push_back({ capital[i],profits[i] });
        }
        sort(record.begin(), record.end());//很奇特的一点，vector能根据pair中第一个值的大小进行排序
        while (k--) {
            while (cur < n && record[cur].first <= w) {
                duile.push(record[cur].second);
                cur++;
            }
            if (!duile.empty()) {
                w += duile.top();
                duile.pop();
            }
            else break;  //当没有可做的任务时，直接退出
        }
        return w;
    }
};