#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> q1(5);
    q1.put(33);
    q1.put(14);
    std::cout << q1;
}
