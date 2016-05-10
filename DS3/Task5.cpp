#include "openAddress.cpp"
#include "Chaining.cpp"
#include "doubleHash.cpp"
#include <vector>
#include "time.h"
#include <sstream>
#include "string.h"
void Run_Chaining(vector<string> ,vector<string> );
void Run_OpenAddressing(vector<string> ,vector<string> );
void Run_DoubleHashing(vector<string> ,vector<string> );
int main()
{
    vector<string> dict;
    vector<string> queries;
    ifstream file;
    file.open("dict.txt");
    while (!file.eof())
    {
        string Buffer;
		getline(file,Buffer,'\n');
		dict.push_back(Buffer);
    }
    file.close();
    file.open("queries.txt");
    while (!file.eof())
    {
        string Buffer;
		getline(file,Buffer,'\n');
		queries.push_back(Buffer);
    }
    Run_Chaining(dict,queries);
  //  Run_OpenAddressing(dict,queries);
 //   Run_DoubleHashing(dict,queries);
}

void Run_Chaining(vector<string> dict,vector<string> queries)
{
    ofstream file;
    file.open("chainingdata.txt");
    for (int i=1;i<=50;i++)
    {
    startTimer();
    HashC Table(i);
    for (int r=0;r<dict.size();r++)
        Table.insert(dict[r]);
    double time =stopTimer();
    startTimer;
    for (int r=0;r<queries.size();r++)
        Table.lookup(queries[r]);

    float time2=stopTimer();
    string temp="Parameter: ";
    stringstream ss;
    ss << i;
    temp=temp+ss.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Insertion-Time: ";
    stringstream ss1;
    ss1 << time;
    temp=temp+ss1.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Look-Up Time: ";
    stringstream ss2;
    ss2 << time2;
    temp=temp+ss2.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Collisions: ";
    stringstream ss3;
    ss3 << Table.Collisions();
    temp=temp+ss3.str()+"\n\n";

    file.write(temp.c_str(),temp.size());

    }
}

void Run_OpenAddressing(vector<string> dict,vector<string> queries)
{
    ofstream file;
    file.open("OpenAddData.txt");
    for (int i=1;i<=50;i++)
    {
    startTimer();
    OpenAddress Table(i);

    for (int r=0;r<dict.size();r++)
        Table.insertItem(dict[r]);
    double time =stopTimer();
    startTimer;
    for (int r=0;r<queries.size();r++)
    {
        string result = Table.lookUp(queries[r]);
    }
    float time2=stopTimer();
    string temp="Parameter: ";
    stringstream ss;
    ss << i;
    temp=temp+ss.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Insertion-Time: ";
    stringstream ss1;
    ss1 << time;
    temp=temp+ss1.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Look-Up Time: ";
    stringstream ss2;
    ss2 << time2;
    temp=temp+ss2.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Collisions: ";
    stringstream ss3;
    ss3 << Table.Collisions();
    temp=temp+ss3.str()+"\n\n";
    file.write(temp.c_str(),temp.size());
    cout <<"."<<endl;
    }
}

void Run_DoubleHashing(vector<string> dict,vector<string> queries)
{
    ofstream file;
    file.open("DoubleHashData.txt");
    for (int i=1;i<=50;i++)
    {
    startTimer();
    DoubleHash Table(i);

    for (int r=0;r<dict.size();r++)
        Table.insertItem(dict[r]);
    double time =stopTimer();
    startTimer;
    for (int r=0;r<queries.size();r++)
    {
        string result = Table.lookUp(queries[r]);
    }
    float time2=stopTimer();
    string temp="Parameter: ";
    stringstream ss;
    ss << i;
    temp=temp+ss.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Insertion-Time: ";
    stringstream ss1;
    ss1 << time;
    temp=temp+ss1.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Look-Up Time: ";
    stringstream ss2;
    ss2 << time2;
    temp=temp+ss2.str()+"\n";
    file.write(temp.c_str(),temp.size());
    temp="Collisions: ";
    stringstream ss3;
    ss3 << Table.Collisions();
    temp=temp+ss3.str()+"\n\n";
    file.write(temp.c_str(),temp.size());
    }
}
