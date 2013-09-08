#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    �����������
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
    2:��������
        1��������ض��ٵ���
        2��Ҫ�������е�����������Ҫ����ϵͳ
            ����֪����������������У�����
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
    ������Ҫ����
*/
int missiles2(int arr[], int n)
{
    if (arr == NULL || n <= 0)
        return 0;
    vector<int> dp(n, 0);
    // dp[i]��ʾ��i�����ĸ߶�
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
                { // Ҫ���������ߵ�
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
    �����ϳ�����
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
    ������ɣ�
        ÿ������ļ۸񶼱���һ�εĵ�
        ��½�������
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
	װ�����⣺
		��������ΪV��n����Ʒ��ÿ����Ʒ�������ʹ�����ӵ�������С
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
    ��άdp����д����άת�Ʒ��̣����Ƿ����ת��Ϊһά...
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
	��ҩ��
		�����ļ�medic.in�ĵ�һ������������T��1 <= T <= 1000����M��1 <= M <= 100������һ���ո������
		T�����ܹ��ܹ�������ҩ��ʱ�䣬M����ɽ����Ĳ�ҩ����Ŀ����������M��ÿ�а���������1��100֮�䣨����1��100����������
		�ֱ��ʾ��ժĳ���ҩ��ʱ��������ҩ�ļ�ֵ��
	����һ�ر�����
		�����һά����Ҫ�Ӻ���ǰ����
		����ö�ά���޴�����

	����N�ر�����
		�����һά����Ҫ��ǰ��ǰ����

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
	// ��Ҫ�и���ǣ���¼�Ƿ���Թ��ɣ����������Ϊ0
	dp[0] = 1;
	dp[time[0]] = value[0];
	for (int i = 1; i < M; ++i)
	{
		// �ö�ά��ʱ�򣬾Ͳ��ÿ��ǴӺ���ǰ�������ˣ���Ϊ[i][j]��[i-1][j]������һ���洢λ��
		for (int j = T; j >= time[i]; --j)
		{
			if (dp[j - time[i]])
				dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
		}
	}
	cout << (dp[T] - 1) << endl;
}
/*
	��ά��̬�滮��
		��ν��ά״̬����˵һ����Ƶ�״̬��opt[i,j]��ʽ�ġ���i,j ���Դ���ʲô�أ�
		(1)i,j �����������һ��������꣨��Ȼ��ƽ������ϵ�����磺�ֵ����⣩��
		(2)i,j ��ϱ�ʾһ������ĵ�Ԫ��λ�ã���i�У���j�У����磺�������⣩
		(3)���Ϊi ����Ϊj�����䡣���磺���Ĵʣ�
		(4)���Ϊi �յ�Ϊj�����䡣���磺ʯ�Ӻϲ����⣩
		(5)����û�������������1 �ĵ�i ��λ�ã���Ӧ����2 �ĵ�j  ��λ�ã����������ƣ�
		(6)�������У���һ�����е�ǰi ��λ�û��i ��λ�ö�Ӧ��2 �����еĵ�j  ��λ�û�ǰj  ��λ�á�������������У���
		(7)����
*/

/*
	�����������
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
	���Ĵ�
	�������һ���ַ�����ͨ�����������ַ��������Ա��һ�����Ĵʡ�
	����������ַ�����ɻ��Ĵ��������������ַ���
	�����ַ�����Ab3bd �����ڲ��������ַ�����Ա��һ�����Ĵʣ���dAb3bAd ����Adb3bdA ������
	Ȼ���� �����������µ��ַ��޷�ʹ�����һ�����Ĵ�
*/
/*
	˼·һ��
		�Գ���Ϊ�׶ν��л���
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
	˼·������str��ת����Ϊ�ڶ����ַ����������ַ����������������
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
	�������Σ�
		ѧУ�������ϣ��涨�ϳ���Ҫ�μӱ�����������Ա���·���ɫ���ܻܺ��ң�
		�ϳ���ԱӦ�ų�һ���ţ����·���ɫ���������ҶԳƵġ�
		���磺�����������족�򡰺����������족���Ƿ��ϵģ����������̺족���������족�Ͳ�����Ҫ��
		�ϳ���������Ȼ�ܶ࣬�����е�ͬѧ�Ϳ��ܻ��� 3000  ������ʦϣ�����ϳ��ӵ����÷���Ҫ�󣬵���Ҫ���������٣������鷳��������һ������Ϊ��һ�ε�����
		1���ڶ�������ұ߼�һ���ˣ��·���ɫ��Ҫ���������
		2 ���ڶ��������������м����һ���ˣ��·���ɫ��Ҫ���������
		3���޵�һ���ˣ�
		4 ����һ���˻��·���ɫ��
		��ʦ��֪����Ŀǰ�Ķ������ٵĵ��������Ƕ��٣������һ���������ش�����
		��Ϊ����ϳ��Ӻ����ţ��������Ϊ���������޵ģ�����ʱ���һ���˶����ҵ��ˡ�ͬʱ�·���ɫҲ������ġ�
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
	�����������չ:
	sqybi ������m �����,��Ҳͨ��һ��ʱ���Ŭ���ܵ���r ����Ʒ.��ƾ����Щ�������Ʒ�����ݵ�һЩMM.
	����֪��, �Լ��ݵ�����MM���ѵ�����ʱ���Ƕ���.
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
	�������⣺һ��ʱ���ڣ�������ʹ�õ÷����
	��M�ŵ���ÿһ��Ҫ�����ѵ�ʱ��Ϊtime[i],�÷�Ϊvalue[i]��
	�ڹ涨ʱ��L�ڣ��õ�������ֵ
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
	���䶯̬�滮
*/
/*
	ʯ�Ӻϲ�
	��һ���ٳ��ϰڷ���һ�й�n �ѵ�ʯ�ӡ���Ҫ��ʯ������غϲ���һ�ѡ��涨ÿ��ֻ��ѡ���ڵ�����
	�ϲ����µ�һ�ѣ������µ�һ��ʯ������Ϊ�ôκϲ��ĵ÷֡���༭�������n ��ʯ�Ӻϲ���һ�ѵ���С
	�÷ֺͽ�n ��ʯ�Ӻϲ���һ�ѵ����÷֡�
	dpmin[i][j] = min(dpmin[i][k] + dpmin[k+1][j] + sum(a[i], a[j]))
	dpmax[i][j] = max(dpmax[i][k] + dpmax[k+1][j] + sum(a[i], a[j]))
	i <= k < j

	��Ҫ����Ŀ�еĻ�������������÷������⡣
		���巽�����ѻ��ضϣ�����һ�ݷŵ��ضϺ��γɵ����ĺ����γ�һ��������ԭ����������
		��ֻ�л��е�Ԫ���ڴ���ʱ�����ű仯���Ϳ�������������ʵ���������Ѿ�����ض��ˣ�
	Ҫ�ϲ�һ���������ʯ�����ۺϲ���˳��������ĵ÷ֶ�����������ڵ�����ʯ�ӵĺͣ����Կ�����
	һ������sum[i]��ϲ�ǰi��ʯ�ӵĵ÷֡�
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
	����������
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
			// dp[i][i]û�����壡i<k<j
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
	ͳ�Ƶ��ʸ�����

*/

/*
	���������ƣ�ÿһ������Ҫ���룡
		ǰi�����ŵ�ǰj����ƿ�е������ѧֵ
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
	�����㷨������Ƿ�����
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
	��ά��״̬opt[i,j,k]һ��ɱ�ʾ����ĺ��壺
	��1����ά״̬�Ļ����ϼ���ĳ��������������һά���������
	����opt[L,i]��ʾ���ΪI������ΪL �����е�����ֵ��opt[L,i,j]�Ϳɱ�ʾ�����i �������j��������L���������е�����ֵ��
    ��2��I��J ��K ��ϱ�ʾһ�������Σ���i,j����Ϊһ�ǣ��߳�ΪK����
	��3��I��J ��K ��ϱ�ʾһ���ȱ������Σ���i,j����Ϊһ�ǣ��߳�ΪK����
    ��ά�����˶�ά����ά�������⣬��������i,j,k,t ���������һ�����Σ�
    ��i,j����ͣ�k,t�����������Զ��㡣
	�����ռ��Ż���
	�������飬����������ǰ��Ҳ�ᵽ������ʵ�ܼ򵥣����һ��״̬�ľ��ߵĲ���ΪN��ֻ��������������N��һ��N=1�����׶ε�״̬��
	��Ϊ��ǰ״ֻ̬�ͺ�N ���׶��е�״̬�йأ�����ǰ���Ѿ����ù��ˣ�û���˾Ϳ����滻���ˡ�
	����ʵ�������ֻ���±������������ʡʱ�䣩��X ��=K1 ��K1 ��=K2 ��K2 ��=K3 ��K3 ��=X
	������ʵ����һ��N=3  ���±�Ĺ������ڹ��������״̬���漰�ۼӣ��۳���Ĳ���Ҫע�⽫��ǰҪ���״̬��ʼ����
    ����ʱ���Ż�������һЩ���ݽṹ���ѣ����鼯��HASH�����Ͳ��Ҹ��Ӷȡ�
    ʱ��ռ�˫���Ż����ı�״̬�ı�ʾ��������״̬ά����
*/

/*
	�Ƿ��ӣ���M*N�ľ�����������������
	������������
	   4 4
	   0 1 1 1
	   1 1 1 0
	   0 1 1 0
       1 1 0 1
    �����������
	   2
*/
/*
	ֱ�ӷ�����
		dp[l][i][j] = dp[l-1][i][j] && dp[l-1][i+1][j] && dp[l-1][i][j+1] && matrix[i+l][j+l]
	�Ż�������
		ֻ��Ҫ֪����(i,j)Ϊ���Ͻǵ���󳤶ȵ������ξͿ�����
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
	����̶�̬�滮��
	����ȡ����
		N*N����ÿһ����һ�����֣������Ͻǵ����½ǣ�û��һ��ȡһ������ֵΪ�㡣
		һ�������Σ������
	dp[i1][j1][i2][j2] = max(
			dp[i1-1][j1][i2-1][j2], dp[i1-1][j1][i2][j2-1],
			dp[i1][j1-1][i2-1][j2], dp[i1][j1-1][i2][j2-1])
			if (i1 == i2 && j1 == j2)
				dp[i1][j1][i2][j2] += matrix[i1][j1];
			else
				dp[i1][j1][i2][j2] += matrix[i1][j1] + matrix[i2][j2];

	opt[k,i1,i2]��ʾ���ڽ׶�K ʱ�ߵ�i1,i2 ������·����ȡ�õ��������͡�
	�������˼ά���������̬ת�Ʒ��̣�
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
