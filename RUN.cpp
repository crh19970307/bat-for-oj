/**
* 添加批处理程序
* 对拍程序入口 点击 RUN.exe 即可运行
*/
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    int T;
    cout << "Please input the number of test :" << endl;
    cin >> T;
    bool ok = 1;
    for(int i = 1;i <= T;i ++)
    {
        cout << "On test : " << i << endl;
        system("DATA > data.in");
        system("AC < data.in > AC.out");
        system("WA < data.in > WA.out");
        if(system("fc AC.out WA.out"))   {
        	cout << "------ WA on test " << i << " -------" << endl;
            ok = 0;
        	break;
        }
    }
    if(ok) cout << "------ successfully! --------" << endl;
    system("pause");
    return 0;
}