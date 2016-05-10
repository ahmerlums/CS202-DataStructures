#include "doubleHash.cpp"

int main()
{
    cout << "Enter the name of the file: ";
    string temp;
    cin >> temp;
    ifstream file;
    file.open(temp.c_str());
    DoubleHash Table(17);
    while(!file.eof())
    {
        getline(file,temp,'\n');
        Table.insertItem(temp);
    }
    cout <<"Enter the word to search: ";
    cin >>temp;
    if (Table.lookUp(temp)==temp)
        cout<<"The word is present!"<<endl;
    else
        cout <<"Word not present!" << endl;


}
