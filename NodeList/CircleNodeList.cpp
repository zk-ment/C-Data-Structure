
# 循环链表实现约瑟夫环

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
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
        if (head == NULL) {
            return;
        }
        Node<Type> *current_node = head->next;
        head->next = NULL;
        while (current_node != NULL) {
            Node<Type> *delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    void insert(Node<Type> *node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return ;
            }
            head = node;
            head->next = head;
            return;
        }
        if (index == 0) {
            node->next = head->next;
            head->next = node;
            return;
        }
        Node<Type> *current_node = head->next;
        int count = 0;
        while (current_node != head && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
        if (node == head->next) {
            head = node;
        }
    }
    // 请在下面实现输出方法 output_josephus
    void output_josephus(int m) {
        Node<Type> *current_node = head;
        head = NULL;
        while(current_node -> next != current_node) {
            for (int i = 1; i < m; i++){
                current_node = current_node -> next;
            }
            cout<<current_node -> next -> data<<" ";
            Node<Type> *delete_node = current_node -> next;
            current_node -> next = current_node -> next -> next;
            delete delete_node;
        }
        cout<<current_node -> data<<endl;
        delete current_node;
    }
};
int main() {
    LinkedList<int> linkedlist;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        Node<int> *node = new Node<int>(i);
        linkedlist.insert(node, i - 1);
    }
    linkedlist.output_josephus(m);
    return 0;
}