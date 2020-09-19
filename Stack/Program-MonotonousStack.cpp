
# 程序设计-单调栈实现木板倒水问题

#include<iostream>
#include<cassert>
using std::cin;
using std::cout;
using std::endl;
class Node {
public:
    int id, height;
};
template<typename Type> class Stack {
private:
    Type *elements;
    int max_size, top_index;
public:
    Stack(int length_input) {
        elements = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack() {
        delete[] elements;
    }
    bool push(const Type &element) {
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index++;
        elements[top_index] = element;
        return true;
    }
    bool pop() {
        if (top_index < 0) {
            return false;
        }
        top_index--;
        return true;
    }
    Type top() {
        assert(top_index >= 0);
        return elements[top_index];
    }
    bool empty() {
        return top_index < 0;
    }
};
int main() {
    int n, ans = 0;
    cin >> n;
    Stack<Node> stack(n);
    Node temp;
    for (int i = 1; i <= n; i++){
        cin >> temp.height;
        temp.id = i;
        while(!stack.empty() && stack.top().height <= temp.height){
            ans = ans + i - stack.top().id - 1;
            stack.pop();
        }
        stack.push(temp);
    }
    while(!stack.empty()){
        ans = ans + n + 1 - stack.top().id - 1;
        stack.pop();
    }
    cout << ans << endl;
    return 0;
}