#include <iostream>
using namespace std;
class Array
{
private:
    int *p;
    public:
    int size;

public:
    Array()
    {

    }
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
    friend Array* operator+(Array,Array);
    ~Array()
    {
        delete[] p;
    }
    
};
    Array* operator+(Array a1,Array a2)
{
    Array *arrptr=new Array();
    arrptr->size=a1.size+a2.size;
    arrptr->p=new int[arrptr->size];
    int i,k;
    for(i=0,k=0;i<a1.size;i++,k++)
        arrptr->p[k]=a1.p[i];
    for(i=0;i<a2.size;i++,k++)
        arrptr->p[k]=a2.p[i];
    return arrptr;
}
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
    cout << "Enter the size of the array: ";
    cin >> size;
    Array a(size);
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    Array *b=arr+a;
     cout << "Resultant array after addition: ";
    for (int i = 0; i < b->size; i++)
    {
        cout << (*b)[i] << " ";
    }

    return 0;
}