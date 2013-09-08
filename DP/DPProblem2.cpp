#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    最长递增子序列
*/
int maxIncreaseSequence(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[i] >= arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}

/*
    2:导弹拦截
        1：最多拦截多少导弹
        2：要拦截所有导弹，最少需要几套系统
            在已知序列中找最长上升序列！！！
*/
int missiles(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[i] <= arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n-1];
}
/*
    至少需要几套
*/
int missiles2(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    // dp[i]表示第i套最后的高度
    dp[0] = arr[0];
    int cur = 1;
    for (int i = 1; i < n; ++i)
    {
        int tmp = -1;
        for (int j = 0; j < cur; ++j)
        {
            if (dp[j] >= arr[i])
            {
                if (tmp == -1)
                {
                    tmp = j;
                }
                else
                { // 要保留尽量高的
                    if (dp[tmp] > dp[j])
                    {
                        tmp = j;
                    }
                }
            }
        }
        if (tmp != -1)
        {
            dp[tmp] = arr[i];
        }
        else
        {
            dp[cur++] = arr[i];
        }
    }
    return cur;
}

int missiles3(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i-1; j >= 0; --j)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void testMissiles()
{
    int arr[] =
    {
        389, 207, 155, 300, 299, 170, 158, 65
    };
    cout << missiles(arr, sizeof(arr) / sizeof(int)) << endl;
    cout << missiles2(arr, sizeof(arr) / sizeof(int)) << endl;
    cout << missiles3(arr, sizeof(arr) / sizeof(int)) << endl;
}

