#include <bits/stdc++.h>
using namespace std;

int max_value = -10e9-1;
int min_value = 10e9+1;
int N; vector<int> a; string oper = "";
vector<bool> visited;
string ans = "";


int calculate() {
	int result = a[0];
	for (int i = 0; i < N - 1; i++) {
		if (ans[i] == '+') {
			result += a[i + 1];
		}
		else if (ans[i] == '-') {
			result -= a[i + 1];
		}
		else if (ans[i] == 'x') {
			result *= a[i + 1];
		}
		else if (ans[i] == '%') {
			result /= a[i + 1];
		}
	}

	return result;
}

void dfs(int cnt) {
	if (cnt == N-1) {
		//cout << ans << endl;
		int value = calculate();

		max_value = max(max_value, value);
		min_value = min(min_value, value);

		return;
	}
	for (int i = 0; i < N - 1; i++) {
		if (visited[i])	continue;

		visited[i] = true;
		ans.push_back(oper[i]);
		dfs(cnt+1);
		visited[i] = false;
		ans.pop_back();
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int nn;
		cin >> nn;
		a.push_back(nn);
	}

	for (int i = 0; i < 4; i++) {
		int nn;
		cin >> nn;
		for (int j = 0; j < nn; j++) {
			if (i == 0)	oper.push_back('+');
			if (i == 1) oper.push_back('-');
			if (i == 2)	oper.push_back('x');
			if (i == 3) oper.push_back('%');
		}
	}

	for (int i = 0; i < N - 1; i++) {
		visited.push_back(false);
	}

	// oper 내의 문자들을 순열구하기
	dfs(0);

	cout << max_value << endl;
	cout << min_value;

	return 0;
}