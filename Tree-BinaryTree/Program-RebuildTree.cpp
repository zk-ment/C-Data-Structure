
# 程序设计-已知前序遍历和中序遍历求后续遍历（外加镜像树的后序遍历）

// 蒜头君最近在学习二叉树，可是心不在焉的他一会儿就学累了，于是他想休息会儿。蒜头君拿出镜子，对着镜子中的自己各种卖萌。蒜头君无意间看见镜子中出现了一棵二叉树，这不是他刚画的那棵二叉树么，在镜子里怎么左右颠倒了呀。

// 蒜头君觉得好神奇，于是他又随手画了一棵二叉树，他想知道这棵二叉树在镜子里是长什么样的。为了将问题简单，现在蒜头君告诉你这棵二叉树的先序遍历结果和中序遍历结果，求原始二叉树的后序遍历结果，以及镜子里的二叉树的后序遍历结果。

// 输入格式
// 输入第一行是一个字符串pre_str，代表原始二叉树的先序遍历结果；输入第二行是一个字符串in_str，代表二叉树的中序遍历结果。每个字符代表结点的编号，结点的编号互不相同，字符仅由大小写字母组成。保证两个字符串长度相等，长度最大不超过 50，且保证可以通过先序遍历结果和中序遍历结果构造出一棵唯一的二叉树。

// 输出格式
// 输出第一行，输出一个字符串，代表原始二叉树的后序遍历结果；

// 输出第二行，输出一个字符串，代表镜子里的二叉树的后序遍历结果。

// 样例输入
// abdce
// dbaec
// 样例输出
// dbeca
// ecdba

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    char data;
    Node *lchild, *rchild;
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
    Node* build (const string &pre_str, const string &in_str, int len) {
        Node *p = new Node(pre_str[0]);
        int pos = in_str.find(pre_str[0]);
        if (pos > 0) {
            p -> lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
        }
        if (len - pos - 1 > 0){
            p -> rchild = build(pre_str.substr(pos + 1), in_str.substr(pos + 1), len - pos - 1);
        }
        return p;
    }
    void postorder() {
        if (lchild != nullptr) {
            lchild -> postorder();
        }
        if (rchild != nullptr) {
            rchild -> postorder();
        }
        cout << data;
    }
    void reverse(){
        if (lchild != nullptr) {
            lchild -> reverse();
        }
        if (rchild != nullptr) {
            rchild -> reverse();
        }
        Node *tmp = lchild;
        lchild = rchild;
        rchild = tmp;
    }
};

class BinaryTree {
private:
    Node *root;
public:
    BinaryTree(){
        root = nullptr;
    }
    ~BinaryTree(){
        delete root;
    }
    BinaryTree(const string &pre_str, const string &in_str, int len){
        root = root -> build(pre_str, in_str, len);
    }
    void postorder() {
        root -> postorder();
    }
    
    void reverse(){
        if (root == nullptr) {
            return ;
        }
        root -> reverse();
    }
};

// BinaryTree* Reverse(BinaryTree *root)

int main() {
    string pre_str, in_str;
    cin >> pre_str;
    cin >> in_str;
    BinaryTree binarytree(pre_str, in_str, in_str.length());
    binarytree.postorder();
    cout << endl;
    binarytree.reverse();
    binarytree.postorder();
    cout << endl;
    return 0;
}