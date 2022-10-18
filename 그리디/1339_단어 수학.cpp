#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool cmp(int a, int b) {
	if (a == b)	return a > b;
	else return a > b;
}

// 각 알파벳이 숫자 몇을 나타낼 수 있는지 저장
// 이후 지정한 0~9까지의 수를 곱하여 최종값에 더하기

int main() {
	int N, answer = 0, num = 9;
	vector<string> words;
	vector<int> alpha(26, 0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string w;
		cin >> w;
		words.push_back(w);
	}

	for (int i = 0; i < N; i++) {
		string w = words[i];
		int e = 1;
		for (int j = w.length()-1; j >= 0; j--) {
			int idx = w[j] - 'A';
			alpha[idx] += e;
			e *= 10;
		}
	}

	sort(alpha.begin(), alpha.end(), cmp);

	for (int i = 0; i < 10; i++) {
		answer += alpha[i] * num;
		num--;
	}

	cout << answer;


	return 0;
}