#include "openAddress.h"
#include <stdio.h>

OpenAddress::OpenAddress(int A)
{
    a=A;
    tableSize=7331;
    collisions=0;
    entries=0;
    hashTable=new string[tableSize]();
}

void OpenAddress::Load(char* file)
{
    ifstream input;
    input.open(file);
    string temp;
    int i=0;
    while (!input.eof())
    {
        getline(input,temp);
        insertItem(temp);

    }
}

int OpenAddress::hash(string input)
{
    int res=0;
    int j=input.size()-1;
    int temp=0;
    for (int i=0;i<input.size();i++)
    {
        temp=input[i];
        res=res+temp*pow(a,j);
        j--;

    }
    res=res%tableSize;

    if (res<0)
        res=-res;

    return res;
}

long OpenAddress::getSize()
{
    return tableSize;
}

int OpenAddress::Collisions()
{
    return collisions;
}

void OpenAddress::insertItem(string Word)
{
    int TableIndex=hash(Word);
    entries++;
    if (entries>0.6*tableSize)
    {
        resize();
    }
    if (hashTable[TableIndex]!="")
        collisions++;
    while (hashTable[TableIndex]!="")
    {
        if (TableIndex==tableSize-1)
            TableIndex=0;
        else
            TableIndex++;
    }

    hashTable[TableIndex]=Word;

}


string OpenAddress::lookUp(string Word)
{
    int TableIndex=hash(Word);
    int stop=0;
    while (true)
    {
        if (hashTable[TableIndex]==Word)
            return hashTable[TableIndex];
        if (stop>=tableSize)
            return "Not Found";
        if (TableIndex==tableSize-1)
            TableIndex=0;
        else
            TableIndex++;

        stop++;
    }

}

void OpenAddress::resize()
{

    OpenAddress temp(a);
    temp.tableSize=tableSize*2;
    temp.hashTable=new string[temp.tableSize];
    int r=0;
    for (int i=0;i<tableSize;i++)
    {
        temp.insertItem(hashTable[i]);
    }

    tableSize=tableSize*2;
    delete [] hashTable;
    hashTable = temp.hashTable;

}
