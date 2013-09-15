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

void Process()
{	
	int T;
	int M;
	int caseid = 0;
	cin >> T;
	
	while(caseid < T)
	{
		cin >> M;
		map<string,int> Mymap;
		NODE graph[MAXSIZE];

		int id = 0;
		for(int i=0;i<M;i++)
		{
			char s1[MAXSIZE],s2[MAXSIZE];
			cin >> s1 >> s2;
			string str_s1(s1),str_s2(s2);
			NODE node1,node2;
			int id1,id2;
			if(Mymap.count(str_s1)==0)
			{
				Mymap[str_s1] = id;
				id1 = id;
				id++;
			}
			else
				id1 = Mymap[str_s1];
			if(Mymap.count(str_s2)==0)
			{
				Mymap[str_s2] = id;
				id2 = id;
				id++;
			}
			else
				id2 = Mymap[str_s2];
			graph[id1].neigh_list.push_back(id2);
			graph[id2].neigh_list.push_back(id1);
		}

		//judge whether it is a bipartigraph
		for(int i=0;i<MAXSIZE;i++)
		{
			graph[i].color = -1;
		}
		if(JudgeBiGraph(0,graph))
		{
			cout << "Case #" << (caseid + 1) << ": Yes" << endl;
			//printf("Case #%d: Yes\n",caseid+1);
		}
		else
		{
			//printf("Case #%d: No\n",caseid+1);
			cout << "Case #" << (caseid + 1) << ": No" << endl;
		}
		caseid++;
	}
}

