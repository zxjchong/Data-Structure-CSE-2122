#include <iostream>
#include <string>
#include "pqueue.h"
#include "pqueue.cpp"

using namespace std;
using namespace pqueuenamespace;  

template<class T>
void testPQueue(PQueue<T> &pq)
{
	int n;
	cout << "Enter how many items you want to add to the queue: ";
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		T input;
		int priority;
		cout << "Enter item and its priority: ";
		cin >> input >> priority;
		pq.add(input, priority);
	}

	cout << "Items in queue in order of priority:" << endl;
	while(!pq.empty())
	{
		cout << pq.remove() << endl;
	}
}

int main()
{
	PQueue<char> pqc;
	cout << "Character queue:" << endl;
	testPQueue(pqc);

	PQueue<string> pqs;
	cout << "String queue:" << endl;
	testPQueue(pqs);

	return 0;
}
