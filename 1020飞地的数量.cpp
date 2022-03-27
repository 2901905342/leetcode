//����һ����СΪ m x n �Ķ����ƾ��� grid ������ 0 ��ʾһ������Ԫ��1 ��ʾһ��½�ص�Ԫ��
//һ�� �ƶ� ��ָ��һ��½�ص�Ԫ���ߵ���һ�����ڣ��ϡ��¡����ң���½�ص�Ԫ����� grid �ı߽硣
//���������� �޷� ������������ƶ����뿪����߽��½�ص�Ԫ���������

////////////˼·����ԴDFS���Ҿ�����д��û�����⣬����֪��Ϊʲôһֱ��ʱ
#include "myhead.h"
class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 0) return 0;
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) return 1;
        grid[x][y] = 0;  // ����ڵ�
        int flag = dfs(x + 1, y, grid) | dfs(x - 1, y, grid) | dfs(x, y - 1, grid) | dfs(x, y + 1, grid);
        grid[x][y] = 1; //���ݣ������Խڵ�Ĳ���
        return flag;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!dfs(i, j, grid)) res++;
                }
            }
        }
        return res;

    }
};

//////////�ٷ�д��
//���ݷɵصĶ��壬�����һ��½�ص�Ԫ������޷��ƶ�������߽磬�����½�ص�Ԫ���Ƿɵء�
//��˿��Խ�����½�ص�Ԫ��ֳ����ࣺ��һ��½�ص�Ԫ�������߽���������Щ½�ص�Ԫ���Ƿɵأ�
//�ڶ���½�ص�Ԫ�񲻺�����߽���������Щ½�ص�Ԫ���Ƿɵء�
//
//���ǿ��Դ�����߽��ϵ�ÿ��½�ص�Ԫ��ʼ�������������������߽�֮�����к�����߽�������½�ص�Ԫ��Ͷ������ʹ��ˡ�
//Ȼ���������������������е�һ��½�ص�Ԫ��û�б����ʹ������½�ص�Ԫ�񲻺�����ı߽��������Ƿɵء�

class Solution {
public:
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));
        //ֻ�����߽�ĵ�
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        int enclaves = 0;
        ///ֻ�����ڲ��ĵ�
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }

    void dfs(const vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col]) {
            return;
        }
        visited[row][col] = true; //���˵���ĵ��Ѿ������ʹ���
        for (auto& dir : dirs) { 
            dfs(grid, row + dir[0], col + dir[1]);//�ݹ飬���ܵĵ�
        }
    }
private:
    int m, n;
    vector<vector<bool>> visited;
};

///////////ʵ���Ϲٷ��Ľ���˼·��BFSЧ������ĺ�
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
        queue<pair<int, int>> duilie;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (grid[i][0]) {
                visited[i][0] = 1;
                duilie.push(make_pair(i, 0));
            }
            if (grid[i][n - 1]) {
                visited[i][n - 1] = 1;
                duilie.push(make_pair(i, n - 1));
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j]) {
                visited[0][j] = 1;
                duilie.push(make_pair(0, j));
            }
            if (grid[m - 1][j]) {
                visited[m - 1][j] = 1;
                duilie.push(make_pair(m - 1, j));
            }
        }
        while (!duilie.empty()) {
            auto p = duilie.front();
            duilie.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int next_x = dirs[i][0] + p.first;
                int next_y = dirs[i][1] + p.second;
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] && !visited[next_x][next_y]) {
                    duilie.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] && !visited[i][j]) res++;
            }
        }
        return res;
    }
};