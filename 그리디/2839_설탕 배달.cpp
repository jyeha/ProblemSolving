#include <bits/stdc++.h>
using namespace std;

int solution() {
    int n, answer = 0;
    // Nkg 입력
    cin >> n;

    while (n >= 0) {
        // n이 5로 나누어 떨어지는가?
        if (n % 5 == 0) {
            // Yes : 그럼 Nkg을 모두 5로 나누면 되는구나
            // or n==0일 경우이니까 가능하므로 답을 출력
            answer += n / 5;
            cout << answer;;
            return 0;
        }
        // 만약 5로 나누어 떨어지지 않으면?
        // 일단 3kg으로 하나 가져가고 다시 5kg으로 다 가져갈 수 있는지 계산
        n -= 3;
        answer++;
    }

    // 빠져나왔다는 건 5kg와 3kg로는 설탕을 모두 나눌 수 없음
    cout << -1;


    //// 그리디
    //answer += (n / 5);
    //int mod = n % 5;

    //if (mod % 3 != 0) {
    //    // 그리디로는 불가능
    //    // 3의 배수인지 확인
    //    if (n % 3 == 0) {
    //        cout << n / 3;
    //    }
    //    else cout << "-1";
    //}
    //else {
    //    // 그리디가 가능 or 5의 배수
    //    answer += n / 3;
    //    cout << answer;
    //}

    return 0;
}