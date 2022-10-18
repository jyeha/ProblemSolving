#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, answer = 0;
	priority_queue<int> plus, zero;
	priority_queue<int, vector<int>, greater<int>> minus;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n > 0)	plus.push(n);
		else if (n < 0)	minus.push(n);
		else zero.push(n);
	}

	// 양수
	while (!plus.empty()) {
		int a, b;
		if (plus.size() >= 2) {
			a = plus.top();
			plus.pop();
			b = plus.top();
			plus.pop();

			// 둘 중 하나가 1이면 더하는 게 이득
			if (a == 1 || b == 1) answer += (a + b);
			else answer += a * b;
		}
		else {
			a = plus.top();
			plus.pop();
			answer += a;
		}
	}

	// 음수
	while (!minus.empty()) {
		int a, b;
		if (minus.size() >= 2) {
			a = minus.top();
			minus.pop();
			b = minus.top();
			minus.pop();

			answer += a * b;
		}
		else {
			if (!zero.empty()) {
				minus.pop();
			}
			else {
				a = minus.top();
				minus.pop();
				answer += a;
			}
		}
	}

	cout << answer;

	// 양의 정수: 큰거 우선으로 곱. 1일 경우 더하는 게 이득
	// 음의 정수: 작은거 우선으로 곱. 남은게 홀수일 경우 곱하지 않고 더하거나 0과 곱이 이득
	// 0: 그냥 더하거나, 음수와 곱


	return 0;
}