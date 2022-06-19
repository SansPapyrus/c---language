#include<Windows.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<regex>
using namespace std;
void compile(char* filename)
{
	ifstream fin(filename);
	regex r(".+\\.cmm$");
	if (!regex_match(filename, r))
	{
		cout << "文件后缀名不正确!" << endl;
		return;
	}
}
int main(int args, char *argv[])
{
	for(int i = 1; i < args; i++)
	{
		if (strcmp(argv[i], "-v") == 0)
		{
			cout << "g--: 版本1.0.0" << endl;
			return 0;
		}
		ifstream fin(argv[i]);
		if(!fin)
		{
			if(argv[i][0] == '-')
				cout << "g--: " << argv[i] << " 选项未知。" << endl;
			else
				cout << "g--: " << argv[i] << " 打开失败。" << endl;
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
				cout << "g--: " << argv[i] << " 编译时发生错误。" << endl;
			}
		}
	}
	return 0;
}