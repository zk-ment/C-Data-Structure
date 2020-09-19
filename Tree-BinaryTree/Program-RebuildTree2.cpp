
# 程序设计-广义表重建二叉树/输出广义表，复习手写栈

// 编写递归算法，对于二叉树中每一个元素值data等于x的节点，删去以它为根的子树，并释放相应的空间。

// 树的结构以广义表的形式给出。如A(B,)表示一颗有2个节点的树。其中根的data值为A，其左孩子为叶子节点，data值为B，右孩子为空。

// 输入格式
// 输入有两行，第一行为以广义表的形式给出的树形结构，长度在区间 [0,30) 内，均由大写字母和左右括号组成，每个结点由一个大写字母组成，互不相同。第二行为待删除子树根结点的元素值x，为一个大写字母。

// 输出格式
// 输出有一行，为原树删除子树后的广义表达式。

// 若找不到该元素，则不做删除操作直接输出广义表达式。

// 样例输入
// A(B,C)
// B
// 样例输出
// A(,C)

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

template <typename Type> class Stack{
public:
    Type *data;
    int max_size, top_index;
    Stack(int length_input){
        data = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack(){
        delete[] data;
    }
    bool push(const Type &_data){
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index ++;
        data[top_index] = _data;
        return true;
    }
    Type top(){
        return data[top_index];
    }
    void pop(){
        top_index--;
    }
    bool empty(){
        return top_index < 0;
    }
};

class Node{
public:
    char data;
    Node *lchild;
    Node *rchild;
    Node(const char &_data){
        data = _data;
        lchild = nullptr;
        rchild = nullptr;
    }
    ~Node(){
        if (lchild != nullptr) {
            delete lchild;
        }
        if (rchild != nullptr) {
            delete rchild;
        }
    }
    void ToStr() {
        
        cout << data;
        if (lchild != nullptr || rchild != nullptr) {
            cout << "(";
        }
        if (lchild != nullptr) {
            lchild -> ToStr();
        }
        if (rchild != nullptr) {
            cout << ",";
            rchild -> ToStr();
        }
        if (lchild != nullptr || rchild != nullptr) {
            cout << ")";
        }
    }
    void dete(const char &_data){
        if (lchild != nullptr) {
            if (lchild -> data == _data) {
                Node *de = lchild;
                lchild = nullptr;
                delete de;
                return ;
            } else {
                lchild -> dete(_data);
            }
        }
        if (rchild != nullptr) {
            if (rchild -> data == _data) {
                Node *de = rchild;
                rchild = nullptr;
                delete de;
                return ;
            } else {
                rchild -> dete(_data);
            }
        }
    }
    void preorder(){
        cout << data;
        if (lchild != nullptr) {
            lchild -> preorder();
        }
        if (rchild != nullptr) {
            rchild -> preorder();
        }
    }
};

class BinaryTree{
private:
    Node *root;
public:
    BinaryTree(){
        root = nullptr;
    }
    ~BinaryTree(){
        delete root;
    }
    void buildtree(const string &buffer){
        int n = buffer.length();
        if (n == 0) {
            return ;
        }
        Stack<Node*> stack(n);
        int i = 0;
        int k = -1;
        Node *p = nullptr;
        while (i < n){
            if (buffer[i] == '(') {
                if (p != nullptr) {
                    k = 0;
                    stack.push(p);
                    p = nullptr;
                }
            } else if (buffer[i] == ',') {
                k = 1;
            } else if (buffer[i] == ')') {
                stack.pop();
            } else {
                p = new Node(buffer[i]);
                if (root == nullptr) {
                    root = p;
                } else {
                    if (k == 0) {
                        stack.top() -> lchild = p;
                    } else if (k == 1) {
                        stack.top() -> rchild = p;
                    }
                }
            }
            i++;
        }
    }
    void delete_node(const char &_data){
        if (root == nullptr) {
            return ;
        }
        if (root -> data == _data) {
            Node *de = root;
            root = nullptr;
            delete de;
        } else {
            root -> dete(_data);
        }
    }
    void TreetoStr(){
        if (root == nullptr) {
            return ;
        }
        root -> ToStr();
        cout << endl;
    }
    void preorder() {
        if (root == nullptr) {
            return ;
        }
        root -> preorder();
        cout << endl;
    }
};

int main() {
    // char *buffer = new char;
    // scanf("%s\n", buffer);
    string buffer;
    getline(cin, buffer);
    BinaryTree binarytree;
    binarytree.buildtree(buffer);
    // binarytree.preorder();
    char dt;
    cin >> dt;
    // cout << dt << endl;
    binarytree.delete_node(dt);
    binarytree.TreetoStr();
    return 0;
}