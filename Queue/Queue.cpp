# 实现队列插入、遍历、出队等功能

// 输入格式
// 输入一共有 3 行，第一行为一个正整数 m（1≤m≤100），代表入队的元素个数。

// 第二行为 m 个整数，表示插入到队列中的元素。

// 第三行为一个整数 n（1≤n<m），表示执行出队操作的次数。

// 输出格式
// 输出一共有 2 行，第一行为执行完所有入队、出队操作后当前队列的队首元素。

// 第二行为最终队列的遍历输出结果，每两个整数之间一个空格，最后一个整数后面没有空格。

// 样例输入
// 5
// 3 1 5 4 2
// 2
// 样例输出
// 5
// 5 4 2

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
template <typename Type> class Queue {
private:
    Type *data;
    int head, tail, length;
public:
    Queue(int length_input) {
        data = new Type[length_input];
        length = length_input;
        head = 0;
        tail = -1;
    }
    ~Queue() {
        delete[] data;
    }
    bool push(Type element) {
        if (length <= tail + 1) return false;
        tail += 1;
        data[tail] = element;
        return true;
    }
    void output() {
        for (int i = head; i <= tail; i++){
            i == head || cout<<" ";
            cout<<data[i];
        }
        cout<<endl;
    }
    Type front() {
        return data[head];
    }
    void pop() {
        head += 1;
    }
    bool empty() {
        return head > tail;
    }
};
int main() {
    // 请在此处完成代码
    int n;
    cin>>n;
    Queue<int> queue(n);
    int tmp;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        queue.push(tmp);
    }
    int m;
    cin>>m;
    while(m--){
        queue.pop();
    }
    cout<<queue.front()<<endl;
    queue.output();
    return 0;
}
