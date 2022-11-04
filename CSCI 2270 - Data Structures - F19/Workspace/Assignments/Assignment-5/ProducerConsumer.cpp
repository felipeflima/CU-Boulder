#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std;

ProducerConsumer::ProducerConsumer()
{
  queueFront = 0;
  queueEnd = 0;
}

bool ProducerConsumer::isEmpty()
{
  if (counter == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool ProducerConsumer::isFull()
{
  if (counter == SIZE)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void ProducerConsumer::enqueue(string item)
{
  if (!isFull())
  {
    if (!isEmpty())
    {
      queue[queueEnd] = item;
      if(queueEnd == SIZE-1)
      {
        queueEnd = 0;
      }
      else
      {
        queueEnd++;
      }
      counter++;
    }
    else
    {
      queue[queueEnd] = item;
      queueEnd++;
      counter++;
    }
  }
  else
  {
    cout << "Queue full, cannot add new item" << endl;
  }
}

void ProducerConsumer::dequeue()
{
  if (isEmpty())
  {
    cout << "Queue empty, cannot dequeue an item" << endl;
    return;
  }
  else
  {
    queue[queueFront] = "";
    if (queueFront == SIZE-1)
    {
      queueFront = 0;
    }
    else
    {
      queueFront++;
    }
    counter--;
  }
}

int ProducerConsumer::queueSize()
{
  return counter;
}

string ProducerConsumer::peek()
{
  if (isEmpty())
  {
    cout << "Queue empty, cannot peek" << endl;
    return "";
  }
  else
  {
    return queue[queueFront];
  }
}
