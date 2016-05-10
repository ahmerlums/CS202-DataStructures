#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
 head = NULL;
}

template<class T>
LinkedList<T>::LinkedList( const LinkedList<T>& otherLinkedList)
{

}

template <class T>
LinkedList<T>::~LinkedList() {



}


template <class T>
void LinkedList<T>::insertAtHead(T item)
{
ListItem<T> *p = new ListItem<T>(item);
 if(head==NULL)
{
 head=p;
}
else
{
// ListItem<T>*p=new ListItem<T>(item);
  p->next=head;
head->prev=p;
head=p;
}

}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
  ListItem<T>* temp = new ListItem<T>(item);



  if (head == NULL){
	head = temp;
  }

  else{
    ListItem<T>* tail = getTail();
    tail->next = temp;
    temp->prev = tail;

}
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat) {
ListItem<T> *p;
p = searchFor(afterWhat);
if (p!=NULL)
{
ListItem<T> *q;
q = new ListItem<T>(toInsert);
q->prev=p;
if(p->next!=NULL)
{
q->next=p->next;
p->next->prev=q;
}
p->next=q;

}
}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
ListItem<T>*t=getTail();
ListItem<T>*h=head;
 if ((h==NULL) ||(item>t->value)){
   insertAtTail(item);
 }
 else{
  while(h!=NULL)
  {
   if(h->value>=item)
   {
    if(h->prev==NULL){
     insertAtHead(item);
    }
    else{
     h=h->prev;
     ListItem<T>*hn=h->next;
     h->next=new ListItem<T>(item);
     h->next->prev=h;
     h->next->next=hn;
     hn->prev=h->next;
     }
    break;
   }
   h=h->next;
  }
 }
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
 ListItem<T> *p = head;

 if(head==NULL){
 return NULL;
 }
 else{
 while (p->next != NULL){
  p=p->next;
 }
 return p;
 }
}



template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item) {
ListItem<T> *p = head;
while (p != NULL && p->value != item){
 p = p->next;
}
return p;
}


template <class T>
void LinkedList<T>::deleteElement(T item)
{
 ListItem<T> *del = searchFor(item);
 ListItem<T> *t= getTail();
 if (del->value==head->value)
 {
  deleteHead();
 }
 else if(del->value==t->value)
 {
  deleteTail();
 }

 else{
 ListItem<T> *temp;
 temp=del->prev;
 temp->next=del->next;
 del->next->prev=temp;
 del->prev=t->next;
 del->next=temp;
 del=NULL;
 delete del;
 }
}

template <class T>
void LinkedList<T>::deleteHead()
{
if (head == NULL) {
	head = 	NULL;
	return;}
else if (head->next == NULL) {
	head = 	NULL;
	return;
	}


ListItem<T>* newhead = head->next;
ListItem<T>* oldhead = head;

head->prev= NULL;
//cout << "im here" << endl;
 delete oldhead;
head = newhead;
}

template <class T>
void LinkedList<T>::deleteTail()
{
 ListItem<T> *oldtail = getTail();
ListItem<T> *temp = oldtail->prev;

 delete oldtail;
 temp -> next = NULL;



}

template <class T>
int LinkedList<T>::length()
{
ListItem<T> *p = head;
int i=0;
 while (p != NULL){
  p=p->next;
  i++;
 }
return i;

}


template <class T>
void LinkedList<T>::reverse() {

	ListItem<T>* backup;
	ListItem<T>* headBackup;

	for (ListItem<T>* iter=head; iter!=NULL; iter=iter->prev) {
		backup = iter->prev;
		iter->prev = iter->next;
		iter->next = backup;
		headBackup = iter;
	}
	head = headBackup;
}

template <class T>
void LinkedList<T>::parityArrangement() {
   ListItem<T>* hnn=head->next->next;
   ListItem<T>* hn=head->next;
   ListItem<T>* tmp;

   while(hnn != NULL ){
         tmp = hnn;
         hn->next = tmp->next;
         tmp->next = hn;
         hnn = hn->prev;
         hnn->next = hn;
         hnn=hnn->next->next;
    }
}

#endif
