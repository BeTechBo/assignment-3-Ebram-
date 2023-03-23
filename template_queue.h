#ifndef template_queue // the quard to make sure no redifination happens
#define template_queue
#include <cstdlib>
template <typename T> class queue{
T *qu;
int front, rear, counterQ, maxS;
public:
queue();
~queue();
bool isEmpty();
bool isFull();
void enqueue(T); 
T dequeue();
};
#endif 