/*
    三：合唱队形
*/
int singerQueue(int arr[], int n)
{
    vector<int> dp1(n, 1);
    dp1[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    vector<int> dp2(n, 1);
    dp2[n-1] = 1;
    for (int i = n-2; i >= 0; --i)
    {
        for (int j = n-2; j > i; --j)
        {
            if (arr[i] > arr[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return (n - ans);
}

void testSingerQueue()
{
    int arr[] =
    {
        186, 186, 150, 200, 160, 130, 197, 220
    };
    cout << singerQueue(arr, sizeof(arr) / sizeof(int)) << endl;
}

/*
    逢低吸纳：
        每次买入的价格都比上一次的低
        最长下降子序列
*/
int buyLowBuyLower(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i-1; j >= 0; --j)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


/*
	ships
*/
struct Friends
{
	int num1;
	int num2;
};

bool friendSort(const Friends &f1, const Friends &f2)
{
	if (f1.num1 < f2.num1)
		return true;
	else if (f1.num1 > f2.num1)
		return false;
	else
		return f1.num2 <= f2.num2;
}

void ships()
{
	Friends fris[101];
	int riverLong, riverWide;
	while (cin >> riverLong >> riverWide)
	{
		if (riverLong == 0 && riverWide == 0)
		{
			break;
		}
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			Friends f;
			cin >> f.num1 >> f.num2;
			fris[i] = f;
		}
		sort(fris, fris + N, friendSort);
		vector<int> dp(N, 1);
		int ans = 1;
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++i)
			{
				if (fris[i].num2 > fris[j].num2)
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
}

void ships2()
{
	Friends fris[101];
	int riverLong, riverWide;
	while (cin >> riverLong >> riverWide)
	{
		if (riverLong == 0 && riverWide == 0)
		{
			break;
		}
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			Friends f;
			cin >> f.num1 >> f.num2;
			fris[i] = f;
		}
		vector<int> dp(N, 1);
		int ans = 1;
		dp[ans] = 0;
		for (int i = 1; i < N; ++i)
		{
			int tmp = ans - 1;
			for (int j = ans - 1; j >= 0; --j)
			{
				if (fris[i].num2 > fris[j].num2 && fris[i].num1 > fris[j].num1)
				{
					tmp = j;
					break;
				}
			}
			if (tmp == ans - 1)
				dp[ans++] = tmp;
			else
				dp[tmp] = i;
		}
		cout << ans << endl;
	}
}


/*
	装箱问题：
		箱子容量为V，n个物品，每个物品有体积，使得箱子的容量最小
*/
void pack()
{
	int V;
	cin >> V;
	int arr[31];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<bool> dp(V, false);
	for (int i = 0; i < n; ++i)
	{
		for (int j = V; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]])
				dp[j] = true;
		}
	}
	int ans = 0;
	for (int i = V; i >= 0; --i)
	{
		if (dp[i])
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

/*
    二维dp，先写出二维转移方程，看是否可以转换为一维...
*/
void pack2()
{
	int V;
	cin >> V;
	int arr[31];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<bool> > dp(n, vector<bool>(V, false));
	dp[0][arr[0]] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = V; j >= arr[i]; --j)
		{
			dp[i][j] = dp[i-1][j];
			if (dp[i-1][j - arr[i]])
			{
				dp[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = V; i >= 0; --i)
	{
		if (dp[n-1][i])
		{
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}

/*
	采药：
		输入文件medic.in的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），用一个空格隔开，
		T代表总共能够用来采药的时间，M代表山洞里的草药的数目。接下来的M行每行包括两个在1到100之间（包括1和100）的整数，
		分别表示采摘某株草药的时间和这株草药的价值。
	对于一重背包，
		如果用一维，需要从后往前遍历
		如果用二维，无此限制

	对于N重背包，
		如果用一维，需要从前往前遍历

*/
void medic()
{
	int T, M;
	cin >> T >> M;
	int time[101] = {0};
	int value[101] = {0};
	for (int i = 0; i < M; ++i)
	{
		cin >> time[i] >> value[i];
	}
	int dp[1001] = {0};
	// 需要有个标记，记录是否可以构成，如果不能则为0
	dp[0] = 1;
	dp[time[0]] = value[0];
	for (int i = 1; i < M; ++i)
	{
		// 用二维的时候，就不用考虑从后向前的问题了，因为[i][j]与[i-1][j]不共用一个存储位置
		for (int j = T; j >= time[i]; --j)
		{
			if (dp[j - time[i]])
				dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
		}
	}
	cout << (dp[T] - 1) << endl;
}
/*
	二维动态规划：
		所谓二维状态就是说一般设计的状态是opt[i,j]形式的。那i,j 可以代表什么呢？
		(1)i,j 组合起来代表一个点的坐标（显然是平面坐标系）（如：街道问题）。
		(2)i,j 组合表示一个矩阵的单元的位置（第i行，第j列）（如：数塔问题）
		(3)起点为i 长度为j的区间。（如：回文词）
		(4)起点为i 终点为j的区间。（如：石子合并问题）
		(5)两个没关联的事物，事物1 的第i 个位置，对应事物2 的第j  个位置（花店橱窗设计）
		(6)两个序列，第一个序列的前i 个位置或第i 个位置对应第2 个序列的第j  个位置或前j  个位置。（最长公共子序列）。
		(7)其它
*/

/*
	最长公共子序列
*/
void longestCommonSequence(int arr1[], int a, int arr2[], int b)
{
	vector<vector<int> > dp(a + 1, vector<int> (b + 1, 0));
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			if (arr1[i - 1] == arr2[j - 1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[a][b] << endl;
}
/*
	回文词
	任意给定一个字符串，通过插入若干字符，都可以变成一个回文词。
	求出将给定字符串变成回文词所需插入的最少字符数
	比如字符串“Ab3bd ”，在插入两个字符后可以变成一个回文词（“dAb3bAd ”或“Adb3bdA ”）。
	然而， 插入两个以下的字符无法使它变成一个回文词
*/
/*
	思路一：
		以长度为阶段进行划分
*/
void palindrome(string str)
{
	int len = str.length();
	vector<vector<int> > dp(len, vector<int>(len, 0));
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < len - k; ++i)
		{
			int j = i + k;
			if (k == 1)
			{
				if (str[i] != str[j])
				{
					dp[i][j] = 1;
				}
			}
			else
			{
				dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
				if (str[i] == str[j])
				{
					dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
				}
			}
		}
	}
	cout << dp[0][len-1] << endl;
}
/*
	思路二：将str翻转，作为第二个字符串，两个字符串求最长公共子序列
*/
void palindrome2(string str1, string str2)
{
	int len = str1.length();
	vector<vector<int> > dp(2, vector<int>(len + 1, 0));
	int flag = 0;
	for (int i = 1; i <= len; ++i)
	{
		for (int j = 1; j <= len; ++j)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[flag][j] = dp[1-flag][j-1] + 1;
			}
			else
			{
				dp[flag][j] = max(dp[1-flag][j], dp[flag][j-1]);
			}
		}
		flag = 1 - flag;
	}
	cout << (len - dp[1-flag][len]) << endl;
}


/*
	调整队形：
		学校艺术节上，规定合唱队要参加比赛，各个队员的衣服颜色不能很混乱：
		合唱队员应排成一横排，且衣服颜色必须是左右对称的。
		例如：“红蓝绿蓝红”或“红蓝绿绿蓝红”都是符合的，而“红蓝绿红”或“蓝绿蓝红”就不符合要求。
		合唱队人数自然很多，仅现有的同学就可能会有 3000  个。老师希望将合唱队调整得符合要求，但想要调整尽量少，减少麻烦。以下任一动作认为是一次调整：
		1、在队伍左或右边加一个人（衣服颜色依要求而定）；
		2 、在队伍中任两个人中间插入一个人（衣服颜色依要求而定）；
		3、剔掉一个人；
		4 、让一个人换衣服颜色；
		老师想知道就目前的队形最少的调整次数是多少，请你编一个程序来回答他。
		因为加入合唱队很热门，你可以认为人数是无限的，即随时想加一个人都能找到人。同时衣服颜色也是任意的。
*/
void modifyQueue()
{
	int arr[3001];
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
	for (int k = 1; k < N; ++k)
	{
		for (int i = 0; i < N - k; ++i)
		{
			int j = i + k;
			if (k == 1)
			{
				if (arr[i] != arr[j])
				{
					dp[i][j] = 1;
				}
			}
			else
			{
				dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
				if (arr[i] == arr[j])
				{
					dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i+1][j-1] + 1);
				}

			}
		}
	}
	cout << dp[1][N-1] << endl;
}

/*
	背包问题的拓展:
	sqybi 现在有m 块大洋,他也通过一段时间的努力攒到了r 的人品.他凭借这些大洋和人品可以泡到一些MM.
	他想知道, 自己泡到最多的MM花费的最少时间是多少.
*/
void pack3()
{
	int N;
	cin >> N;
	int money[11];
	int rp[11];
	int time[11];
	for (int i = 0; i < N; ++i)
	{
		cin >> money[i] >> rp[i] >> time[i];
	}
	int dp[101][101][1001] = {0};
	dp[0][0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1000; j >= time[i]; --j)
		{
			for (int k = 100; k >= rp[i]; --k)
			{
				for (int t = 100; t >= money[i]; --t)
				{
					if (dp[j-time[i]][k-rp[i]][t-money[i]])
					{
						dp[j][k][t] = max(dp[j][k][t], dp[j-time[i]][k-rp[i]][t-money[i]]+1);
					}
				}
			}
		}
	}
}

/*
	看碟问题：一定时间内，看碟，使得得分最大
	买M张碟，每一张要看花费的时间为time[i],得分为value[i]。
	在规定时间L内，得到的最大分值
*/
void watchDVD()
{
	int N, M, L;
	cin >> N >> M >> L;
	int time[21];
	int value[21];
	for (int i = 0; i < N; ++i)
	{
		cin >> time[i] >> value[i];
	}
	int dp[21][1001];
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = M; j >= 1; ++j)
		{
			for (int k = 1000; k >= time[i]; --k)
			{
				if (dp[j-1][k - time[i]])
				{
					dp[j][k] = max(dp[j][k], dp[j-1][k - time[i]] + value[i]);
				}
			}
		}
	}
	if (dp[M][L] == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << (dp[M][L] - 1) << endl;
	}
}

