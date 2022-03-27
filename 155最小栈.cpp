//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//ʵ�� MinStack �� :
//MinStack() ��ʼ����ջ����
//void push(int val) ��Ԫ��val�����ջ��
//void pop() ɾ����ջ������Ԫ�ء�
//int top() ��ȡ��ջ������Ԫ�ء�
//int getMin() ��ȡ��ջ�е���СԪ�ء�


////��򵥵��뷨��Ūһ������ջ
//������ǿ���ʹ��һ������ջ����Ԫ��ջͬ��������ɾ�������ڴ洢��ÿ��Ԫ�ض�Ӧ����Сֵ��
//��һ��Ԫ��Ҫ��ջʱ������ȡ��ǰ����ջ��ջ���洢����Сֵ���뵱ǰԪ�رȽϵó���Сֵ���������Сֵ���븨��ջ�У�
//��һ��Ԫ��Ҫ��ջʱ�����ǰѸ���ջ��ջ��Ԫ��Ҳһ��������
//������һ��ʱ�̣�ջ��Ԫ�ص���Сֵ�ʹ洢�ڸ���ջ��ջ��Ԫ����


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