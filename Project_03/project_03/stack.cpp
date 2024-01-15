#include <iostream>
#include <new>
#include "stack.h"

using namespace std;

// Attempts to increase size of stack array to 2*num and then push n onto stack
// If unable to resize, throw StackFull exception
void Stack::Resize(int n)
{
	try
	{
		// store num in old_num and update num value to 2*num
		int old_num = num;
		num = 2 * num;
		
		// create a resize array to store array values
		int* resize = new int[num];
		
		// copy array values into resize array
		for (int i = 0; i < old_num; i++)
		{
			resize[i] = array[i];
		}

		// delete old array
		delete[] array;

		// set array equal to the resized array
		array = resize;

		array[++top] = n;
		
	}
	catch (...)
	{
		try
		{
			throw StackFull();
		}
		catch (StackFull())
		{
			cout << "Full Stack" << endl;
		}
	}
	
}

// Parameterized constructor dynamically allocates an empty stack array  
// that may hold no more than n elements and initializes other private variables
Stack::Stack(int n)
{
	top = -1;
	num = n + 1;
	array = new int[num];
}

// Destructor deallocates all dynamically-allocated memory
// associated with the object
Stack::~Stack()
{
	delete[] array;
}

// Pushes integer n onto top of stack.  If stack is full, attempts to
// resize stack and then push n.  If unable to resize, throws StackFull exception.
void Stack::Push(int n)
{
	if (IsFull())
	{
		// FLAG
		Resize(2 * num);
	}

	
		top++;
		array[top] = n;
	
}						

// Removes top integer from stack
// If stack is empty, throws StackEmpty exception
void Stack::Pop()
{
	if (IsEmpty())
	{
	
		
	   throw StackEmpty();
		}
	
	{
		top--;
	}
}


// Returns true if stack is empty; false otherwise
bool Stack::IsEmpty() const
{
	return (top == -1);
}

// Returns true if stack is full; false otherwise
bool Stack::IsFull() const
{
	return (top == (num - 1));
}

// Removes all items from stack leaving an empty, but usable stack with capacity num
// If stack is already empty, MakeEmpty() does nothing
void Stack::MakeEmpty()
{
	top = -1;
}

// Returns value of top integer on stack WITHOUT modifying the stack
// If stack is empty, throws StackEmpty exception
int Stack::Top() const 
{
	if (IsEmpty())
	{
		try
		{
			throw StackEmpty();
		}
		catch (StackEmpty())
		{
			// cout error statement
		}
	}
	else
	{
		return array[top];
	}
}

// Returns number of items on stack WITHOUT modifying the stack
int Stack::Size() const
{
	return (top + 1);
}

// Returns value of largest integer on stack WITHOUT modifying the stack
// If stack is empty, throws StackEmpty
int Stack::Max() const
{
	if (IsEmpty())
	{
		try
		{
			throw StackEmpty();
		}
		catch (StackEmpty())
		{
			// cout error statement
		}
	}
	else
	{
		int max = array[top];
		
		for (int i = top - 1; i > -1; i--)
		{
			if (max < array[i])
			{
				max = array[i];
			}
		}

		return max;
	}
}

// Returns value of smallest integer on stack WITHOUT modifying the stack
// If stack is empty, throws StackEmpty

int Stack::Min() const
{
	if (IsEmpty())
	{
		try
		{
			throw StackEmpty();
		}
		catch (StackEmpty())
		{
			// cout error statement
		}
	}
	else
	{
		int min = array[top];

		for (int i = top - 1; i > -1; i--)
		{
			if (min > array[i])
			{
				min = array[i];
			}
		}

		return min;
	}
}

// Returns stack value n levels down from top of stack. Peek(0) = Top()
// If position n does not exist, throws StackInvalidPeek
int Stack::Peek(unsigned int n) const
{
	if ((0 <= n) && (n <= top))
	{
		return array[top - n];
	}
	else
	{
		try
		{
			throw StackInvalidPeek();
		}
		catch (StackInvalidPeek())
		{
			// cout error statement
		}
	}
}

// Returns total num of elements that maybe stored in stack array
int Stack::Capacity() const
{
	return num;
}