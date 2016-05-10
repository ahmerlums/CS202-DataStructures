#include <iostream>
#include "bst.cpp"
#include "avl.cpp"
#include <fstream>
#include <vector>
using namespace std;



int main()
{
    cout <<"Please Choose Data Structure"<<endl<<"1)BST"<<endl<<"2)AVL"<<endl;
    int n;
    cin >> n;
    if (n==1)
    {
        cout <<"Please enter a filename:"<<endl;
        string temp ;
        cin >> temp;
        ifstream file;
        bst<int>* tree=new bst<int>();
        file.open(temp.c_str());
         vector<string> store_file;
    temp="";
    while(!file.eof())
    {
        getline(file,temp);
        store_file.push_back(temp);
    }
    bool timer = 1;
    vector<string> Values;
    vector<int> Keys;
    for (int i=0;i<store_file.size();i++)
    {
        temp="";
        for (int r=0;r<store_file[i].size();r++)
        {
            if(store_file[i][r]=='~')
            {
                Values.push_back(temp);
                temp="";
                r+=1;
            }

            temp+=store_file[i][r];
            if(r==store_file[i].size()-1)
               Keys.push_back(atoi(temp.c_str()));
        }
    }
            startTimer();
    for(int i=0 ; i<Keys.size();i++)
    {
        tree->insert(Values[i],Keys[i]);
    }
    cout<<"File loaded successfully. "<<Keys.size()<<" key/value pairs loaded from the file ";
    stopTimer();
    while (true)
    {
    cout <<"Press 1 to Insert another key/value Pair"<<endl;
    cout <<"Press 2 to search for a value using its key"<<endl;
    cout <<"Press 3 to delete a key/value pair" << endl;
    cout <<"Press 4 to update the key of an existing value"<<endl;
    cout <<"Press 5 to see the current height of the Tree" << endl;
    cin >>n;
    if (n==1)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        cout << "Enter value ";
        cin >> temp;
        tree->insert(temp,b);
    }
    if (n==2)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        startTimer();
        bst_node<int>* a=tree->search(b);
        stopTimer();
        if (a==NULL)
            cout <<"No node found" <<endl;
        else
        cout << "Value corresponding to your key is:"<<a->value<<endl;

    }
    if (n==3)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        tree->delete_node(b);
    }
    if (n==4)
    {
        cout <<"Enter old key: ";
        int b;
        cin >>b;
        cout <<"Enter new key: ";
        int c;
        cin >>c;
        tree->replace(b,c);
    }
    if (n==5)
    {
        cout<<"Height of the tree is "<< tree->height(tree->getroot())<<endl;
    }
    }

    }

    if (n==2)
    {
        cout <<"Please enter a filename:"<<endl;
        string temp ;
        cin >> temp;
        ifstream file;
        AvL<int>* tree=new AvL<int>();
        file.open(temp.c_str());
         vector<string> store_file;
temp="";
    while(!file.eof())
    {
        getline(file,temp);
        store_file.push_back(temp);
    }
    bool timer = 1;
    vector<string> Values;
    vector<int> Keys;
    for (int i=0;i<store_file.size();i++)
    {
        temp="";
        for (int r=0;r<store_file[i].size();r++)
        {
            if(store_file[i][r]=='~')
            {
                Values.push_back(temp);
                temp="";
                r+=1;
            }

            temp+=store_file[i][r];
            if(r==store_file[i].size()-1)
               Keys.push_back(atoi(temp.c_str()));
        }
    }
            startTimer();
    for(int i=0 ; i<Keys.size();i++)
    {
        tree->insert(Values[i],Keys[i]);
    }
    cout<<"File loaded successfully. "<<Keys.size()<<" key/value pairs loaded from the file ";
    stopTimer();
    while (true)
    {
    cout <<"Press 1 to Insert another key/value Pair"<<endl;
    cout <<"Press 2 to search for a value using its key"<<endl;
    cout <<"Press 3 to delete a key/value pair" << endl;
    cout <<"Press 4 to update the key of an existing value"<<endl;
    cout <<"Press 5 to see the current height of the Tree" << endl;
    cin >>n;
    if (n==1)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        cout << "Enter value ";
        cin >> temp;
        tree->insert(temp,b);
    }
    if (n==2)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        startTimer();
        AvLNode<int>* a=tree->search(b);
        stopTimer();
        if (a==NULL)
            cout <<"No node found" <<endl;
        else
        cout << "Value corresponding to your key is:"<<a->value<<endl;

    }
    if (n==3)
    {
        cout <<"Enter Key: ";
        int b;
        cin >>b;
        tree->delete_node(b);
    }
    if (n==4)
    {
        cout <<"Enter old key: ";
        int b;
        cin >>b;
        cout <<"Enter new key: ";
        int c;
        cin >>c;
        tree->replace(b,c);
    }
    if (n==5)
    {
        cout<<"Height of the tree is "<< tree->nodeHeight(tree->getRoot())<<endl;
    }
    }


    }
}
