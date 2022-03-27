//给你一个有 n 个服务器的计算机网络，服务器编号为 0 到 n - 1 。
//同时给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示服务器 ui 和 vi 之间有一条信息线路，在 一秒 内它们之间可以传输 任意 数目的信息。
//再给你一个长度为 n 且下标从 0 开始的整数数组 patience 。
//题目保证所有服务器都是 相通 的，也就是说一个信息从任意服务器出发，都可以通过这些信息线路直接或间接地到达任何其他服务器。
//编号为 0 的服务器是 主 服务器，其他服务器为 数据 服务器。每个数据服务器都要向主服务器发送信息，并等待回复。
//信息在服务器之间按 最优 线路传输，也就是说每个信息都会以 最少时间 到达主服务器。主服务器会处理 所有 新到达的信息并 立即 按照每条信息来时的路线 反方向 发送回复信息。
//在 0 秒的开始，所有数据服务器都会发送各自需要处理的信息。从第 1 秒开始，每 一秒最 开始 时，每个数据服务器都会检查它是否收到了主服务器的回复信息（包括新发出信息的回复信息）：
//如果还没收到任何回复信息，那么该服务器会周期性 重发 信息。
//数据服务器 i 每 patience[i] 秒都会重发一条信息，也就是说，数据服务器 i 在上一次发送信息给主服务器后的 patience[i] 秒 后 会重发一条信息给主服务器。
//否则，该数据服务器 不会重发 信息。
//当没有任何信息在线路上传输或者到达某服务器时，该计算机网络变为 空闲 状态。
//请返回计算机网络变为 空闲 状态的 最早秒数 。


//思路：
//求各个节点与 0 号服务器的最短路径R，直接利用广度优先搜索即可。
//服务器最后接收到回复的时间为T=2R+k ,其中k为最后一次服务器重发信息的时刻
//关于k的计算  
//当 2R<=patience[i],不会重发，k=0
//当 2R%patience[i]==0, 重发时刻为 k=2R-patience[i]
//当 2R%patience[i]!=0,重发时刻为 k=(2R/patience[i])*patience; 注意2R/patience[i]利用了int 自身的向下取整


#include "myhead.h"
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);  ///adj[i]存储节点i的邻居节点
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> duile;
        vector<int> visited(n, -1); //visied[i]存储i号节点到0号节点的距离，当值为-1是表明该节点还未被访问
        visited[0] = 0;
        int count = 1;  //记录当前节点与0号节点间的距离，在BFS中递增
        duile.push(0);
        while (!duile.empty()) {
            int d_size = duile.size();
            for (int i = 0; i < d_size; i++) {
                int temp = duile.front();
                duile.pop();
                for (auto &x : adj[temp]) {
                    if (visited[x] == -1) {
                        visited[x] = count;
                        duile.push(x);
                    }
                }
            }
            count++;
        }

        int max = 0; //记录所有节点都收到回复的最大时间
        int k = 0; //记录最近一次重发的时间
        for (int i = 1; i < n; i++) {
            int R2 = 2 * visited[i];
            if (R2 <= patience[i])  k = 0;
            else  k = (R2 % patience[i] == 0) ? R2 - patience[i] : (R2 / patience[i]) * patience[i];
            if (max < R2 + k) max = R2 + k;
        }
        return max + 1;  //所有节点都收到回复的下一时刻，网络空闲下来
    }
};

///可以边做BFS，边记录时间
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> duile;
        vector<int> visited(n, -1);
        int count = 1;
        visited[0] = 0;
        int max = 0;
        int k = 0;
        duile.push(0);
        while (!duile.empty()) {
            int d_size = duile.size();
            for (int i = 0; i < d_size; i++) {
                int temp = duile.front();
                duile.pop();
                for (auto x : adj[temp]) {
                    if (visited[x] == -1) {
                        visited[x] = count;
                        duile.push(x);
                        int R2 = 2 * count;
                        if (R2 <= patience[x])  k = 0;
                        else  k = (R2 % patience[x] == 0) ? R2 - patience[x] : (R2 / patience[x]) * patience[x];
                        if (max < R2 + k) max = R2 + k;
                    }
                }
            }
            count++;
        }

        return max + 1;
    }
};