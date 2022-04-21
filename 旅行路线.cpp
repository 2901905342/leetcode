#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& space, vector<vector<int>>& visited, vector<vector<int>>& dir, vector<int>& Li, int& n, int& m, int path, int& res, int x, int y) {
	if (path == n * m - 1) {
		res = (res + 1) % 11192869;
	}
	for (auto temp : dir) {
		int next_x = x + temp[0];
		int next_y = y + temp[1];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && visited[next_x][next_y] == 0 && space[next_x][next_y] == Li[path + 1]) {
			visited[next_x][next_y] = 1;
			dfs(space, visited, dir, Li, n, m, path + 1, res, next_x, next_y);
			visited[next_x][next_y] = 0;
		}
	}

};
int main() {
	vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0} };
	int n, m;
	cin >> n >> m;
	vector<vector<int>>space(n, vector<int>(m));

	vector<int>Li(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
		}
	}
	for (int i = 0; i < n * m; i++) {
		cin >> Li[i];
	}
	vector<vector<int>>starts = { {0,0},{0,m - 1},{n - 1,0},{n - 1,m - 1} };
	int res = 0;
	for (auto start : starts) {
		int x = start[0];
		int y = start[1];
		vector<vector<int>>visited(n, vector<int>(m));
		if (space[x][y] == Li[0]) {
			visited[x][y] = 1;
			int path = 0;
			dfs(space, visited, dir, Li, n, m, path, res, x, y);
		}

	}
	cout << res << endl;
	return 0;
}

//2010�꣬���������й��Ϻ��ٰ죬����������ǧ��Ƶ������ο�ǰ���ιۡ�
//����ڼ�СZҲ�������Ϻ�����԰�� ��������԰��ӵ���������ţ����е�չ������Ҫ���Ϻü���Сʱ�ĶӲ��ܽ���Ҳ�����˳��׼������Ϊ��ʹ���Լ�������֮�ø���˳���泩��СZ����������֮ǰ�� �ƶ�һ����ϸ������·�ߡ�
//СZ�Ѽ���������԰�ĵ�ͼ�������ִ������Ͽ�����԰��һ��ǳ����������򣬶�ÿһ��չ��ռ��������һ��������ͬ��С�ķ��顣��˿��Խ�����԰������һ��n �� m�ľ���(n��3)������ÿһ������Ϊһ������չ�ݡ�
//���ڲ�ͬչ���ܵ��Ĺ�ע�Ȼ���һЩ�������Ŷ�ʱ��ĳ���Ҳ������ͬ��СZ����ͳ����Ϣ��ÿһ��չ��(x, y)�����Tx, y = 0��1�����Tx, y = 1����ʾ���չ�ݷǳ����ţ���Ҫ�źܳ�ʱ��Ķӣ�
//���Tx, y = 0����ʾ���չ����ԱȽ���ͨ����������Ҫ�ŶӼ��ɽ���ιۡ�СZϣ���ܹ��ƶ�һ�ݺ����·�ߣ�ʹ���ܽ���ι����Źݺ���ͨ�ݣ��Ȳ�����Ϊ���ǲι����Ź� ����ʱ�����Ŷӣ�Ҳ������Ϊ���ǲι���ͨ�ݶ�ʹ����������ƽ����
//ͬʱ��СZ���ºܽ���Ч�ʣ���ϣ�����α�����չ�ݵ�ͬʱ���ֲ�����ԩ��·�˷������������ϣ������·���������¼������ƣ�
//�ڲι���λ��(x, y)��չ�ݺ���һ���ι۵���һ�����ڵ���δ���ι۹���չ��(x', y')���� | x - x'|+|y-y' |= 1��
//·�ߵ����λ����������ı߽��ϣ���x = 1��x = n��y = 1��y = m��
//���ƶ���һ������Ϊn * m�� 01 ����L����ϣ����i���ι۵�չ��(x, y)����Tx, y = Li��
//СZ��֪���ж�������ͬ������·���ܹ���������Ҫ��
//�������յĽ�����ܴܺ�СZֻ��֪�����е�����·������mod 11192869��ֵ��


#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& space, vector<vector<int>>& visited, vector<vector<int>>& dir, vector<int>& Li, int& n, int& m, int path, int& res, int x, int y) {
	if (path == n * m - 1) {
		res = (res + 1) % 11192869;
	}
	for (auto temp : dir) {
		int next_x = x + temp[0];
		int next_y = y + temp[1];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && visited[next_x][next_y] == 0 && space[next_x][next_y] == Li[path + 1]) {
			visited[next_x][next_y] = 1;
			dfs(space, visited, dir, Li, n, m, path + 1, res, next_x, next_y);
			visited[next_x][next_y] = 0;
		}
	}

};
int main() {
	vector<vector<int>>dir = { {0,1},{0,-1},{1,0},{-1,0} };
	int n, m;
	cin >> n >> m;
	vector<vector<int>>space(n, vector<int>(m));

	vector<int>Li(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
		}
	}
	for (int i = 0; i < n * m; i++) {
		cin >> Li[i];
	}
	//vector<vector<int>>starts={{0,0},{0,m-1},{n-1,0},{n-1,m-1}};
	vector<vector<int>>starts;
	for (int j = 0; j < m; j++) {
		starts.push_back({ 0,j });
		starts.push_back({ n - 1,j });
	}
	for (int i = 1; i < n - 1; i++) {
		starts.push_back({ i,0 });
		starts.push_back({ i,m - 1 });
	}

	int res = 0;
	for (auto start : starts) {
		int x = start[0];
		int y = start[1];
		vector<vector<int>>visited(n, vector<int>(m));
		if (space[x][y] == Li[0]) {
			visited[x][y] = 1;
			int path = 0;
			dfs(space, visited, dir, Li, n, m, path, res, x, y);
		}

	}
	cout << res << endl;
	return 0;
}