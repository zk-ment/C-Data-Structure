
# 已知前序遍历和中序遍历求后续遍历

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        cout << data << " ";
    }
    // 请在下面实现建立二叉树的方法 build
	Node* build(const string &pre_str, const string &in_str, int len){
        Node *p = new Node(pre_str[0] - '0');
        int pos = in_str.find(pre_str[0]);
        if (pos > 0){
            p -> lchild = build(pre_str.substr(1, pos), in_str.substr(0, pos), pos);
        }
        if (len - pos - 1 > 0){
            p -> rchild = build(pre_str.substr(pos + 1), in_str.substr(pos + 1), len - pos - 1);
        }
        return p;
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        delete root;
    }
    // 请在下面实现构造函数
	BinaryTree(const string &pre_str, const string &in_str, int len){
        root = root -> build(pre_str, in_str, len);
    }
    void postorder() {
        root->postorder();
    }
};
int main() {
    string pre_str = "136945827";
    string in_str = "963548127";
	BinaryTree binarytree(pre_str, in_str, in_str.length());
    binarytree.postorder();
    cout << endl;
    return 0;
}