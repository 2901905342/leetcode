//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false


////////////思路////
//使用栈来模式队列的行为，如果仅仅用一个栈，是一定不行的，所以需要两个栈一个输入栈，一个输出栈，
//这里要注意输入栈和输出栈的关系。
//在push数据的时候，只要数据放进输入栈就好，但在pop的时候，操作就复杂一些，输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入），
// 再从出栈弹出数据，如果输出栈不为空，则直接从出栈弹出数据就可以了。
//最后如何判断队列为空呢？如果进栈和出栈都为空的话，说明模拟的队列为空了

#include "myhead.h"

class MyQueue {
public:
    stack<int>inque;  //输入栈
    stack<int>outque; //输出栈
    MyQueue() {

    }

    void push(int x) {
        inque.push(x);
    }

    int pop() {
        //当输出栈为空的时候，需要将输入栈中的元素依次出栈放入输出栈中
        if (outque.empty()) {  
            while (!inque.empty()) {
                outque.push(inque.top());
                inque.pop();
            }
        }
        int res = outque.top();//获取输出栈栈顶元素
        outque.pop(); //输出栈栈顶元素出栈
        return res;
    }


    int peek() {
        if (outque.empty()) {
            while (!inque.empty()) {
                outque.push(inque.top());
                inque.pop();
            }
        }
        int res = outque.top();
        return res;
    }
        ////由于peek与pop的功能和代码实现上类似，可以思考一下如何把代码抽象一下。
    //    int res = this->pop(); // 直接使用已有的pop函数
    //    outque.push(res); // 因为pop函数弹出了元素res，所以再添加回去
    //    return res;
  

    bool empty() {
        if (inque.empty() && outque.empty()) return true;
        return false;

    }
};
