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

		// ����
		if (!visited[cur][cur]) {
			visited[cur][cur] = true;
			q.push({ cur, cur, time + 1 });
		}

		// �ٿ��ֱ�
		if (clip > 0 && cur + clip < 1001) {
			if (!visited[cur + clip][clip]) {
				visited[cur + clip][clip] = true;
				q.push({ cur + clip, clip, time + 1 });
			}
		}
		// ����
		if (cur - 1 > 0 && cur - 1 >= 0) {
			if (!visited[cur - 1][clip]) {
				visited[cur - 1][clip] = true;
				q.push({ cur - 1, clip, time + 1 });
			}
		}

	}
}

// ���� ȭ���� �̸�Ƽ�� ���� x, Ŭ�������� �̸�Ƽ�� ���� y
// ���� x , y = x
// �ٿ��ֱ� x*2, y = x
// 1�� ���� x-1, y = x

int main() {
	cin >> S;

	bfs();

	return 0;
}