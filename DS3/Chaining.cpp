#include "Chaining.h"


HashC::HashC(int t)
{
    a=t;
    tableSize=5000;
    collisions=0;
    hashTable=new LinkedList<string>[tableSize]();
}

void HashC::insert(string input)
{
    int TableIndex = hash(input);
    if (hashTable[TableIndex].length()!=0)
    {
        collisions++;
    }

    hashTable[TableIndex].insertAtHead(input);
}

ListItem<string>* HashC::lookup(string input)
{
    int TableIndex = hash(input);

 return hashTable[TableIndex].searchFor(input);
}
int HashC::hash(string input)
{
    int res=0;
    int j=input.size()-1;
    for (int i=0;i<input.size();i++)
    {
        res=res+input[i]*pow(a,j);
        j--;

    }
    res=res%tableSize;
    if (res<0)
        res=-res;
    return res;
}

int HashC::Collisions()
{
    return collisions;
}

void HashC::Load(char* file)
{
    ifstream input;
    input.open(file);
    string temp;
    while (!input.eof())
    {
        getline(input,temp);
        insert(temp);
    }
}
