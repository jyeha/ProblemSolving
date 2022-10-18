#include <bits/stdc++.h>
using namespace std;

int N, K;
int mintime = 10e9;
bool visited[100001];

void bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();


		// �湮ó��
		visited[cur] = true;

		if (cur == K) {
			// ���� ������ ��ġ���?
			mintime = min(mintime, time);
		}

		int nextcur;

		nextcur = cur - 1;
		if (0 <= nextcur && nextcur <= 100000 && !visited[nextcur]) {
			q.push(make_pair(nextcur, time+1));
		}

		nextcur = cur + 1;
		if (0 <= nextcur && nextcur <= 100000 && !visited[nextcur]) {
			q.push(make_pair(nextcur, time + 1));
		}

		nextcur = 2 * cur;
		if (0 <= nextcur && nextcur <= 100000 && !visited[nextcur]) {
			q.push(make_pair(nextcur, time));
		}
	}
}

int main() {
	cin >> N >> K;

	bfs();

	cout << mintime;
	return 0;
}