/*
	区间动态规划
*/
/*
	石子合并
	在一个操场上摆放着一行共n 堆的石子。现要将石子有序地合并成一堆。规定每次只能选相邻的两堆
	合并成新的一堆，并将新的一堆石子数记为该次合并的得分。请编辑计算出将n 堆石子合并成一堆的最小
	得分和将n 堆石子合并成一堆的最大得分。
	dpmin[i][j] = min(dpmin[i][k] + dpmin[k+1][j] + sum(a[i], a[j]))
	dpmax[i][j] = max(dpmax[i][k] + dpmax[k+1][j] + sum(a[i], a[j]))
	i <= k < j

	先要把题目中的环变成链，这样好分析问题。
		具体方法：把环截断，复制一份放到截断后形成的链的后面形成一个长度是原来两倍的链
		（只有环中的元素在处理时不随着变化，就可以这样做。其实读入数据已经帮你截断了）
	要合并一个区间里的石子无论合并的顺序如何它的得分都是这个区间内的所有石子的和，所以可以用
	一个数组sum[i]存合并前i个石子的得分。
*/
void stoneMerge()
{
	int N;
	cin >> N;
	int arr[1001];
	vector<vector<int> > dp1(N, vector<int>(N, 0));
	vector<vector<int> > dp2(N, vector<int>(N, 0));
	cin >> arr[0];
	dp1[0][0] = arr[0];
	dp2[0][0] = arr[0];
	for (int i = 1; i < N; ++i)
	{
		cin >> arr[i];
		dp1[i][i] = arr[i];
		dp2[i][i] = arr[i];
		arr[i] += arr[i-1];
	}

	for (int l = 1; l < N; ++l)
	{
		for (int i = 0; i < N - l; ++i)
		{
			int j = i + l;
			for (int k = i; k < j; ++k)
			{
				dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k+1][j] + arr[j] - arr[i-1]);
				dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k+1][j] + arr[j] - arr[i-1]);
			}
		}
	}
	cout << dp1[0][N - 1] << endl;
	cout << dp2[0][N - 1] << endl;
}


