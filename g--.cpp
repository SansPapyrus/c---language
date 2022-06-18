#include<Windows.h>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(int args, char *argv[])
{
	for(int i = 1; i < args; i++)
	{
		if (strcmp(argv[i], "-v") == 0)
		{
			cout << "g-- version 1.0" << endl;

		}
		ifstream fin(argv[i]);
		if(!fin)
		{
			cout<<"Error opening file "<<argv[i]<<endl;
			continue;
		}
		
	}
	return 0;
}