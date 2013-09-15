#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <cstring>
#include <cctype>
#include <queue>
#include <cmath>
#include <limits>
#include <cfloat>
#include <iomanip>


using namespace std;

#define _MY_DEBUG_

/*
	Process：处理每一组数据
*/
void Process();


struct Node
{
	int num;
	int index;
};

bool compare(const Node &n1, const Node &n2)
{
	if (n1.num < n2.num)
		return true;
	return false;
}

int main()
{

#ifdef _MY_DEBUG_
	string inputStr = "C:/Users/cao/Desktop/test.txt";
	string outputStr = "C:/Users/cao/Desktop/out.out";
	ifstream fin;
	fin.open(inputStr);	

	cin.rdbuf(fin.rdbuf());	

	ofstream fout;
	fout.open(outputStr);

	cout.rdbuf(fout.rdbuf());
#endif

	Process();
	return 0;
}

void Process()
{	
	// memset(matrix, 0, sizeof(matrix));
	//int num1, num2, num3;
	//cin >> num1 >> num2 >> num3;
	//cout << num1 << num2 << num3;
	
	// 直接读取行
	//string str;
	//while (getline(cin, str))
	//{
	//	if (str == "")
	//	{
	//		break;
	//	}
	//	cout << str << endl;
	//}
	// 给定行数读取行
	//string str;
	//int count = 0;
	//cin >> count;
	//cin.get();
	//while (count--)
	//{
	//	getline(cin, str);
	//	cout << str << endl;
	//}

	// 解析
	//string str;
	//while (getline(cin, str))
	//{
	//	stringstream ss(str);
	//	string tmp1, tmp2;
	//	ss >> tmp1 >> tmp2;
	//	cout << tmp1 << " " << tmp2 << endl;;		
	//}

	// 解析
	//string str;
	//while (getline(cin, str))
	//{
	//	stringstream ss(str);
	//	string tmp1, tmp2;
	//	double dNum;
	//	ss >> tmp1 >> tmp2 >> dNum;
	//	cout << tmp1 << " " << tmp2 << " " << dNum << endl;
	//}
	
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		string strs[101];
		int N;
		cin >> N;
		cin.get();
		for (int j = 0; j < N; ++j)
		{
			getline(cin, strs[j]);			
		}
		int ans = 0;
		for (int j = 1; j < N; ++j)
		{
			int k;
			string cur = strs[j];
			for (k = j - 1; k >= 0; --k)
			{
				if (cur.compare(strs[k]) < 0)
				{
					strs[k+1] = strs[k];
				}
				else
				{
					break;
				}
			}
			++k;
			if (k != j)
			{
				++ans;
				strs[k] = cur;
			}
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
}

