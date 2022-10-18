#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)	return a.second < b.second;
	else return a.second < b.second;
}

int main() {
	int T, N;
	vector<int> answer;
	cin >> T;

	for (int i = 0; i < T; i++) {
		// 각 테스트케이스
		cin >> N;

		int cnt = 0;
		vector<pair<int, int>> score;
		// 테케 입력받기
		for (int j = 0; j < N; j++) {
			int a, b;
			cin >> a >> b;
			score.push_back(make_pair(a, b));
		}

		// 서류 결과로 정렬
		sort(score.begin(), score.end());
		int a_score = score[0].second;
		//cnt++;

		//for (int j = 0; j < N; j++) {
		//	if (score[j].second < a_score) {
		//		a_score = score[j].second;
		//		cnt++;
		//	}
		//}

		// 면접 결과로 정렬
		sort(score.begin(), score.end(), cmp);
		int b_score = score[0].first;

		for (int j = 0; j < N; j++) {
			if (score[j].first <= b_score && score[j].second <= a_score) {
				cnt++;
			}
		}

		answer.push_back(cnt);
	}

	for (int i = 0; i < T; i++) {
		cout << answer[i];
		if (i < T - 1)	cout << endl;
	}


	return 0;
}