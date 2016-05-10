#include "doubleHash.h"

DoubleHash::DoubleHash(int A)
{
    a=A;
    tableSize=7331;
    collisions=0;
    entries=0;
    hashTable=new string[tableSize]();
}

void DoubleHash::Load(char* file)
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

int DoubleHash::hash2(string input)
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

int DoubleHash::hash1(string input)
{
int Hash1=0;

for (int i=0;i<input.size();i++)
{
    Hash1=Hash1^((Hash1<<5)+(Hash1>>2)+(int)input[i]);
}

return abs(Hash1%tableSize);

}

long DoubleHash::getSize()
{
    return tableSize;
}

int DoubleHash::Collisions()
{
    return collisions;
}

void DoubleHash::insertItem(string Word)
{
    int TableIndex=hash1(Word);

    entries++;
    if (entries>0.6*tableSize)
    {
        resize();
    }
    if (hashTable[TableIndex]!="")
        collisions++;

    if (hashTable[TableIndex].size()==0)
        hashTable[TableIndex]=Word;
    else
    {
        TableIndex=hash2(Word);

        while (hashTable[TableIndex].size()!=0)
        {
            if (TableIndex==tableSize-1)
                TableIndex=0;
            else
                TableIndex++;
        }
            hashTable[TableIndex]=Word;


    }

}

string DoubleHash::lookUp(string Word)
{
    int TableIndex=hash1(Word);

    if (hashTable[TableIndex]==Word)
        return Word;
    else
    {
            TableIndex=hash2(Word);
            int stop=0;
            while (hashTable[TableIndex]!=Word)
            {
                if (TableIndex==tableSize-1)
                    TableIndex=0;
                if (stop==tableSize)
                    return "Not found";
                else
                    TableIndex++;
                stop++;
            }
            return hashTable[TableIndex];
    }

}


void DoubleHash::resize()
{
    DoubleHash temp(a);
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


