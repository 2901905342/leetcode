//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
//调用 min、push 及 pop 的时间复杂度都是 O(1)。

/////////////思路 ：
////////本题难点： 将 min() 函数复杂度降为 O(1)O(1) ，可通过建立辅助栈实现；
//数据栈 A ： 栈 A 用于存储所有元素，保证入栈 push() 函数、出栈 pop() 函数、获取栈顶 top() 函数的正常逻辑。
//辅助栈 B ： 栈 B 中存储栈 A 中所有 非严格降序 的元素，则栈 A 中的最小元素始终对应栈 B 的栈顶元素，
//即 min() 函数只需返回栈 B 的栈顶元素即可。
//因此，只需设法维护好 栈 BB 的元素，使其保持非严格降序，即可实现 min() 函数的 O(1) 复杂度。

#include "myhead.h"
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A;    //数据栈
    stack<int> B;    //辅助栈
    MinStack() {

    }

    void push(int x) {
        A.push(x);
        if (B.empty()) {
            B.push(x);
        }
        else if (B.top() >= x) {
            B.push(x);
        }
    }

    void pop() {
        if (A.top() == B.top()) {
            B.pop();
        }
        A.pop();
    }

    int top() {
        return A.top();
    }

    int min() {
        return B.top();
    }
};

