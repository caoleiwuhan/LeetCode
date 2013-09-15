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


const int MAXSIZE = 1000;
typedef struct Node NODE;

struct Node
{
	int color;
	vector<int> neigh_list;
};


bool JudgeBiGraph(int start, NODE *graph)
{
	queue<int> Myqueue;

	Myqueue.push(start);
	graph[start].color = 0;
	
	while(!Myqueue.empty())
	{
		int gid = Myqueue.front();
		for(int i=0;i<graph[gid].neigh_list.size();i++)
		{
			int neighid = graph[gid].neigh_list[i];
			if(graph[neighid].color==-1)
			{
				graph[neighid].color = (graph[gid].color+1)%2;
				Myqueue.push(neighid);
			}
			else
			{
				if(graph[neighid].color == graph[gid].color)
					return false;
			}
		}
		Myqueue.pop();
	}
	return true;
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

float  cal_ang(int v,int d){
	double tmp=(9.8*d)/(v*v);
	if(fabs(tmp-1.000000)<1.0e-6){
		tmp=1.000000;
	}
	double res=asin(tmp);
	double pi=acos(-1.0);
	res=res*180/pi;
	return res;
}

void Process()
{	
	int T;
	int M;
	int caseid = 0;
	cin >> T;
	for(caseid = 1;caseid <= T; caseid++)
	{
		int v, d;
		cin >> v >> d;
		double res = cal_ang(v,d);
		res=res/2;
		cout << "Case #" << caseid << ": " << fixed << setprecision(7) << res << endl;
	}
}

