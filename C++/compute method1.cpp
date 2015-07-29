#include <iostream>

using namespace std;
struct num
{
    double x;
    double y;
};
struct num number[1000000];
double ln[10000000];





int main()
{
    int i;

    int n;
    double h;
    cout << "please input the amount!"<<endl;
    cin >> n;
    h = 10.0 / n;
    for (i = 0; i <= n; i++)
    {
        number[i].x = -5.0 + i*h;
        number[i].y = 1 / (1 + number[i].x*number[i].x);

        ln[i] = 1.0;
    }

    double x;
    cout << "please input the x" << endl;

    while (cin>>x)
    {
        int j, k;
        double result;
        result = 0;
        k = 0;
        while (k <= n)
        {
            for (j = 0; j <= n; j++)
            {
                if (j == k)
                    continue;
                else
                {
                    ln[k] = ln[k] * (x - number[j].x) / (number[k].x - number[j].x);
                }
            }
            result = result + ln[k] * (number[k].y);
            k = k + 1;
        }
        cout << result << endl;
        result=0;
        k=0;
        for (i = 0; i <= n; i++)
        {


            ln[i] = 1.0;
        }
    }
    return 0;
}

