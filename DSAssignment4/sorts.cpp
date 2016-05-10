#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "list.cpp"
#include "math.h"
#include <stdlib.h>
#include <time.h>
//=====================================================================================
vector<long> InsertionSort(vector<long> nums)
{
    long arr[nums.size()];
    for (long i=0; i<nums.size(); i++)
        arr[i]=nums[i];

    long length = nums.size();
    for (long i = 0; i < length; i++)
    {
        long j = i;

        while (j > 0 && arr[j] < arr[j-1])
        {
            long temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    for (long i=0; i<nums.size(); i++)
        nums[i]=arr[i];

    return nums;

}

//=====================================================================================
vector<long> MergeSort(vector<long> nums)
{
    List<long>* S=new List<long>();
    for (long i=0; i<nums.size(); i++)
        S->insertAtHead(nums[i]);

    MergeSort(S);
    long r = S->length();

    for (long i=0; i<r; i++)
    {
        nums[i]=S->getHead()->value;
        S->deleteHead();
    }
    return nums;

}

void MergeSort(List<long>* &nums)
{
    long n=nums->length();
    if (n<=1)
        return;

    List<long>* S1=new List<long>() ;
    List<long>* S2=new List<long>() ;

    for (long i=0; i<n; i++)
    {
        if (i<n/2)
        {
            S1->insertAtHead(nums->getHead()->value);
            nums->deleteHead();
        }
        else
        {
            S2->insertAtHead(nums->getHead()->value);
            nums->deleteHead();
        }
    }
    MergeSort(S1);
    MergeSort(S2);

    while (S1->length()>0 && S2->length()>0)
    {
        if (S1->getHead()->value <= S2->getHead()->value)
        {
            nums->insertAtTail(S1->getHead()->value);
            S1->deleteHead();

        }
        else
        {
            nums->insertAtTail(S2->getHead()->value);
            S2->deleteHead();
        }
    }
    while (S1->length()>0)
    {
        nums->insertAtTail(S1->getHead()->value);
        S1->deleteHead();
    }

    while (S2->length()>0)
    {
        nums->insertAtTail(S2->getHead()->value);
        S2->deleteHead();
    }

}

//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
    long *Arr = new long[nums.size()];
    for (long i=0; i<nums.size(); i++)
        Arr[i]=nums[i];

    MyQuickSort(Arr,0,nums.size()-1,3);

    for (long i=0; i<nums.size(); i++)
        nums[i]=Arr[i];

    return nums;
}

void MyQuickSort(long* Arr, long left, long right,int option)
{
    long i = left;
    long j = right;


    int MedianofThree = (right+left)/2;
    long pivot = Arr[MedianofThree];


    while (true)
    {
        while (Arr[i] < pivot)
            i++;
        while (Arr[j] > pivot)
            j--;

        if (i>j)
            break;

            int temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
            i++;
            j--;

    }

    if (left < j)
        MyQuickSort(Arr, left, j,option);
    if (i < right)
        MyQuickSort(Arr, i, right,option);
}

vector<long> QuickSortList(vector<long> nums)
{
    List<long> *a=new List<long>();
    for (long i=0; i<nums.size(); i++)
        a->insertAtTail(nums[i]);

    QuickSortList(a->getHead(),a->getTail());

    for (long i=0; i<nums.size(); i++)
    {
        nums[i]=a->getHead()->value;
        a->deleteHead();
    }
    return nums ;

}

void QuickSortList(ListItem<long> *left, ListItem<long> *right)
{
    ListItem<long> *i;
    ListItem<long> *j;
    ListItem<long>* pivot;
    ListItem<long>*t;
    srand(time(NULL));
    int r=rand()%2;

    if (r==0)
        pivot=left;
    else
        pivot=right;


    j = right;
    i = left;
    t=i;
    bool a=1;
    while (a==1)
    {

        while (i->value<pivot->value)
            i=i->next;
        while (j->value> pivot->value)
            j=j->prev;
        t=i;
        a=0;
        while (t!=NULL)
        {
            if (t==j)
            {
                a=1;
                break;
            }
            t=t->next;
        }
        if(a==1)
        {
            int temp=i->value;
            i->value=j->value;
            j->value=temp;
            i=i->next;
            j=j->prev;
        }

    }
    a=0;
    t= left->next;
    while (t!=NULL)
    {
        if (t==j)
        {
            a=1;
            break;
        }
        t=t->next;
    }
    if (a==1)
        QuickSortList(left,j);
    a=0;
    t=i->next;
    while (t!=NULL)
    {
        if (t==right)
        {
            a=1;
            break;
        }
        t=t->next;
    }
    if (a==1)
        QuickSortList(i,right);

}
//=====================================================================================


//=====================================================================================
vector<long> HeapSort(vector<long> nums)
{
    long arr[nums.size()+1];
    long n=0;

    for (long i=0; i<nums.size(); i++)
    {
        arr[n+1]=nums[i];
        n++;
        long k=n;
        while (true)
        {
            if (k/2<=0)
                break;
            if (arr[k]<arr[k/2])
            {
                long temp=arr[k/2];
                arr[k/2]=arr[k];
                arr[k]=temp;
                k=k/2;
            }

            else
                break;
        }

    }
    long x=nums.size();

    for (long i=0; i<nums.size(); i++)
    {
        nums[i]=arr[1];
        arr[1]=arr[x];
        x--;
        long r=1;
        while(true)
        {
            if (2*r>x)
                break;

            if (2*r+1<=x)
            {
                if (arr[r]<arr[2*r]&&arr[r]<arr[2*r+1])
                    break;

                if (arr[2*r]<arr[2*r+1])
                {
                    long temp=arr[r];
                    arr[r]=arr[2*r];
                    arr[2*r]=temp;
                    r=2*r;
                }
                else
                {
                    long temp=arr[r];
                    arr[r]=arr[2*r+1];
                    arr[2*r+1]=temp;
                    r=2*r+1;

                }
            }
            else
            {
                if (arr[r]<arr[2*r])
                    break;
                else
                {
                    long temp=arr[r];
                    arr[r]=arr[2*r];
                    arr[2*r]=temp;
                    r=2*r;

                }
            }

        }


    }



    return nums;


}

//=====================================================================================
vector<long> BucketSort(vector<long> nums, long max)
{
    List<long>* Table=new List<long>[max]();
    for (long i=0; i<nums.size(); i++)
    {

        long toinsert=nums[i];

        if (nums.size()>max-1)
        {
            double l= nums.size();
            double p= max-2;
            double number = ceil(l/p);
            double n= toinsert;
            double t = floor (n/number);
            toinsert=t;
        }

        Table[toinsert].insertSorted(nums[i]);

    }
    long c=0;
    for (long i=0; i<max; i++)
    {
        while (true)
        {
            ListItem<long>* temp=Table[i].getHead();
            if (temp==NULL)
                break;
            nums[c]=temp->value;

            c++;
            Table[i].deleteHead();
        }
    }

    return nums;

}

#endif
