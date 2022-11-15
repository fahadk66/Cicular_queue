#include <iostream>

using namespace std;
#define n 100
class cQueue
{

	int rear;
	int front;
    int size;
	int *arr;
	
    public:
	cQueue(int s)
	{
	front =-1;
	rear = -1;
	size = s;
	arr = new int[s];
	}


void enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		cout<<"\nQueue is Full";
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}


int deQueue()
{
	if (front == -1)
	{
		cout<<"\nQueue is Empty";
		return 0;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}


void displayQueue()
{
	if (front == -1)
	{
		cout<<"\nQueue is Empty";
		return;
	}
	cout<<"\nElements in Circular Queue are: ";
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout<<arr[i]<<endl;
	}
	else
	{
		for (int i = front; i < size; i++)
			cout<< arr[i];

		for (int i = 0; i <= rear; i++)
			cout<<arr[i];
	}
}
};

/* Driver of the program */
int main()
{
	cQueue q(100);

	
	

	q.displayQueue();

	
	cout<<"\nDeleted value"<<q.deQueue();
	cout<<"\nDeleted value"<<q.deQueue();

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}
