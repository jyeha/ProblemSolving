#include <bits/stdc++.h>
using namespace std;

// 1000*100000 = 100000000;
// int ���� ������ �ذ� ����
int main() {
	int N, cnt = 0;

	// pq�� ������������
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		pq.push(a + b);
		cnt += (a+b);
	}

	cout << cnt;


	return 0;
}