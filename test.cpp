#include <deque>
#include <iostream>
using namespace std;
void debug(deque<int> q)
{
    deque<int>::iterator i;
    for (i = q.begin(); i <= q.end(); i++)
        cout << *i << " ";
    cout << endl;
    return;
}
int main()
{
    deque<int> a{1, 2, 3, 4, 5}, b{1, 2, 3}; // 声明两个vector变量a,b
    deque<int>::iterator i, j;
    i = a.begin();                                // begin函数返回第一个元素的迭代器
    j = a.end();                                  // end函数返回最后一个元素的迭代器
    int n = a.size();                             // size函数返回容器大小
    cout << a.front() << " " << a.back() << endl; // front和back函数返回容器中第一个和最后一个元素
    if (a.empty() == false)
    {                     // empty函数返回一个bool值，用以确定容器非空
        a.push_back(101); // push_back函数在队列尾部插入一个元素
        a.pop_back();
        debug(a);          // pop_back函数在队列尾弹出一个元素
        a.push_front(102); // push_front函数在队列头插入一个元素
        a.pop_front();     // pop_front函数在队列头弹出一个元素
        debug(a);
        debug(b);
        b.clear();  // 清空b容器中的所有元素
        swap(a, b); // 交换a,b容器中的内容
    }
    for (i = b.begin(); i <= b.end(); i++)
        cout << *i << " ";
    cout << endl;
    return 0;
}
