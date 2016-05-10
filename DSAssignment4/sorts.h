#ifndef __SORTS_H
#define __SORTS_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "list.cpp"
using namespace std;

vector<long> InsertionSort(vector<long> nums);
vector<long> MergeSort(vector<long> nums);
void MergeSort(List<long>* &nums);
vector<long> QuickSortArray(vector<long> nums);
vector<long> QuickSortList(vector<long> nums);
void QuickSortList(List<long>* ,ListItem<long>*,ListItem<long>*);
vector<long> HeapSort(vector<long> nums);
vector<long> BucketSort(vector<long> nums, long max);
void MyQuickSort(long*,long,long,int);
void QuickSortList(ListItem<long>*, ListItem<long>*);
#endif

