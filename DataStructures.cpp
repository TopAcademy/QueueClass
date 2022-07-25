#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> q1(5);
    q1.put(33);
    q1.put(14);
    q1.put(88);
    q1.put(24);
    q1.put(32);
    q1.show();
    //std::cout << q1;
}
