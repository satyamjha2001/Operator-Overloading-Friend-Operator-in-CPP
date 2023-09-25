#include<iostream>
using namespace std;
class Complex
{
    int a,b;
    public:
    void setData(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    void showData()
    {
        cout<<"a= "<<a<<" b= "<<b<<endl;
    }
    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);
    friend Complex operator*(Complex, Complex);

};
    Complex operator+(Complex C,Complex D)
    {
        Complex temp;
        temp.a=C.a+D.a;
        temp.b=C.b+D.b;
        return temp;
    }
    Complex operator-(Complex C,Complex D)
    {
        Complex temp;
        temp.a=C.a-D.a;
        temp.b=C.b-D.b;
        return temp;
    }
    Complex operator*(Complex C,Complex D)
    {
        Complex temp;
        temp.a=C.a*D.a-C.b*D.b;
        temp.b=C.a*D.b+C.b*D.a;
        return temp;
    }
int main() {
Complex c1,c2,c3,c4,c5;
c1.setData(3,4);
c2.setData(3,4);
c3=c1+c2;
c4=c1-c2;
c5=c1*c2;
c1.showData();
c2.showData();
c3.showData();
c4.showData();
c5.showData();
return 0;
}