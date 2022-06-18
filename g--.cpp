#include<Windows.h>
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void compile(char* filename)
{

}
int main(int args, char *argv[])
{
	for(int i = 1; i < args; i++)
	{
		if (strcmp(argv[i], "-v") == 0)
		{
			cout << "g-- 版本 1.0.0" << endl;
			continue;
		}
		ifstream fin(argv[i]);
		if(!fin)
		{
			if(argv[i][0] == '-')
			{
				cout << "g--: " << argv[i] << " 选项未知。" << endl;
			}
			else
			{
				cout << "g--: " << argv[i] << " 打开失败。" << endl;
			}
			continue;
		}
		else
		{
			try
			{
				compile(argv[i]);
			}
			catch(...)
			{
				cout << "g--: " << argv[i] << ": 编译时发生错误。" << endl;
			}
		}
	}
	return 0;
}