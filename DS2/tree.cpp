#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

Tree::Tree()
{
    head=NULL;
}

Tree::Tree(string file)
{
    head=NULL;
    ifstream input_file;
    input_file.open(file.c_str());
    vector<string> store_file;
    string temp;
    while(!input_file.eof())
    {
        getline(input_file,temp);
        insert(temp);
    }
}
Tree::~Tree()
{
    for (int i=0;i<Searches.size();i++)
    {
        Searches[i]->FChild=NULL;
        Searches[i]->Parent=NULL;
        Searches[i]->NextS=NULL;
        delete Searches[i];

    }
}

void Tree::insert(string item)
{
    TreeItem* t=head;
    int i=0;
    string temp="";
    while (i < item.size())
    {
        temp="";

    while (i<item.size())
    {
        if (item[i]=='/')
        {
            i++;
            break;
        }

        temp=temp+item[i];
        i++;
    }
    bool a=0;
    TreeItem* lo=NULL;
    for (int r=0;r<Searches.size();r++)
    {
        if (Searches[r]->value==temp)
        {
            lo=Searches[r];
            a=1;
            break;
        }
    }
    if (head==NULL)
    {

    head = new TreeItem(temp);
    Searches.push_back(head);
    t=head;
    }
    else if (a==0)
    {

        TreeItem* t1=new TreeItem(temp);

        Searches.push_back(t1);
    bool d=0;
    if (t->FChild==NULL)
    {
        d=1;
        t->FChild = t1;
    }

    t1->Parent=t;
    bool b=0;
    TreeItem* n=NULL;

    for (int r=0;r<Searches.size();r++)
    {
        if (Searches[r]->Parent!=NULL&&t1->Parent!=NULL&&Searches[r]->Parent->value==t1->Parent->value&&Searches[r]->NextS==NULL)
        {
            n=Searches[r];
            b=1;
            break;
        }
    }
    if (b==1)
        n->NextS=t1;


        t=t1;

    }
   else
   {
       t=lo;

   }
    }
}

vector<string> Tree::Locate(string qry)
{
    //startTimer();
    vector<string> res;
    bool a=0;
    for(int i=0;i<Searches.size();i++)
    {
        if (Searches[i]->value==qry)
        {
            a=1;
            TreeItem* temp = Searches[i];
            while (temp->Parent!=NULL)
            {
                temp=temp->Parent;
                res.push_back(temp->value);
            }
        }
        if (a==1)
        {
            return res;
        }
    }
  //  stopTimer();
    return res;

}

string Tree::LComAc(string a, string b)
{

    vector<string> a1=Locate(a);
    vector<string> b1=Locate(b);
    for (int i=0;i<a1.size();i++)
    {
        for (int r=0;r<b1.size();r++)
        {


            if(a1[i]==b1[r])
            {
                return a1[i];
            }
        }
    }

}

TreeItem* Tree::getHead()
{
    return head;
}

int Tree::countFiles()
{
    int res=0;
    for (int i=0;i<Searches.size();i++)
    {
        if (Searches[i]->FChild==NULL)
        {
            res++;
        }
    }
    return res;
}
/*
int main()
{
    Tree("input_test.txt");
}*/
#endif
