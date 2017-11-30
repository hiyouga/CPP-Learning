// stack.h -- class definition for the stack ADT

#ifndef STACK_H_
#define STACK_H_

typedef char Elemtype;

class Stack
{
private:
	enum {MAX = 99}; // constant specific to class
	Elemtype _stack[MAX]; // holds stack items
	int _top; // index for top stack item
public:
	Stack();
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Elemtype & item);
	bool pop(Elemtype & item);
	bool get(Elemtype & item);
};

#endif

Stack::Stack()
{
	_top = 0;
}

Stack::~Stack()
{
	;
}

bool Stack::isempty() const
{
	return _top == 0;
}

bool Stack::isfull() const
{
	return _top == MAX;
}

bool Stack::push(const Elemtype & item)
{
	if (_top < MAX) {
		_stack[_top++] = item;
		return true;
	} else {
		return false;
	}
}

bool Stack::pop(Elemtype & item)
{
	if(_top > 0) {
		item = _stack[--_top];
		return true;
	} else {
		return false;
	}
}

bool Stack::get(Elemtype & item)
{
	if(_top > 0) {
		item = _stack[_top-1];
		return true;
	} else {
		return false;
	}
}
