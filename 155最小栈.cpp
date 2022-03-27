//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类 :
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。


////最简单的想法是弄一个辅助栈
//因此我们可以使用一个辅助栈，与元素栈同步插入与删除，用于存储与每个元素对应的最小值。
//当一个元素要入栈时，我们取当前辅助栈的栈顶存储的最小值，与当前元素比较得出最小值，将这个最小值插入辅助栈中；
//当一个元素要出栈时，我们把辅助栈的栈顶元素也一并弹出；
//在任意一个时刻，栈内元素的最小值就存储在辅助栈的栈顶元素中


#include "myhead.h"
class MinStack {
public:
    stack<int> main_stack;
    stack<int> assist_stack;
    MinStack() {
        assist_stack.push(INT_MAX);
    }

    void push(int val) {
        main_stack.push(val);
        assist_stack.push(min(assist_stack.top(), val));
    }

    void pop() {
        if (!main_stack.empty()) {
            main_stack.pop();
            assist_stack.pop();
        }
    }

    int top() {
        return main_stack.top();

    }

    int getMin() {
        return assist_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */