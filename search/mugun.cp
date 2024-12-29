/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  Thu Dec  5 14:33:32 2024
 Description:   这是一个新的模板描述
 ************************************************************************/

#include "cctype"
#include "string"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;


int a[105],book[105],n,target;// target拼起来的木头根数 
int maxL = 0, sum = 0, maxLLToTry;
bool cmp(int a,int b)
{
	return a>b;
}
bool dfs(int cnt,int len,int pos)
{
	if(cnt == target)	return true;
	if(len == maxLLToTry)return dfs(cnt+1,0,0);

	for(int i=pos;i<n;i++)
	{
		if(book[i] == 0 && len + a[i] <= maxLLToTry)
		{
			book[i] = 1;
			if(dfs(cnt,len+a[i],i)) return true;
			book[i]=0;
			if(len==0) return false;//凑第一根的时候可以随便选
			while( i + 1 < n && a[i+1] == a[i] ) 
                i++;
		}
	}
	return false;
}

int main()
{
    while (cin >> n) {

        if (n == 0) {
            break;
        }

        
        maxL = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            maxL = max(maxL, a[i]);
            
        }
        sort(a, a + n, cmp);

        int res = sum;
        for (int k = maxL; k < sum; ++k) {

            if (sum % k == 0) {
                memset(book, 0, sizeof(book));
                maxLLToTry = k;
                target = sum / k;
                if (dfs(0, 0, 0)) {
                    res = k;
                    break;
                }
            }
        }
        cout << res  << endl;
    }
}
