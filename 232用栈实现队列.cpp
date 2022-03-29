//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false


////////////˼·////
//ʹ��ջ��ģʽ���е���Ϊ�����������һ��ջ����һ�����еģ�������Ҫ����ջһ������ջ��һ�����ջ��
//����Ҫע������ջ�����ջ�Ĺ�ϵ��
//��push���ݵ�ʱ��ֻҪ���ݷŽ�����ջ�ͺã�����pop��ʱ�򣬲����͸���һЩ�����ջ���Ϊ�գ��Ͱѽ�ջ����ȫ�����������ע����ȫ�����룩��
// �ٴӳ�ջ�������ݣ�������ջ��Ϊ�գ���ֱ�Ӵӳ�ջ�������ݾͿ����ˡ�
//�������ж϶���Ϊ���أ������ջ�ͳ�ջ��Ϊ�յĻ���˵��ģ��Ķ���Ϊ����

#include "myhead.h"

class MyQueue {
public:
    stack<int>inque;  //����ջ
    stack<int>outque; //���ջ
    MyQueue() {

    }

    void push(int x) {
        inque.push(x);
    }

    int pop() {
        //�����ջΪ�յ�ʱ����Ҫ������ջ�е�Ԫ�����γ�ջ�������ջ��
        if (outque.empty()) {  
            while (!inque.empty()) {
                outque.push(inque.top());
                inque.pop();
            }
        }
        int res = outque.top();//��ȡ���ջջ��Ԫ��
        outque.pop(); //���ջջ��Ԫ�س�ջ
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
        ////����peek��pop�Ĺ��ܺʹ���ʵ�������ƣ�����˼��һ����ΰѴ������һ�¡�
    //    int res = this->pop(); // ֱ��ʹ�����е�pop����
    //    outque.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
    //    return res;
  

    bool empty() {
        if (inque.empty() && outque.empty()) return true;
        return false;

    }
};
