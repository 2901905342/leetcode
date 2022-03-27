//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 - 1)

////////////////// 思路：
/////维持双栈，A负责入栈，B负责出栈

#include "myhead.h"
class CQueue {
public:
    stack<int> A;
    stack<int> B;
    CQueue() {

    }
    void appendTail(int value) {
        A.push(value);
    }
    int deleteHead() {
        if (A.empty() && B.empty()) return -1;  //当A B都为空时，返回-1
        if (!B.empty()) {           //当B不为空时，直接出栈
            int res = B.top();
            B.pop();
            return res;
        }
        while (!A.empty()) {    //当B为空时，将此事A中所有的元素出栈并压入B中，
            B.push(A.top());
            A.pop();
        }
        int res = B.top();  //B出栈
        B.pop();
        return res;
    }
};