#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define _toTransform(a, b) \
    ss << (a);             \
    ss >> (b);             \
    ss.clear()
#define ll long long
#define inf (ll)1e18
using namespace std;
stringstream ss;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

//  https://www.luogu.com.cn/problem/P1032

/**
 * 题目比较坑爹
 * 没有告诉我有几个
 * 第一个数据比较坑
 * 注意及时跳出bfs，不然第四个会超时
 * 
 **/

string a, b;
struct Node
{
    string str;
    int cnt;
    Node(string str, int cnt) : str(str), cnt(cnt){};
};
string sa[7], sb[7];
map<string, int> vis;
int ans = 15;
int n;
void BFS()
{
    queue<Node> Q;
    //  初始化
    Node start(a, 0);
    Q.push(start);

    while (!Q.empty())
    {
        Node temp = Q.front();
        Q.pop();
        if (temp.cnt > 10)
            continue;

        if (temp.str == b)
        {
            ans = min(ans, temp.cnt);
            break;
        }
        for (int j = 1; j <= n; j++)
        {
            string i = sa[j];
            string temp2 = temp.str;
            while (1)
            {
                if (temp2.find(i) != temp2.npos)
                {
                    string nexts = temp.str;
                    nexts = nexts.replace(temp2.find(i), i.size(), sb[j]);
                    temp2[temp2.find(i)] = '~';
                    if (vis.count(nexts))
                        continue;
                    Node nextt(nexts, temp.cnt + 1);
                    vis[nextt.str] = 1;
                    Q.push(nextt);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); //解决c++输入输出流被卡问题
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    string k, t;

    for (int i = 1; i <= 6; i++)
    {
        cin >> sa[i] >> sb[i];
    }
    int l = 6;
    while (sa[l][0] == '\0')
        l--;

    n = l;

    if (a == b)
    {
        cout << 0 << endl;
        return 0;
    }
    BFS();

    if (ans > 10)
    {
        cout << "NO ANSWER!" << endl;
    }
    else
    {
        cout << ans << endl;
    }

    system("pause");
    return 0;
}