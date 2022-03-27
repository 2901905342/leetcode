//���Լ����Ӣ�greatest common divisor��gcd������ѧ�ʻ㣬ָ�ܹ�������������������������
//һ����շת����������������ȡ�����ظ����������ֱ������Ϊ0ʱ��ǰһ��������Ϊ���Լ����


//1.whileѭ�������٣�
//�˶δ���a��b����Ϊ0
//�����㷨
int gcd(int a, int b)  
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//2.��Ŀ��������Ͽ죩
//�˶δ���a��b����Ϊ0

int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}

//3.λ���㣨���죩
//�˶δ���a��b����Ϊ0

int gcd(int a, int b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}

//4.if + while + λ���㣨���죩
//�˶δ���a��b����Ϊ0
 int gcd(int a, int b)
{
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}

//5.շת��������Ͽ죩  �ݹ��㷨
//�˶δ���a��b����Ϊ0
 int gcd(int a, int b)
 {
     if (a % b == 0)
         return b;
     else return (gcd(b, a % b));
 }

 //6.gcd�⺯����������
 //    �˶δ���a��b����Ϊ0
 // ��ֵ����飺�ҵ�algorithm�Ⲣ����ʶ��_gcd�⺯��
//#include <algorithm>
// inline int gcd(int a, int b) {
//     return __gcd(a, b);
