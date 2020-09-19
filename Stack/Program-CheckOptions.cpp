
# 程序设计-判断栈操作序列是否合法

// 蒜头君有一台神奇的魔法机，它能将输入的序列进行一系列复杂的变换，输出原序列的另一种排列方式。蒜头君十分好奇魔法机的工作原理，终于有一天他尝试着把魔法机拆开研究了。

// 通过一系列复杂的演算，蒜头君终于发现了魔法机的工作原理：其实魔法机就是一个栈，根据栈先进后出的性质，每次一个数字进栈或将栈顶元素弹出，由此可以产生不同的出栈序列，出栈序列就是原序列的另一种排列了。

// 在研究完原理后，蒜头君凭借记忆很快就把魔法机组装好了。现在蒜头君想测试下魔法机在组装完成后是否出现问题。

// 首先他将 1 到 N 这 N 个数字依次输入魔法机里，然后随机写下一组序列a，现在他想知道能否通过魔法机得到序列a，聪明的你能帮蒜头君算一算吗？

// 输入格式
// 输入有两行，第一行是一个正整数 N (1≤N≤100)，表示输入魔法机序列的长度，第二行是序列a，共有 N 个整数，表示要得到的目标序列。

// 序列为 1 到 N 的排列，即序列a长度为 N，保证序列中的整数都不相同，且整数在区间 [1, N] 内。

// 输出格式
// 输出一行，如果能通过魔法机得到序列a，则输出YES，否则输出NO。

// 样例输入复制
// 5
// 2 1 5 4 3
// 样例输出复制
// YES

#include <iostream>

using namespace std;

template <typename Type> class Stack{
private:
    Type *data;
    int max_size, top_index;
public:
    Stack(int length_input){
        data = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack(){
        delete[] data;
    }
    bool push(const Type &value){
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index ++;
        data[top_index] = value;
        return true;
    }
    Type top(){
        return data[top_index];
    }
    void pop(){
        // assert(top_index >= max_size);
        top_index -= 1;
    }
    bool empty(){
        return top_index < 0;
    }
};

int main() {
    int n;
    cin >> n;
    Stack<int> stackop(n);
    Stack<int> stackans(n);
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        stackop.push(tmp);
    }
    int k = n;
    while(!stackop.empty()){
        while (! stackans.empty() && stackop.top() < stackans.top()){
            if (stackans.top() != k) {
                cout << "NO" << endl;
                return 0;
            }
            k--;
            stackans.pop();
        }
        stackans.push(stackop.top());
        stackop.pop();
    }
    while (! stackans.empty()){
        if (stackans.top() != k) {
            cout << "NO" << endl;
            return 0;
        }
        k--;
        stackans.pop();
    }
    cout << "YES" << endl;
    return 0;
}