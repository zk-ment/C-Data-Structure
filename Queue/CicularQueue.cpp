
# 实现循环队列的入队、遍历、出队

#include <iostream>
using std::cout;
using std::endl;
template <typename Type> class Queue {
private:
    Type *data;
    int head, tail, length, count;
public:
    Queue(int length_input) {
        data = new Type[length_input];
        length = length_input;
        head = 0;
        tail = -1;
        count = 0;
    }
    ~Queue() {
        delete[] data;
    }
    bool push(Type element) {
        if (count >= length) {
            return false;
        }
        tail = (tail + 1) % length;
        data[tail] = element;
        count++;
        return true;
    }
    void output() {
        int i = head;
        do {
            cout << data[i] << " ";
            i = (i + 1) % length;
        } while(i != (tail + 1) % length);
        cout << endl;
    }
    Type front() {
        return data[head];
    }
    void pop() {
        head = (head + 1) % length;
        count--;
    }
    bool empty() {
        return count == 0;
    }
};
int main() {
    Queue<int> queue(100); 
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    if (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }
    queue.output();
    return 0;
}