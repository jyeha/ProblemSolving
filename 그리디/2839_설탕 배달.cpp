#include <bits/stdc++.h>
using namespace std;

int solution() {
    int n, answer = 0;
    // Nkg �Է�
    cin >> n;

    while (n >= 0) {
        // n�� 5�� ������ �������°�?
        if (n % 5 == 0) {
            // Yes : �׷� Nkg�� ��� 5�� ������ �Ǵ±���
            // or n==0�� ����̴ϱ� �����ϹǷ� ���� ���
            answer += n / 5;
            cout << answer;;
            return 0;
        }
        // ���� 5�� ������ �������� ������?
        // �ϴ� 3kg���� �ϳ� �������� �ٽ� 5kg���� �� ������ �� �ִ��� ���
        n -= 3;
        answer++;
    }

    // �������Դٴ� �� 5kg�� 3kg�δ� ������ ��� ���� �� ����
    cout << -1;


    //// �׸���
    //answer += (n / 5);
    //int mod = n % 5;

    //if (mod % 3 != 0) {
    //    // �׸���δ� �Ұ���
    //    // 3�� ������� Ȯ��
    //    if (n % 3 == 0) {
    //        cout << n / 3;
    //    }
    //    else cout << "-1";
    //}
    //else {
    //    // �׸��� ���� or 5�� ���
    //    answer += n / 3;
    //    cout << answer;
    //}

    return 0;
}