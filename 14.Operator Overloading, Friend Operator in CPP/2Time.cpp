#include <iostream>
using namespace std;
class Time
{
    int hr, min, sec;

public:
    void normalise()
    {
        min += sec / 60;
        sec = sec % 60;
        hr += min / 60;
        min = min % 60;
    }
    friend istream &operator>>(istream &, Time &);
    friend ostream &operator<<(ostream &, Time);
};
istream &operator>>(istream &din, Time &t)
{
    cout << "Enter values of time in hour, minute and second: ";
    din >> t.hr >> t.min >> t.sec;
    t.normalise();
    return din;
}
ostream &operator<<(ostream &dout, Time t)
{
    dout << endl;
    dout << "Time = " << t.hr << ":" << t.min << ":" << t.sec;
    return dout;
}
int main()
{
    Time t1, t2;
    cin >> t1>>t2;  //is call ke vajah se return karwaana hai din ko;
    cout << t1<<t2; //is call ke vajah se return karwaana hai dout ko;
    return 0;
}