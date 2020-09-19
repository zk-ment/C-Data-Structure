
# 程序设计-附加头节点方式实现双向循环链表

// 已知有一个单向循环链表，其每个结点中含三个域：prior，data 和 next，其中 data 域为数据域，next 为指向后继结点的指针域，prior 也为指针域,但它的值为空 (NULL) ，试编写算法将此单向循环链表改为双向循环链表，即使 prior 成为指向前驱结点的指针域。

// 输入格式
// 输入共有三行，第一行为该单向循环链表的长度 n（1≤n≤60）；第二行为该单向循环链表的各个元素 a_i（1≤a_i≤1000），它们各不相同且都为数字；第三行为一个数字 m，表示链表中的一个元素值，要求输出时以该元素为起点反向输出整个双向链表。

// 输出格式
// 输出为一行，即完成双向链表后以反向顺序输出该链表，每两个整数之间一个空格，最后一个整数后面没有空格。

// 样例输入
// 5
// 1 2 3 4 6
// 1
// 样例输出
// 1 6 4 3 2

#include <iostream>
using namespace std;

template <typename Type> class Node{
public:
    Type data;
    Node<Type> *prior;
    Node<Type> *next;
    
    Node(const Type &_data){
        data = _data;
        prior = NULL;
        next = NULL;
    }
};

template <typename Type> class LinkedList{
private:
    Node<Type> *head;
public:
    LinkedList(){
        head = new Node<Type>(0);
        head -> next = head;
        head -> prior = head;
    }
    ~LinkedList(){
        Node<Type> *current_node = head -> next;
        while (current_node != head){
            Node<Type> *delete_node = current_node;
            current_node = current_node -> next;
            delete delete_node;
        }
        delete head;
    }
    Node<Type> *location(int index, int direction){
        if (head -> next == head || index == 0){
            return head;
        }
        Node<Type> *current_node;
        if (direction == 0){
            current_node = head -> prior;
        } else {
            current_node = head -> next;
        }
        int cnt = 0;
        while(current_node != head && cnt < index - 1){
            if (direction == 0) {
                current_node = current_node -> prior;
            } else {
                current_node = current_node -> next;
            }
            cnt ++;
        }
        if (cnt == index - 1 && current_node != head){
            return current_node;
        } else {
            return NULL;
        }
    }
    int getIndex(Type value){
        if (head -> next == head) {
            return -1;
        }
        Node<Type> *current_node = head -> next;
        int cnt = 0;
        while(current_node != head && current_node -> data != value){
            current_node = current_node -> next;
            cnt++;
        }
        if (current_node -> data == value){
            return cnt;
        }
        return -1;
    }
    void insert(Node<Type> *node, int index, int direction){
        
        Node<Type> *current_node = location(index, direction);
        if (current_node == NULL) return ;
        if (direction == 0){
            node -> prior = current_node -> prior;
            node -> prior -> next = node;
            node -> next = current_node;
            current_node -> prior = node;
        } else {
            node -> next = current_node -> next;
            node -> next -> prior = node;
            node -> prior = current_node;
            current_node -> next = node;
        }
    }
    void print(Type value){
        int idx = getIndex(value);
        if (idx == -1) {
            return ;
        }
        // cout<<idx<<endl;
        Node<Type> *current_node = location(idx, 1) -> next;
        Node<Type> *node_se = current_node -> prior;
        cout<<current_node -> data;
        while(node_se != current_node){
            if (node_se == head) {
                node_se = node_se -> prior;
                continue;
            }
            cout<<" "<<node_se -> data;
            node_se = node_se -> prior;
        }
        cout<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    LinkedList<int> linkedlist;
    int tmp;
    for (int i = 0; i < n; i++){
        cin>>tmp;
        Node<int> *node = new Node<int>(tmp);
        linkedlist.insert(node, i, 1);
    }
    int target;
    cin>>target;
    linkedlist.print(target);
    return 0;
}