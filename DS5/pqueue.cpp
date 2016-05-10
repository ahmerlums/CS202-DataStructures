#include "pqueue.h"

template<class T>
pqueue<T>::pqueue()
{
    size = 10000;
    numE = 0;
    heap = new T[size]();

}

template<class T>
void pqueue<T>::insert(T item)
{
        heap[numE+1]=item;
        if (numE+1==size)
        {
            size=size*2;
            T temp[size];
            for (int i=1;i<=numE;i++)
            {
                cout <<i<<endl;
                temp[i]=heap[i];
            }
            delete []heap;
        heap = new T[size];
            for (int i=1;i<=numE;i++)
                heap[i]=temp[i];
        }
        numE++;
        long k=numE;
        while (true)
        {
            if (k/2<=0)
                break;
            if (heap[k]<heap[k/2])
            {
                T temp=heap[k/2];
                heap[k/2]=heap[k];
                heap[k]=temp;
                k=k/2;
            }

            else
                break;
        }


}

template<class T>
T pqueue<T>::ExtractMin()
{
    long x=numE;
    T res;
    res=heap[1];
        heap[1]=heap[x];
        x--;
        long r=1;
        while(true)
        {
            if (2*r>x)
                break;

            if (2*r+1<=x)
            {
                if (heap[r]<heap[2*r]&&heap[r]<heap[2*r+1])
                    break;

                if (heap[2*r]<heap[2*r+1])
                {
                    T temp=heap[r];
                    heap[r]=heap[2*r];
                    heap[2*r]=temp;
                    r=2*r;
                }
                else
                {
                    T temp=heap[r];
                    heap[r]=heap[2*r+1];
                    heap[2*r+1]=temp;
                    r=2*r+1;

                }
            }
            else
            {
                if (heap[r]<heap[2*r])
                    break;
                else
                {
                    T temp=heap[r];
                    heap[r]=heap[2*r];
                    heap[2*r]=temp;
                    r=2*r;

                }
            }

        }
        numE--;
        return res;

}

template<class T>
void pqueue<T>::Print()
{
    for (int i=1;i<=numE;i++)
        cout << heap[i]<<",";
}




