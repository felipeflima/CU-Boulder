RPNCalculator::RPNCalculator()
{
  while (stackHead != NULL)
  {
    stackHead = stackHead->next;
  }
}

RPNCalculator::~RPNCalculator()
{
  Operand* crawler;

	while(stackHead!=nullptr){
		crawler = stackHead->next;
		delete stackHead;
		stackHead = crawler;
	}
}
