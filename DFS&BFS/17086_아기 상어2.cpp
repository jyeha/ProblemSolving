#include <bits/stdc++.h>
using namespace std;

// 모든 상어의 위치에서 bfs
// 최단 거리일 경우 갱신
// 북, 남, 동, 서, 북서, 북동, 남서, 남동
int N, M, answer;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1};

vector<vector<int>> dist;

void bfs(int x, int y, vector<vector<bool>> visited, vector<vector<int>> space) {
	
	queue<vector<int>> q;
	vector<int> v = { x, y, 0 };
	q.push(v);
	visited[x][y] = true;

	while (!q.empty()) {
		int curx = q.front()[0];
		int cury = q.front()[1];
		int curd = q.front()[2];
		q.pop();

		for (int i = 0; i < 8; i++) {
			int newx = curx + dx[i];
			int newy = cury + dy[i];

			if (0 <= newx && newx < N && 0 <= newy && newy < M) {
				if (!visited[newx][newy] && space[newx][newy] == 0) {
					visited[newx][newy] = true;
					dist[newx][newy] = min(dist[newx][newy], curd+1);
					vector<int> v = { newx, newy, curd + 1 };
					q.push(v);
				}
			}
		}
	}

	return;
}

int main() {
	cin >> N >> M;
	vector<vector<int>> space(N, vector<int>(M, 0));
	vector<vector<bool>> visited(N, vector<bool>(M, 0));
	
	for (int i = 0; i < N; i++) {
		vector<int> v;
		for (int j = 0; j < M; j++) {
			v.push_back(10000);
		}
		dist.push_back(v);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				space[i][j] = 1;
				visited[i][j] = 1;
				dist[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (space[i][j] == 1) {
				bfs(i, j, visited, space);
			}
		}
	}

	answer = dist[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] > answer)	answer = dist[i][j];
		}
	}

	

	cout << answer;

	return 0;
}