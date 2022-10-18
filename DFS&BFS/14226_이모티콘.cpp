#include <bits/stdc++.h>
using namespace std;

int S;
bool visited[1001][1001];

int mintime = 10e9;

struct emo {
	int emoticon;
	int clipboard;
	int time;
};

void bfs() {

	queue<emo> q;
	q.push({ 1, 0, 0 });

	while (!q.empty()) {
		int cur = q.front().emoticon;
		int clip = q.front().clipboard;
		int time = q.front().time;
		q.pop();

		if (cur == S) {
			cout << time;
			return;
		}

		// 복사
		if (!visited[cur][cur]) {
			visited[cur][cur] = true;
			q.push({ cur, cur, time + 1 });
		}

		// 붙여넣기
		if (clip > 0 && cur + clip < 1001) {
			if (!visited[cur + clip][clip]) {
				visited[cur + clip][clip] = true;
				q.push({ cur + clip, clip, time + 1 });
			}
		}
		// 삭제
		if (cur - 1 > 0 && cur - 1 >= 0) {
			if (!visited[cur - 1][clip]) {
				visited[cur - 1][clip] = true;
				q.push({ cur - 1, clip, time + 1 });
			}
		}

	}
}

// 현재 화면의 이모티콘 개수 x, 클립보드의 이모티콘 개수 y
// 복사 x , y = x
// 붙여넣기 x*2, y = x
// 1개 삭제 x-1, y = x

int main() {
	cin >> S;

	bfs();

	return 0;
}