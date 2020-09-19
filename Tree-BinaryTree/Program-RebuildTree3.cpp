
# 程序设计-字符串序列递归重建二叉树/输出广义表，复习手写队列

// 假设用顺序表来表示一棵完全二叉树。从根到叶结点按层次从 1 开始编号，同一层次从左到右编号，数据存储在对应的数组元素中。试编写算法由此顺序存储结构建立该二叉树的二叉链表。

// 输入格式
// 输入只有一行，为顺序输入的从根节点开始的各个节点元素，它们之间用空格隔开，整个输入以 $ 结束。

// 输出格式
// 输出有一行，为二叉树结构的广义表达式。

// 样例输入
// A B C D $
// 样例输出
// A(B(D),C)

#include <iostream>
using namespace std;

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
    bool push(const Type &_data) {
        if (tail >= length - 1) {
            return false;
        }
        tail+=1;
        data[tail] = _data;
        return true;
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
    int size() {
        return tail + 1 - head;
    }
};

class Node{
public:
    char data;
    Node *lchild, *rchild;
    Node(const char &_data){
        data = _data;
        lchild = nullptr;
        rchild = nullptr;
    }
    ~Node() {
        if (lchild != nullptr) {
            delete lchild;
        }
        if (rchild != nullptr) {
            delete rchild;
        }
    }
    void outnode() {
        cout << data;
        if (lchild != nullptr || rchild != nullptr) {
            cout << "(";
        }
        if (lchild != nullptr) {
            lchild -> outnode();
        }
        if (rchild != nullptr) {
            cout << ",";
            rchild -> outnode();
        }
        if (lchild != nullptr || rchild != nullptr) {
            cout << ")";
        }
    }
};

class BinaryTree {
private:
    Node *root;
public:
    BinaryTree(){
        root = nullptr;
    }
    ~BinaryTree() {
        delete root;
    }
    void buildtree(const string &buffer){
        Node *tmp = nullptr;
        Queue<Node*> queue(buffer.length());
        int i = 0;
        while (i < buffer.length()) {
            if (i == 0) {
                tmp = new Node(buffer[i]);
                root = tmp;
                queue.push(root);
                i++;
            } else {
                int len = queue.size();
                while(i < buffer.length() && len--){
                    tmp = new Node(buffer[i]);
                    queue.front() -> lchild = tmp;
                    queue.push(queue.front() -> lchild);
                    i++;
                    if (i < buffer.length()) {
                        tmp = new Node(buffer[i]);
                        queue.front() -> rchild = tmp;
                        queue.push(queue.front() -> rchild);
                        i++;
                    }
                    queue.pop();
                }
            }
            // outtree();
        }
    }
    void outtree() {
        if (root == nullptr) {
            return ;
        }
        root -> outnode();
        cout << endl;
    }
};

int main() {
    string buffer_raw;
    string buffer = "";
    getline(cin, buffer_raw);
    for (int i = 0; i < buffer_raw.length(); i++){
        if (isalpha(buffer_raw[i])) {
            buffer += buffer_raw[i];
        }
    }
    // cout << buffer << endl;
    BinaryTree binarytree;
    binarytree.buildtree(buffer);
    binarytree.outtree();
    return 0;
}