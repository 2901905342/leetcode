//地上有一个m行n列的方格，从坐标[0, 0] 到坐标[m - 1, n - 1] 。
//一个机器人从坐标[0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
//也不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格[35, 37] ，因为3 + 5 + 3 + 7 = 18。
//但它不能进入方格[35, 38]，因为3 + 5 + 3 + 8 = 19。请问该机器人能够到达多少个格子？

//////////思路：广度优先遍历（BFS）
//可分为以下三步：
//1.将起点入队
//2.将队首节点可扩展的点入队，直到没有可扩展的点，然后剑队首节点出队
// 3.重复该步骤直到队列为空，并记录格子数
//值得注意的是已经走过的格子需要用hash表记录，防止重复计算，
//由于此题的特殊，可以用数组当hash表，比set容器更加节约时间

#include "myhead.h"
class Solution {
public:
    // 计算数位和函数
    int csum(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x = x / 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int, int> > record; //队列，元素为横纵坐标
        vector<vector<int>> hash(m, vector<int>(n, 0));  //里面的vector<int>并没有变量名
        record.push(make_pair(0, 0)); //将起点存入队列
        hash[0][0] = 1; //记录[0,0]已经走过
        int ans = 1;//记录格子数
        // 向下走(i=0)以及向右走(i=1)，
        int dx[2] = { 0,1 };
        int dy[2] = { 1,0 };
        while (!record.empty()) {
            pair<int, int>position = record.front();
            record.pop();
            for (int i = 0; i < 2; i++) {
                int x_next = dx[i] + position.first; //记录下一点横坐标
                int y_next = dy[i] + position.second; //记录下一点纵坐标
                //对于超出边界或者已经走过的点或者不合题意的点进行跳过
                if (x_next >= m || y_next >= n || hash[x_next][y_next] || csum(x_next) + csum(y_next) > k) continue;
                hash[x_next][y_next] = 1;  //记录该点已经走过
                record.push(make_pair(x_next, y_next));//可扩展点入队
                ans++;//格子数+1
            }
        }
        return ans;

    }
};
