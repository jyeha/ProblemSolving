#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];
int mintime = 10e9, cnt = 0;

void bfs() {
	
	// 언제 방문 처리?
	// 큐에서 pop 할때
	// push할때 방문처리를 한다면 n==k가 되는 bfs가 실행 불가능

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();

		visited[cur] = true;

		if (cur == K) {
			// 동생을 잡으면 min time인지? 
			if (mintime > time) {
				// 첫방문이면
				mintime = time;
				cnt = 1;
			}
			else if (mintime == time) {
				// 첫방문이 아니면
				cnt++;
			}
			else {
				// 최소가 아니면 무시
			}
		}

		// x+1
		int nextcur = cur - 1;
		if (0<=(cur-1) && (cur-1)<=100000 && !visited[cur-1]) {
			q.push(make_pair(cur - 1, time + 1));
		}
		// x-1
		if (0 <= (cur + 1) && (cur + 1) <= 100000 && !visited[cur + 1]) {
			q.push(make_pair(cur + 1, time + 1));
		}
		// 2x
		if (0 <= (2 * cur) && (2 * cur) <= 100000 && !visited[2 * cur]) {
			q.push(make_pair(2 * cur, time + 1));
		}

	}

}

int main() {
	cin >> N >> K;

	bfs();

	cout << mintime << endl;
	cout << cnt;

	return 0;
}