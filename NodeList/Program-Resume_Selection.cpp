
# 程序设计-链表实现简历筛选

// 蒜头君想把计算机专业相关的课程都写一遍，放到计蒜客上面帮助同学们学习。但是蒜头君意识到要写的课程有很多很多，蒜头君实在忙不过来，于是他想招几位实习生帮助一块写课程。招聘广告一发，吸引了好多大牛前来应聘，于是蒜头君每天都要安排面试。
// 有一天，结束了一天面试后，boss 跑来问蒜头君：“小蒜，你觉得今天面试的同学里面，谁最优秀呀，谁最适合写课程呀？”蒜头君递给 boss 一沓简历，回答到：“这里有 N 份简历，boss 你猜猜哪位同学最优秀。”
// 每份简历都有一个对应的 id，编号从 1 开始，依次从第一份简历到最后一份简历。boss 会从简历里抽掉 M 份简历，每次他随机念一个数字 num_i，然后从第一份简历开始数，数到第 num_i份时，就会把对应的简历抽掉，接着念下一个数字。抽掉 M 份简历后，boss 从剩余的简历中，取出最中间的一份简历，然后点点头念道：“我相信这位同学一定最优秀，哈哈”。
// 现在蒜头君想知道这份简历的 idid 是多少，聪明的你能帮他算出来吗？

// 输入格式
// 第一行输入两个正整数 N 和 M（1≤M<N≤1000）。第二行输入 M 个整数 num_i 1≤num_i≤1000），表示 boss 依次念出来的数字。
// 保证 N−M 是奇数，输入的 num_i小于等于当前剩余简历数量。

// 输出格式
// 输出为一行，输出 boss 认为最优秀的同学的 id 是多少。

// 样例输入
// 7 2
// 2 4
// 样例输出
// 4

#include <iostream>
using namespace std;

template <typename Type> class Node {
public:
    Type data;
    Node<Type> *next;
    Node(const Type value) {
        data = value;
        next = NULL;
    }
};

template <typename Type> class LinkedList{
private:
    Node<Type> *head;
public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        if (head == NULL) {
            return ;
        }
        Node<Type> *current_node = head;
        while(current_node != NULL){
            Node<Type> *delete_node = current_node;
            current_node = current_node -> next;
            delete delete_node;
        }
    }
    void insert(Node<Type> *node, int index){
        if (head == NULL){
            if (index != 0){
                return ;
            }
            head = node;
            return ;
        }
        if (index == 0){
            node -> next = head;
            head = node;
            return ;
        }
        Node<Type> *current_node = head;
        int cnt = 0;
        while(current_node -> next != NULL && cnt < index - 1){
            current_node = current_node -> next;
            cnt++;
        }
        if (cnt == index - 1) {
            node -> next = current_node -> next;
            current_node -> next = node;
        }
    }
    void remove(int index){
        if (head == NULL) {
            return ;
        }
        Node<Type> *current_node = head;
        if (index == 0){
            head = head -> next;
            delete current_node;
            return ;
        }
        int cnt = 0;
        while(current_node -> next != NULL && cnt < index - 1){
            current_node = current_node -> next;
            cnt++;
        }
        if (cnt == index - 1 && current_node -> next != NULL){
            Node<Type> *delete_node = current_node -> next;
            current_node -> next = delete_node -> next;
            delete delete_node;
        }
    }
    void getmid(int k){
        Node<Type> *current_node = head;
        int cnt = 0;
        while(current_node -> next != NULL && cnt < k){
            current_node = current_node -> next;
            cnt++;
        }
        cout<<current_node -> data<<endl;
    }
    void print(){
        Node<Type> *current_node = head;
        while(current_node != NULL){
            current_node == head || cout<<" ";
            cout<<current_node -> data;
            current_node = current_node -> next;
        }
        cout<<endl;
    }
};

int main() {
    
    int n, m;
    cin>>n>>m;
    LinkedList<int> linkedlist;
    for (int i = 1; i <= n; i++){
        Node<int> *node = new Node<int>(i);
        linkedlist.insert(node, i - 1);
    }
    // linkedlist.print();
    int tmp;
    for (int i = 0; i < m; i++){
        cin>>tmp;
        linkedlist.remove(tmp - 1);
        // linkedlist.print();
    }
    linkedlist.getmid((n - m) / 2);
    return 0;
}