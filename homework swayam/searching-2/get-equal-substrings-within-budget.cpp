#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost) {
        //by concept of sliding window
        int n=s.size();
        int j=0;
        int temp=0;
        int ans=0;
        for(int i=0;i<n;i++){
            //keep adding absolute difference till it becomes greater than the cost
            //agar cost se bada nai h to ans me maximum of ans, length of curr substring(i-j+1) krdo
            temp=temp+abs(s[i]-t[i]);
            //agar temp cost se bada hojata hai to window shrink kro substring ke pehle element se 
            //jab tak wo cost se kam na hojaye
            while(temp>maxCost){
                temp=temp-abs(s[j]-t[j]);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        //answer return krdo
        return ans;
    }
