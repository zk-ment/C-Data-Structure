
# 实现链表的构造、插入、遍历、删除、反转

// 输入格式
// 第一行输入为一个正整数 m（1≤m≤100），代表一共有 m 个操作。

// 接下来一共输入 m 行，每行首先输入一个整数 t，代表着以下几种操作：

// t = 1，代表执行插入操作，此时还需输入两个整数 a 和 b（0≤a,b≤100），代表在位置 a 上插入值为 b 的元素，成功插入输出success，否则输出failed。
// t = 2，代表执行遍历操作，此时程序顺序输出链表的所有元素。
// t = 3，代表执行删除操作，此时还需输入一个整数 a（0≤a≤100），表示删除位置 a 上的元素，如果成功删除则输出success，否则输出failed。
// t = 4，代表执行反转链表的操作，在执行了反转操作之后，还会有其他的操作来验证你的程序是否正确的完成了链表的反转。
// 输出格式
// 输出的结果取决于每组输入的数据。在遍历输出链表时，每个元素后面跟一个空格。对于操作 1 和操作 3，操作成功输出success，否则输出failed。每次操作的输出各占一行。

// 样例输入
// 9
// 1 0 1
// 1 0 2
// 1 0 3
// 2
// 4
// 2
// 3 3
// 3 0
// 2
// 样例输出
// success
// success
// success
// 3 2 1
// 1 2 3
// failed
// success
// 2 3


#include <iostream>
#include<iostream>
using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type &_data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type> *head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    bool insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return false;
            }
            head = node;
            return true;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return true;
        }
        Node<Type> *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
            return true;
        }
        return false;
    }
    void output() {
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    int delete_node(int index) {
        if (head == NULL) {
            return false;
        }
        Node<Type> *current_node = head;
        if (index == 0){
            head = head -> next;
            delete current_node;
            return true;
        }
        int cnt = 0;
        while(current_node -> next != NULL && cnt < index - 1){
            current_node = current_node -> next;
            cnt++;
        }
        if (cnt == index - 1 && current_node -> next != NULL) {
            Node<Type> *delete_node = current_node -> next;
            current_node ->next = delete_node -> next;
            delete delete_node;
            return true;
        }
        return false;
    }
    void reverse() {
        if (head == NULL) {
            return ;
        }
        Node<Type> *current_node, *next_node;
        current_node = head -> next;
        head -> next = NULL;
        while(current_node != NULL){
            next_node = current_node -> next;
            current_node -> next = head;
            head = current_node;
            current_node = next_node;
        }
    }
};
int main() {
    LinkedList<int> linkedlist;
    int n;
    cin>>n;
    int tmp;
    while (n--){
        cin>>tmp;
        if (tmp == 1) {
            int index, value;
            cin>>index>>value;
            Node<int> *node = new Node<int>(value);
            bool flag = linkedlist.insert(node, index);
            if (flag) {
                cout<<"success"<<endl;
            } else {
                cout<<"failed"<<endl;
            }
        } else if (tmp == 2) {
            linkedlist.output();
        } else if (tmp == 3) {
            int index;
            cin>>index;
            int flag = linkedlist.delete_node(index);
            if (flag) {
                cout<<"success"<<endl;
            } else {
                cout<<"failed"<<endl;
            }
        } else {
            linkedlist.reverse();
        }
    }
    return 0;
}