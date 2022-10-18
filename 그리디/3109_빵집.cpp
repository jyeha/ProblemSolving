#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int R, C;
int dx[3] = {1, 1, 1};
int dy[3] = { -1, 0, 1 };
bool arrive = false;

vector<string> _map;
vector<vector<bool>> visited;

void dfs(int x, int y) {
	// 마지막 열에 도달
	if (x == C-1) {
		cnt++;
		arrive = true;
		return;
	}

	for (int i = 0; i < 3; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < C && 0 <= ny && ny < R && _map[ny][nx] == '.' && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(nx, ny);
			// 해당 시작점에서 끝에 도달하면 다른 루트 계산X
			if (arrive)	return;
		}

	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		_map.push_back(s);
	}

	for (int i = 0; i < R; i++) {
		vector<bool> v;
		for (int j = 0; j < C; j++) {
			if (_map[i][j] == '.')	v.push_back(false);
			else v.push_back(true);
		}
		visited.push_back(v);
	}

	for (int i = 0; i < R; i++) {
		arrive = false;
		dfs(0, i);
	}

	cout << cnt;
	return 0;
}