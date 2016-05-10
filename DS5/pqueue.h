#ifndef PQUEUE__H
#define PQUEUE__H
#include <iostream>
using namespace std;

template<class T>
class pqueue
{
	protected:
		int size;
	public:
		int numE;
		T* heap;
		pqueue();
		void insert(T);
		T ExtractMin();
		void Print();
};


#endif
