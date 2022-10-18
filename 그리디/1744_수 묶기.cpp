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

	// ���
	while (!plus.empty()) {
		int a, b;
		if (plus.size() >= 2) {
			a = plus.top();
			plus.pop();
			b = plus.top();
			plus.pop();

			// �� �� �ϳ��� 1�̸� ���ϴ� �� �̵�
			if (a == 1 || b == 1) answer += (a + b);
			else answer += a * b;
		}
		else {
			a = plus.top();
			plus.pop();
			answer += a;
		}
	}

	// ����
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

	// ���� ����: ū�� �켱���� ��. 1�� ��� ���ϴ� �� �̵�
	// ���� ����: ������ �켱���� ��. ������ Ȧ���� ��� ������ �ʰ� ���ϰų� 0�� ���� �̵�
	// 0: �׳� ���ϰų�, ������ ��


	return 0;
}