#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
int i=0;
using namespace std;
template <class T>
bst<T>::bst()
{
    root=NULL;
}

template <class T>
void bst<T>::insert(string val,T key1)
{
    insert(root,val,key1);
}

template <class T>
void bst<T>::insert(bst_node<T>* t,string val,T key) {
    if (root==NULL)
    {
        root=new bst_node<T>(val,key);
        root->height=0;
        return;
    }

  else if(key < t->key)
  {
    if(t->left!=NULL)
     insert(t->left, val,key);
    else
    {
      t->left=new bst_node<T>(val,key);
      t->left->height=height(t->left);
      t->left->parent=t;
      return;//Sets the right child of the child node to null
    }
  }
  else
  {
    if(t->right!=NULL)
      insert(t->right,val,key);

    else
    {
      t->right=new bst_node<T>(val,key);
      t->right->height=height(t->right);
      t->right->parent=t;
      return;//Sets the right child of the child node to null
    }
  }
}


template <class T>
bst_node<T>* bst<T>::search(T key1)
{
    bst_node<T>* t=root;
    i=0;
    return search(t,key1);

}

template <class T>
bst_node<T>* bst<T>::search(bst_node<T>* t, T item) {

    if (root == NULL||t==NULL) {
        return NULL;
    }

    else if (t->key == item) {
        return t;
    }
    else if (t->key > item) {
        return search(t->left, item);
    } else {
        return search(t->right, item);
    }
}

template <class T>
void bst<T>::delete_node(T key1)
{
    bst_node<T>* t=search(key1);
    if (t->right==NULL && t->left==NULL)
    {
    if (t==root)
    {
     root=NULL;
    }
    else if (t->parent->right==t)
    {
     t->parent->right=NULL;
    }
    else if (t->parent->left==t)
    {
        t->parent->left=NULL;
    }
    delete t;
    }

    else if (t->right==NULL)
    {
        if (t==root)
        {
            root=t->left;
            root->parent=NULL;
        }
        else if(t->parent->left==t)
        {
            t->parent->left=t->left;
            t->left->parent=t->parent;
        }
        else if (t->parent->right==t)
        {
            t->parent->right=t->left;
            t->left->parent=t->parent;
        }
        delete t;
    }

    else if (t->left==NULL)
    {
        if (t==root)
        {
            root=t->right;
            root->parent=NULL;
        }
        else if(t->parent->left==t)
        {
            t->parent->left=t->right;
            t->right->parent=t->parent;
        }
        else if (t->parent->right==t)
        {
            t->parent->right=t->right;
            t->right->parent=t->parent;
        }
        delete t;
    }

    else if (t->left!=NULL&&t->right!=NULL)
    {

        if (t->left->right==NULL)
        {

            t->key=t->left->key;
            t->value=t->left->value;
            bst_node<T>* l=t->left;
            if (t->left->left!=NULL)
            {
            t->left->left->parent=t;
            t->left=t->left->left;

            }

            else
            {

                t->left=NULL;
            }
            delete l;

        }

        else
        {
            bst_node<T>* l = delete_node(t->left->right,key1);
            t->key=l->key;
            t->value=l->value;

            l->parent->right=l->left;
            if (l->left!=NULL)
            l->left->parent=l->parent;


        delete l;
        }
    }

}

template <class T>
bst_node<T>* bst<T>::delete_node(bst_node<T>* t,T key1)
{
    if(t->right==NULL)
    {
         return t;
    }
    else
    {
        delete_node(t->right,key1);
    }


}

template <class T>
int bst<T>::height( bst_node<T> *t)
{
    if (t==NULL)
        return -1;

    return (max(height(t->left), height(t->right)) + 1);
}

template<class T>
void bst<T>::replace(T old_key,T new_key)
{
    bst_node<T>* t=search(old_key);
    string temp=t->value;

insert(temp,new_key);
    delete_node(old_key);

}


template <class T>
bst_node<T>* bst<T>::getroot()
{

    return root;
}
#endif


