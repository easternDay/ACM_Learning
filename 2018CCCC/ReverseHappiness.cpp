#include <iostream>
using namespace std;
int main()
{
    int N;
    char c;
    cin >> c >> N;
    getchar(); //注意！接收换行符，以免留在缓冲区被下一次getchar读取
    char fu[100][100];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fu[i][j] = getchar(); //使用getchar读入任意字符
            if (fu[i][j] != ' ')  //如果不为空格，修改字符
                fu[i][j] = c;
        }
        getchar(); //注意！接收换行符，以免留在缓冲区被下一次getchar读取
    }
    int flag = 1;                       //定义标识，初始化为1，代表不用倒
    for (int i = 0; i < N && flag; i++) //如果不用倒，则继续
        for (int j = 0; j < N; j++)
            if (fu[i][j] != fu[N - i - 1][N - 1 - j]) //如果当前字符不等于对应字符
            {
                flag = 0; //说明需要倒
                break;
            }
    if (flag)
        cout << "bu yong dao le\n";
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--) //i,j的初始值和结束条件都改变，递减，输出
            cout << fu[i][j];
        cout << '\n';
    }
    return 0;
}