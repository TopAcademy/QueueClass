#include <iostream>
#include "queue.h"
using std::cout;
using std::endl;

int main()
{
    Queue<int> q1(5);
    q1 << 33 << 14 << 88;
    q1.show();
    
    //cout << q1.get() << endl;
    //cout << q1.get() << endl;
    int x;
    cout << (q1 >> x) << endl;
    cout << (q1 >> x) << endl;
    q1.show();
    q1 << 99;
    cout << q1;
}
