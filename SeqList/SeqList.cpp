
# 实现顺序表的构造、插入、扩容、查找、删除、遍历

// 题目要求
// 我们已经建立好了一个容量为 20 的顺序表，你需要对其执行一系列的操作。

// 输入格式
// 第一行输入一个正整数 m（1≤m≤100），代表一共有 m 个操作。

// 接下来输入 m 行，每行首先输入一个整数 t，分别代表以下操作：

// t = 1，代表插入操作，输入两个整数 a 和 b（0 ≤a,b ≤100），表示在 a 的位置上擦入元素 b，如果插入成功输出success，否则输出failed。
// t = 2，代表删除操作，输入一个整数 a（0≤a≤100），删除位置 a 上的元素，如果删除成功输出success，否则输出failed。
// t = 3，代表查找操作，输入一个整数 a（0≤a≤100），查找元素值为 a 的元素，如果查找成功输出success，否则输出failed。
// t = 4，代表遍历操作，输出当前顺序表的所有元素。
// 输出格式
// 对应每个操作，输出结果。对于前三个操作，如果操作成功输出success，否则输出failed；对于第四个操作，从下标为 0 的位置开始输出当前顺序表的所有元素，每两个整数之间一个空格，最后一个整数后面没有空格。

// 样例输入
// 9
// 1 0 1
// 1 5 2
// 1 1 2
// 1 2 3
// 3 2
// 2 2
// 2 9
// 3 3
// 4
// 样例输出
// success
// failed
// success
// success
// success
// success
// failed
// failed
// 1 2

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size;
    int length;
    Type *data;
public:
    Vector(int init_size) {
        size = init_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        
    }
    bool insert(int loc, Type value) {
        if (loc > length || loc < 0){
            return false;
        }
        if (length == size){
            expand();
        }
        for (int i = length; i > loc; i--){
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        Type *old_data = data;
        size *= 2;
        data = new Type[size];
        for (int i = 0; i < length; i++){
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
    bool search(const Type &value) {
        for (int i = 0; i < length; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }
    bool remove(int loc) {
        if (loc < 0 || loc >= length) {
            return false;
        }
        for (int i = loc + 1; i < length; i++){
            data[i - 1] = data[i];
        }
        length -= 1;
        return true;
    }
    void print() {
        for (int i = 0; i < length; i++) {
            i == 0 || cout<<" ";
            cout<<data[i];
        }
        cout<<endl;
    }
};
int main() {
    Vector<int> v(20);
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        switch(t){
            case 1:{
                int a, b;
                cin>>a>>b;
                bool flag = v.insert(a, b);
                flag ? cout<<"success"<<endl : cout<<"failed"<<endl;
                break;
            }   
            case 2:{
                int a;
                cin>>a;
                bool flag = v.remove(a);
                flag ? cout<<"success"<<endl : cout<<"failed"<<endl;
                break;
            }   
            case 3:{
                int a;
                cin>>a;
                bool flag = v.search(a);
                flag ? cout<<"success"<<endl : cout<<"failed"<<endl;
                break;
            } 
            case 4:{
                v.print();
                break;
            }  
        }
    }
    return 0;
}
