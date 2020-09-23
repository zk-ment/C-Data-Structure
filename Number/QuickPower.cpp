#include <iostream>
#include <windows.h>

using namespace std;

#define MAX_N 1000000007

int main() {
    long long n, po;
    cin >> n >> po;
    DWORD start_time = GetTickCount();
    long long res1 = 1;
    for (long long i = 1; i <= po; i++) {
        res1 = ((res1 % MAX_N) * (n % MAX_N)) % MAX_N;
    }
    DWORD end_time = GetTickCount();
    cout << "#1 The run time is:" << (end_time - start_time) << "ms!" << endl;
    cout << "#1 The result is:" << res1 << endl;
    cout << endl;
    start_time = GetTickCount();
    long long res2 = 1;
    while (po > 0) {
        if (po % 2 == 0) {
            po /= 2;
            n = (n % MAX_N) * (n % MAX_N);
        } else {
            po -= 1;
            res2 = ((res2 % MAX_N) * (n % MAX_N)) % MAX_N;
            po /= 2;
            n = (n % MAX_N) * (n % MAX_N);
        }
    }
    end_time = GetTickCount();
    cout << "#2 The run time is:" << (end_time - start_time) << "ms!" << endl;
    cout << "#2 The result is:" << res2 << endl;

    return 0;
}

// 知识点参考链接：https://blog.csdn.net/qq_19782019/article/details/85621386
