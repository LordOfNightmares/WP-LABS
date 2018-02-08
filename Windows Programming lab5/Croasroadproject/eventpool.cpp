#include "eventpool.h"
#include <QDebug>
EventPool::EventPool()
{

}
void EventPool::add(int adds)
{
  //qu.push_back(adds);
    state=adds;
}
int EventPool::get()
{//int k=qu.front();
 //qu.pop_front();
 return state;
}
void EventPool::swlights(){
   qDebug()<<get();
}
