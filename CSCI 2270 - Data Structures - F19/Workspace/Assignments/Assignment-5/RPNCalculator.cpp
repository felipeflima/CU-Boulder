#include "RPNCalculator.hpp"
#include <iostream>
using namespace std;

RPNCalculator::RPNCalculator()
{
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
    while(!isEmpty())
        pop();
}

bool RPNCalculator::isEmpty()
{
  if (stackHead == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }

}

void RPNCalculator::push(float num)
{
    Operand* newnum = new Operand;
    newnum->number = num;
    newnum->next = NULL;
    newnum->next = stackHead;
    stackHead = newnum;
}

void RPNCalculator::pop()
{
    if(!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else
    {
        cout<<"Stack empty, cannot pop an item."<<endl;
        return;
    }
}

Operand* RPNCalculator::peek()
{
    if(!isEmpty())
        return stackHead;
    else{
        cout<<"Stack empty, cannot peek."<<endl;
        return NULL;
    }
  //return 0;
}

bool RPNCalculator::compute(string symbol)
{
  float one;
  float two;
  float add;
  float mult;
  if (isEmpty())
  {
    cout << "err: not enough operands" << endl;
    return false;
  }
  Operand* fnum = peek();
  one = fnum->number;
  pop();
  if (isEmpty())
  {
    cout << "test" << endl;
    cout << "err: not enough operands" << endl;
    push(one);
    return false;
  }
  if (symbol != "+" && symbol != "*")
  {
    cout << "err: invalid operation" << endl;
    push(one);
    return false;
  }
  Operand* snum = peek();
  two = snum->number;
  pop();
  if (symbol == "+")
  {
    add = one+two;
    push(add);
    return true;
  }
  else if (symbol == "*")
  {
    mult = one*two;
    push(mult);
    return true;
  }
  return true;
}
