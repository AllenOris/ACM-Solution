#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("Hc.in","r",stdin);
    freopen("Hc.out", "w", stdout);
    cout << "500 500 100000" << endl;
    for (int i = 0; i < 500;i++)
    {
        for (int j = 0; j < 250;j++)
            cout << 1+rand()%500<<" ";
        cout << 1000000+rand()%2000 << " ";
        for (int j = 0; j < 248;j++)
            cout << 1+rand()%1000<<" ";
        cout << "1" << endl;
    }
    for (int i = 0; i < 100000;i++)
    {

        cout << i%500+1<<" "<<i/500+1<<" "<<i%500+1<<" "<<i/500+260+1 << endl;
    } 
        return 0;
}

