#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> countfreq()
{
    unordered_map<char,int>m;
    ifstream inputfile;
    cout<<"enter file name to be compressed:\n";
    string filename;
    cin>>filename;
    inputfile.open(filename,ios::in);
    string text,line;
     if(inputfile.fail())
     {
       cout<<"Opening "<<filename<<" file for reading\n";
       cout<<"---------------------------------------\n";
       cout<<"The "<<filename<<" file could not be opened!\n";
       cout<<"Possible errors:\n";
       cout<<"1. The file does not exist.\n";
       cout<<"2. The path was not found.\n";
       exit(1);
      }
     else
      {
       cout<<"The "<<filename<<"file was opened successfully:\n";
        if (inputfile.is_open())
        {
          while ( getline (inputfile,line) )
          {
           cout << line << '\n';
           text+=line;
           text+=" ";
          }
          inputfile.close();
         }
      }
      //conting the frequency of the diffrent character in the given file
      for(char character : text)
      {
          m[character]+=1;
      }
      //cout<<"char"<<"  freq"<<endl;
     /* for(auto it=m.begin();it!=m.end();it++)
      {

          cout<<it->first<<"->"<<it->second<<endl;
      }*/
      //cout<<line<<" ";

    return m;
}
