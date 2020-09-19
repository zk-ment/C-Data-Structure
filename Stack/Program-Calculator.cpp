
# 程序设计-逆波兰表达式求值

// 设计的栈可以解决加、减、乘、除四则运算的程序。你需要独立地完成这个程序。

// 输入格式
// 输入一共有两行，第一行为一个整数 m（1≤m≤100），代表表达式中一共有 m 个字符。

// 第二行的输入为一个表达式，表达式中只包含若干个整数以及+，-，*，/四种运算符。

// 输出格式
// 输出只有一行，即输入的表达式的计算结果。最终结果和标准答案的误差在 10^{-3}以内均认为正确。

// 本题答案不唯一，符合要求的答案均正确

// 样例输入
// 7
// 2*3-4/3
// 样例输出
// 4.667

#include<iostream>
#include<string>
#include<cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;
template<typename Type> class Stack {
private:
    Type *elements;
    int max_size, top_index;
public:
    Stack(int size_input) {
        elements = new Type[size_input];
        max_size = size_input;
        top_index = -1;
    }
    ~Stack() {
        delete[] elements;
    }
    bool push(const Type &element) {
        if (top_index >= max_size - 1){
            return false;
        }
        top_index += 1;
        elements[top_index] = element;
        return true;
    }
    bool pop() {
        if (top_index < 0) {
            return false;
        }
        top_index -= 1;
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
bool precede(char a, char b) {
    if ((a == '*' || a == '/') && (b == '+' || b == '-')){
        return true;
    }
    return false;
}
float operate(char oper, float a, float b) {
    float res;
    switch(oper) {
        case '+' : {
            res =  b + a;
            break;
        }
        case '-' : {
            res = b - a;
            break;
        }
        case '*' : {
            res = b * a;
            break;
        }
        case '/' : {
            res = b / a;
            break;
        }
    }
    return res;
}
void calc(Stack<float>& numbers, Stack<char>& operators) {
    float a = numbers.top();
    numbers.pop();
    float b = numbers.top();
    numbers.pop();
    numbers.push(operate(operators.top(), a, b));
    operators.pop();
}
int main() {
    int n;
    cin >> n;
    Stack<float> numbers(n);
    Stack<char> operators(n);
    string buffer;
    cin >> buffer;
    int i = 0;
    while(i < n){
        if (isdigit(buffer[i])) {
            numbers.push(buffer[i] - '0');
            i++;
        } else {
            if (operators.empty() || precede(buffer[i], operators.top())){
                operators.push(buffer[i]);
                i++;
            } else {
                calc(numbers, operators);
            }
            
        }
    }
    while(!operators.empty()){
        calc(numbers, operators);
    }
    cout << numbers.top() << endl;
    return 0;
}