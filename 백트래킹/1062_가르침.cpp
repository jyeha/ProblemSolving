#include <bits/stdc++.h>
using namespace std;

vector<bool> learn(26, 0);
vector<string> words;
int answer = 0;
string alphabets = "abcdefghijklmnopqrstuvwxyz";

int canread() {
	int count = 0;
	for (string word:words) {
		bool check = true;
		for (int i = 0; i < word.length(); i++) {
			if (!learn[word[i] - 'a']) {
				// ���ڸ� ����� �ʾ��� = ���� �� ����
				check = false;
			}
		}
		if (check)	count++;
	}

	return count;
}

void dfs(int K, int cnt, int idx) {
	if (cnt == K) {
		int readword = canread();
		answer = max(readword, answer);
	}

	for (int i = idx; i < 26; i++) {
		if (learn[i])	continue;
		learn[i] = true;
		dfs(K, cnt+1, i);
		learn[i] = false;
	}
}

int main() {
	int N, K, m = 0;
	cin >> N >> K;

	if (K < 5) {
		cout << "0";
		return 0;
	}

	vector<char> alphabets;

	// a, c, i, n, t �� �ݵ�� �������
	learn['a' - 'a'] = true;
	learn['c' - 'a'] = true;
	learn['i' - 'a'] = true;
	learn['n' - 'a'] = true;
	learn['t' - 'a'] = true;

	// �ܾ� �Է¹ޱ�, �� �ܾ ���� ���ĺ� 1������ ����� ����
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		sort(str.begin(), str.end());

		string word = "";
		char c = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] != c) {
				word.push_back(str[j]);
				c = str[j];
			}
		}
		words.push_back(word);
	}

	dfs(K-5, 0, 0);

	cout << answer;

	return 0;
}