/*
	能量项链：
*/
void energyNecklace()
{
	int N;
	cin >> N;
	int arr[201];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		arr[N + i] = arr[i];
	}
	N <<= 1;
	int dp[201][201] = {0};
	for (int l = 1; l < N; ++l)
	{
		for (int i = 0; i < N - l; ++i)
		{
			int j = i + l;
			// dp[i][i]没有意义！i<k<j
			for (int k = i + 1; k < j; ++k)
			{
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
			}
		}
	}
	int ans = 0;
	N >>= 1;
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, dp[i][i + N]);
	}
	cout << ans << endl;
}

/*
	统计单词个数：

*/

/*
	花店橱窗设计：每一束花都要放入！
		前i束花放到前j个花瓶中的最大美学值
		dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + arr[i][j]);
		dp[i][j] = max(dp[i-1][k] + arr[i][j]); i <= k < j

*/
void flowers()
{
	int F, V;
	cin >> F >> V;
	int arr[101][101];
	for (int i = 0; i < F; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			cin >> arr[i][j];
		}
	}
	int dp[101] = {0};
	dp[0] = 0;
	int ans = 0;
	for (int i = 1; i <= F; ++i)
	{
		for (int j = 100; j >= arr[i-1][j-1]; --j)
		{
			for (int k = j - 1; k >= i; --k)
			{
				dp[j] = max(dp[j], dp[k] + arr[i-1][j-1]);
			}
		}
	}
	cout << dp[V] << endl;
}

/*
	添运算法，结果是否整除
*/
void divisibility()
{
	int count;
	cin >> count;
	int arr[10001];
	while (count--)
	{
		int N, K;
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
	}
}

/*
	三维：状态opt[i,j,k]一般可表示下面的含义：
	（1）二维状态的基础上加了某个条件，或其中一维变成两个。
	比如opt[L,i]表示起点为I，长度为L 的序列的最优值。opt[L,i,j]就可表示起点是i 和起点是j，长度是L的两个序列的最优值。
    （2）I，J ，K 组合表示一个正方形（（i,j）点为一角，边长为K）。
	（3）I，J ，K 组合表示一个等边三角形（（i,j）点为一角，边长为K）。
    四维：除了二维和三维加条件外，还可以用i,j,k,t 组合来描述一个矩形，
    （i,j）点和（k,t）点是两个对顶点。
	常见空间优化：
	滚动数组，滚动数组在前面也提到过，其实很简单，如果一个状态的决策的步长为N就只保留以求出的最后N（一般N=1）个阶段的状态，
	因为当前状态只和后N 个阶段中的状态有关，再以前的已经利用过了，没用了就可以替换掉了。
	具体实现是最好只让下标滚动（这样更省时间）。X ：=K1 ，K1 ：=K2 ，K2 ；=K3 ，K3 ：=X
	这样就实现了一个N=3  的下标的滚动，在滚动完如果状态是涉及累加，累乘类的操作要注意将当前要求的状态初始化。
    常见时间优化：利用一些数据结构（堆，并查集，HASH）降低查找复杂度。
    时间空间双重优化：改变状态的表示法，降低状态维数。
*/

