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

//2010年，世博会在中国上海举办，吸引了数以千万计的中外游客前来参观。
//暑假期间小Z也来到了上海世博园， 她对世博园的拥挤早有所闻，对有的展馆甚至要排上好几个小时的队才能进入也做好了充分准备，但为了使得自己的世博之旅更加顺利舒畅，小Z决定在游玩之前先 制定一份详细的旅行路线。
//小Z搜集到了世博园的地图，她发现从整体上看世博园是一块非常狭长的区域，而每一个展馆占用了其中一个几乎相同大小的方块。因此可以将整个园区看成一个n × m的矩阵(n≤3)，其中每一个格子为一个主题展馆。
//由于不同展馆受到的关注度会有一些差别，因此排队时间的长短也不尽相同。小Z根据统计信息给每一个展馆(x, y)标记了Tx, y = 0或1，如果Tx, y = 1，表示这个展馆非常热门，需要排很长时间的队；
//如果Tx, y = 0，表示这个展馆相对比较普通，几乎不需要排队即可进入参观。小Z希望能够制定一份合理的路线，使得能交替参观热门馆和普通馆，既不会因为总是参观热门馆 而长时间在排队，也不会因为总是参观普通馆而使得游览过于平淡。
//同时，小Z办事很讲究效率，她希望在游遍所有展馆的同时，又不会走冤枉路浪费体力。因此她希望旅行路线满足以下几个限制：
//在参观完位于(x, y)的展馆后，下一个参观的是一个相邻的且未被参观过的展馆(x', y')，即 | x - x'|+|y-y' |= 1；
//路线的起点位于整个矩阵的边界上，即x = 1或x = n或y = 1或y = m；
//她制定了一个长度为n * m的 01 序列L，她希望第i个参观的展馆(x, y)满足Tx, y = Li。
//小Z想知道有多少条不同的旅行路线能够满足她的要求。
//由于最终的结果可能很大，小Z只想知道可行的旅行路线总数mod 11192869的值。


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