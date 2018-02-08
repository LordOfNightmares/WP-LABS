#ifndef EVENTPOOL_H
#define EVENTPOOL_H

#include <deque>
using namespace std;
class EventPool
{
public:
    deque<int> qu;
    int state;
    const static int L1_RED = 0;
    const static int GO = 1;
    EventPool();
    void add(int);
    int get();

    void swlights();
};

#endif // EVENTPOOL_H
