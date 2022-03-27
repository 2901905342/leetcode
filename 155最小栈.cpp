//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У�
//���� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��

/////////////˼· ��
////////�����ѵ㣺 �� min() �������ӶȽ�Ϊ O(1)O(1) ����ͨ����������ջʵ�֣�
//����ջ A �� ջ A ���ڴ洢����Ԫ�أ���֤��ջ push() ��������ջ pop() ��������ȡջ�� top() �����������߼���
//����ջ B �� ջ B �д洢ջ A ������ ���ϸ��� ��Ԫ�أ���ջ A �е���СԪ��ʼ�ն�Ӧջ B ��ջ��Ԫ�أ�
//�� min() ����ֻ�践��ջ B ��ջ��Ԫ�ؼ��ɡ�
//��ˣ�ֻ���跨ά���� ջ BB ��Ԫ�أ�ʹ�䱣�ַ��ϸ��򣬼���ʵ�� min() ������ O(1) ���Ӷȡ�

#include "myhead.h"
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A;    //����ջ
    stack<int> B;    //����ջ
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

