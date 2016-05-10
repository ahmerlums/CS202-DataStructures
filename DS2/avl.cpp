#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
#include "time.h"
#include "bst.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
    root = NULL;
}

template <class T>
AvL<T>::~AvL()
{

}

template <class T>
AvLNode<T>* AvL<T>::search(T k)
{
    return search(root,k);

}

template <class T>
AvLNode<T>* AvL<T>::search(AvLNode<T>* t, T item) {

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
void AvL<T>::replace(T ok, T nk)
{

}
template <class T>
void AvL<T>::recompheight(AvLNode<T>* t)
{
          while ( t != NULL )
      {
         t->height = nodeHeight(t);
         t = t->parent;
      }

}

template <class T>
void AvL<T>::delete_node(T k)
{
    AvLNode<T>* node=NULL;

    AvLNode<T>* t=search(k);
    if (t!=NULL)
    {
    if (t->right==NULL && t->left==NULL)
    {
    if (t==root)
    {
     root=NULL;
    }
    else if (t->parent->right==t)
    {
     t->parent->right=NULL;
     Balance(node);
    }
    else if (t->parent->left==t)
    {
        t->parent->left=NULL;
        Balance(node);
    }


        AvLNode<T>* parent=t->parent;
       delete t;


    if (parent!=NULL)
        Balance(parent);
        return;

    }

    else if (t->right==NULL)
    {
        AvLNode<T>* parent;
        if (t==root)
        {
            t->left->parent=NULL;
            root=t->left;
        }
        else if(t->parent->left==t)
        {
            t->parent->left=t->left;

        parent =t->parent->left;
            t->left->parent=t->parent;
        }
        else if (t->parent->right==t)
        {
            t->parent->right=t->left;
             parent=t->parent->right;
            t->left->parent=t->parent;
        }


        delete t;

    if (parent!=NULL)
        Balance(parent);
        return;
    }

    else if (t->left==NULL)
    {
        AvLNode<T>* parent;
        if (t==root)
        {
            t->right->parent=NULL;
            root=t->right;
        }
        else if(t->parent->left==t)
        {
            t->parent->left=t->right;

        parent =t->parent->left;
            t->right->parent=NULL;
        }
        else if (t->parent->right==t)
        {
            t->parent->right=t->right;

        parent =t->parent->right;
             t->right->parent=NULL;
        }

      //  AvLNode<T>* parent=t->parent;
        delete t;

    if (parent!=NULL)

        Balance(parent);
    return;

    }

    else if (t->left!=NULL&&t->right!=NULL)
    {

        if (t->left->right==NULL)
        {

            t->key=t->left->key;
            t->value=t->left->value;
            AvLNode<T>* l=t->left;
            if (t->left->left!=NULL)
            {
            t->left->left->parent=t;
            t->left=t->left->left;

            }

            else
            {

                t->left=NULL;
            }
             AvLNode<T>* parent=l->parent;
              delete l;
              if (parent!=NULL)
             Balance(parent);
             return;



        }

        else
        {

            AvLNode<T>* l = delete_node(t->left->right,k);

            t->key=l->key;
            t->value=l->value;

            l->parent->right=l->left;
            if (l->left!=NULL)
            l->left->parent=l->parent;
             AvLNode<T>* parent=l->parent;
 delete l;
    if (parent!=NULL)

        Balance(parent);

            return;
        }


    }


}
}


template <class T>
void AvL<T>::Balance(AvLNode<T>* temp)
{
    AvLNode<T>* x=temp;
    AvLNode<T>* y=temp;
    AvLNode<T>* z=temp;
    cout << "yes";
    int i=0;
    while (x!=NULL)
    {
        i++;
        if (abs(nodeHeight(x->right)-nodeHeight(x->left))<2)
        {
            z=y;
            y=x;
            x=x->parent;
        }
        else
            break;

    }

    if(x!=NULL)
    {

        if (x->left==y&&y->left==z)
        {
            AvLNode<T>* t2=y->right;
            y->right=x;
            x->left=t2;
            y->parent=x->parent;
            if (x==root)
            {
                root=y;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=y;
                else
                    x->parent->left=y;
            }
            x->parent=y;
            z->parent=y;
            if (t2!=NULL)
            t2->parent = x;

        }

        if (x->left==y&&y->right==z)
        {
            AvLNode<T>* t2=z->right;
            AvLNode<T>* t1=z->left;
            z->left=y;
            z->right=x;
            x->left=t2;
            if (x==root)
            {
                root=z;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=z;
                else
                    x->parent->left=z;
            }
            z->parent=x->parent;
            x->parent=z;
            y->parent=z;
            y->right=t1;
            if(t1!=NULL)
                t1->parent=y;
            if (t2!=NULL)
                t2->parent =x;



        }


        if (x->right==y&&y->right==z)
        {
            AvLNode<T>* t2=y->left;
            y->left=x;
            y->right=z;
            x->right=t2;
            if (x==root)
            {
                root=y;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=y;
                else
                    x->parent->left=y;
            }
            y->parent=x->parent;
            x->parent=y;
            z->parent=y;
            if(t2!=NULL)
                t2->parent=x;


        }

        if (x->right==y&&y->left==z)
        {
            AvLNode<T>* t2=z->right;
            AvLNode<T>* t1=z->left;
            z->left=x;
            z->right=y;
            x->right=t1;
            if (x==root)
            {
                root=z;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=z;
                else
                    x->parent->left=z;
            }
            z->parent=x->parent;
            x->parent=z;
            y->parent=z;
            y->left=t2;
            if (t1!=NULL)
                t1->parent=x;
            if(t2!=NULL)
                t2->parent=y;


    }}



    }

template <class T>
AvLNode<T>* AvL<T>::delete_node(AvLNode<T>* t,T key1)
{
    if(t->right==NULL)
    {
         return t;
    }

        return delete_node(t->right,key1);



}

template <class T>
void AvL<T>::insert(string val, T k)
{
    AvLNode<T>* node=bst_insert(root,val,k);
    AvLNode<T>* temp=Find_imBalance(node);

    if(temp!=NULL)
    {
        AvLNode<T>* z= temp;
        AvLNode<T>* y=temp->parent;
        AvLNode<T>* x=y->parent;


        if (x->left==y&&y->left==z)
        {
            AvLNode<T>* t2=y->right;
            y->right=x;
            x->left=t2;
            y->parent=x->parent;
            if (x==root)
            {
                root=y;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=y;
                else
                    x->parent->left=y;
            }
            x->parent=y;
            z->parent=y;
            if (t2!=NULL)
            t2->parent = x;

        }

        if (x->left==y&&y->right==z)
        {
            AvLNode<T>* t2=z->right;
            AvLNode<T>* t1=z->left;
            z->left=y;
            z->right=x;
            x->left=t2;
            if (x==root)
            {
                root=z;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=z;
                else
                    x->parent->left=z;
            }
            z->parent=x->parent;
            x->parent=z;
            y->parent=z;
            y->right=t1;
            if(t1!=NULL)
                t1->parent=y;
            if (t2!=NULL)
                t2->parent =x;



        }


        if (x->right==y&&y->right==z)
        {
            AvLNode<T>* t2=y->left;
            y->left=x;
            y->right=z;
            x->right=t2;
            if (x==root)
            {
                root=y;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=y;
                else
                    x->parent->left=y;
            }
            y->parent=x->parent;
            x->parent=y;
            z->parent=y;
            if(t2!=NULL)
                t2->parent=x;


        }

        if (x->right==y&&y->left==z)
        {
            AvLNode<T>* t2=z->right;
            AvLNode<T>* t1=z->left;
            z->left=x;
            z->right=y;
            x->right=t1;
            if (x==root)
            {
                root=z;
            }
            else
            {
                if (x->parent->right==x)
                    x->parent->right=z;
                else
                    x->parent->left=z;
            }
            z->parent=x->parent;
            x->parent=z;
            y->parent=z;
            y->left=t2;
            if (t1!=NULL)
                t1->parent=x;
            if(t2!=NULL)
                t2->parent=y;


    }


    }
}


template <class T>
AvLNode<T>* AvL<T>::Find_imBalance(AvLNode<T>* node)
{
    if(node==NULL)
        return NULL;

    else
    {

       if (node->parent!=NULL&&node->parent->parent!=NULL)
        if ((nodeHeight(node->parent->parent->left)-nodeHeight(node->parent->parent->right)>1) || (nodeHeight(node->parent->parent->right)-nodeHeight(node->parent->parent->left)>1))
        {
            return node;
        }

        return Find_imBalance(node->parent);
}
}
template <class T>
AvLNode<T>* AvL<T>::bst_insert(AvLNode<T>* t,string val,T key) {
    if (root==NULL)
    {
        root=new AvLNode<T>(val,key);
        root->height=nodeHeight(root);
        return root;
    }

  else if(key < t->key)
  {
    if(t->left!=NULL)
     return bst_insert(t->left, val,key);
    else
    {
      t->left=new AvLNode<T>(val,key);
      t->left->height=nodeHeight(t->left);
      t->left->parent=t;
      return t->left;//Sets the right child of the child node to null
    }
  }
  else
  {
    if(t->right!=NULL)
      return bst_insert(t->right,val,key);

    else
    {
     t->height++;
      t->right=new AvLNode<T>(val,key);
      t->right->height=nodeHeight(t->right);
      t->right->parent=t;
      return t->right;//Sets the right child of the child node to null
    }
  }
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *node)
{
    if (node==NULL)
        return -1;

    return (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);
}

template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
	return root;
}

#endif
