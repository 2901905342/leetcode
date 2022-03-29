//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��

//////˼·������ʲô�۶��ӣ�ֱ��˫�˶���////////////

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