/*
	盖房子：在M*N的矩形中找最大的正方形
	【输入样例】
	   4 4
	   0 1 1 1
	   1 1 1 0
	   0 1 1 0
       1 1 0 1
    【输出样例】
	   2
*/
/*
	直接方法：
		dp[l][i][j] = dp[l-1][i][j] && dp[l-1][i+1][j] && dp[l-1][i][j+1] && matrix[i+l][j+l]
	优化方法：
		只需要知道以(i,j)为左上角的最大长度的正方形就可以了
		dp[i][j] = min(dp[i+1][j+1], dp[i][j+1], dp[i+1][j]) + 1;
*/
void house()
{
	int row, col;
	cin >> row >> col;
	int matrix[1001][1001];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	bool dp[1001][1001][1001] = {false};
	int ans = 0;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			dp[0][i][j] = (matrix[i][j] == 1 ? true : false);
	for (int l = 1; l < min(row, col); ++l)
	{
		for (int i = 0; i < row - l; ++i)
		{
			for (int j = 0; j < col - l; ++j)
			{
				if (dp[l-1][i][j] && dp[l-1][i+1][j] && dp[l-1][i][j+1] && matrix[i+l][j+l])
				{
					dp[l][i][j] = true;
					ans = max(ans, l);
				}
			}
		}
	}
	cout << ans << endl;
}

void house2()
{
	int row, col;
	cin >> row >> col;
	int matrix[1001][1001];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	int dp[1001][1001] = {0};
	int ans = 0;
	for (int i = row - 1; i >= 0; --i)
	{
		for (int j = col - 1; j >= 0; --j)
		{
			int l = max(dp[i+1][j+1], dp[i][j+1]);
			l = max(l, dp[i+1][j]);
			l -= 1;
			if (l <= 0)
			{
				if (matrix[i][j] == 1)
					dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = l;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}


/*
	多进程动态规划！
	方格取数：
		N*N方格，每一个有一个数字，从左上角到右下角，没走一步取一个数，值为零。
		一共走两次，和最大。
	dp[i1][j1][i2][j2] = max(
			dp[i1-1][j1][i2-1][j2], dp[i1-1][j1][i2][j2-1],
			dp[i1][j1-1][i2-1][j2], dp[i1][j1-1][i2][j2-1])
			if (i1 == i2 && j1 == j2)
				dp[i1][j1][i2][j2] += matrix[i1][j1];
			else
				dp[i1][j1][i2][j2] += matrix[i1][j1] + matrix[i2][j2];

	opt[k,i1,i2]表示处于阶段K 时走到i1,i2 的两条路径所取得的数的最大和。
	用上面的思维不难想出动态转移方程：
	max(opt[k-1,i1-1,i2-1],opt[k-1,i1-1,i2],opt[k-1,i1,i2-1],
		opt[k-1,i1,i2])+a[i1,k-i1]+a[i2,k-i2](1<=i1,i2<=n,2<=k<=n*2,i1<>i2)
	otp[k,i1,i2]=opt[k-1,i1-1,i2]+a[i1,k-i1](1<=i1,i2<=n,2<=k<=n*2,i1=i2)
*/
void squareNumber()
{
	int N;
	cin >> N;
	int matrix[11][11];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> matrix[i][j];
	int dp[11][11][11][11] = {0};
	for (int i1 = 0; i1 < N; ++i1)
		for (int j1 = 0; j1 < N; ++j1)
			for (int i2 = 0; i2 < N; ++i2)
				for (int j2 = 0; j2 < N; ++j2)
				{
					if (i1 > 0 && i2 > 0)
						dp[i1][j1][i2][j2] = dp[i1-1][j1][i2-1][j2];
					if (i1 > 0 && i2 > 0)
						dp[i1][j1][i2][j2] = max(dp[i1][j1][i2][j2], dp[i1-1][j1][i2][j2-1]);
					if (j1 > 0 && i2 > 0)
						dp[i1][j1][i2][j2] = max(dp[i1][j1][i2][j2], dp[i1][j1-1][i2-1][j2]);
					if (j1 > 0 && j2 > 0)
						dp[i1][j1][i2][j2] = max(dp[i1][j1][i2][j2], dp[i1][j1-1][i2][j2-1]);
					if (i1 == i2 && j1 == j2)
						dp[i1][j1][i2][j2] += matrix[i1][j1];
					else
					{
						dp[i1][j1][i2][j2] += (matrix[i1][j1] + matrix[i2][j2]);
					}
				}
	cout << dp[N-1][N-1][N-1][N-1] << endl;
}

int main()
{
    //cout << "Hello world!" << endl;
    //testMissiles();
    testSingerQueue();
    return 0;
}
