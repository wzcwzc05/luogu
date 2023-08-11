#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str("HelloWorld");
    string str1("iloveyou");
    int len=str.length(); // 返回str字符串的长度
    str.append(str1, 3, 4); // 将str1字符串的第三个位置开始的四个字符添加到str字符串的末尾

    int pos1 = str.find("Hello");   // 返回str1字符串"Hello"中第一次出现的位置
    int pos2 = str.find("love", 1); // 返回str1字符串从第二个位置开始查找"love"中第一次出现的位置

    str.replace(1, 3, "love"); // 将str字符串从第二个位置开始的三个字符替换为"love"

    str.erase(1, 3); // 将str字符串从第二个位置开始的三个字符删除

    str.insert(1, "love"); // 将"love"插入到str字符串的第二个位置
    str.insert(5, 2, 'a'); // 将两个'a'插入到str字符串的第六个位置

    string str3=str.substr(1,3); // 返回str字符串从第二个位置开始的三个字符

    return 0;
}
