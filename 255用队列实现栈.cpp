//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

//////思路：不搞什么幺儿子，直接双端队列////////////

#include "myhead.h"

class MyStack {
public:
    deque<int> line;
    MyStack() {
    }
    void push(int x) {
        line.push_back(x);
    }

    int pop() {
        int res = line.back();
        line.pop_back();
        return res;
    }

    int top() {
        return line.back();
    }

    bool empty() {
        return line.empty();
    }
};
