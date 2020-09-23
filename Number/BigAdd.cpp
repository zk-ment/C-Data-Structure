#include <iostream>
#include <algorithm>
#include <vector>

// 大整数加法

// 整体思路：建立一个数字数组，第一位存放位数，第二位开始存放个位、十位、百位。。。

using namespace std;

int main() {

    string s1, s2;
    int n1[1005] = {0}, n2[1005] = {0};

    cin >> s1 >> s2;
    n1[0] = s1.size();
    n2[0] = s2.size();

    for (int i = 1, j = s1.size() - 1; i <= n1[0]; i++, j--) {
        n1[i] = s1[j] - '0';
    }

    for (int i = 1, j = s2.size() - 1; i <= n2[0]; i++, j--) {
        n2[i] = s2[j] - '0';
    }
    n1[0] = max(n1[0], n2[0]);
    for (int i = 1; i <= n1[0]; i++) {
        n1[i] += n2[i];
        if (n1[i] >= 10) {
            n1[i + 1] += n1[i] / 10;
            n1[i] %= 10;
            if (i == n1[0]) {
                n1[0]++;
            }
        }
    }
    for (int i = n1[0]; i >= 1; i--) {
        cout << n1[i];
    }
    cout << endl;
    return 0;
}
