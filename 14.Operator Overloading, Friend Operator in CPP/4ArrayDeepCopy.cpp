#include <iostream>
using namespace std;
class Array
{
private:
    int *p;
    int size;

public:
    Array(int s)
    {
        size = s;
        p = new int[size];
    }
    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return p[index];
        }
        cout << "Invalid array index";
        return p[0]; // this is not ideal but we have to return something of int& so in this we can do exception handling.
    }
    Array operator=(const Array arr)
    {
        size=arr.size;
        p=new int[size];
        for(int i=0;i<size;i++)
        {
            p[i]=arr.p[i];
        }
        return *this;
    }
    ~Array()
    {
        delete[] p;
    }
};
int main()
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    Array arr(size);
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    Array a=arr;
    cout << "Elements of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}