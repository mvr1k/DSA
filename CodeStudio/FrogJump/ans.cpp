#include <bits/stdc++.h> 
int rec(vector<int> heights,vector<int> &dp,int index){
    //base case
    if(index == 0){
        return 0;
    }
    int left = INT_MAX;
    int right = INT_MAX;


    //take the left recursion 
    if(index - 1 > -1){
        if(dp[index - 1] == -1){
            left = rec(heights, dp, index - 1) + abs(heights[index] - heights[index - 1]);
        } else {
            left = dp[index - 1] + abs(heights[index] - heights[index - 1]);
        }
    }
    //take the right recursion
    if(index - 2 > -1){
        if(dp[index - 2] == -1){
            right = rec(heights, dp, index - 2) + abs(heights[index - 2] - heights[index]);
        } else {
            right = dp[index - 2] + abs(heights[index - 2] - heights[index]);
        }
    }
    

    dp[index] = min(left,right);
    return dp[index];

}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for(int i = 2;i < n;i++){
        int left = dp[i - 1];
        int right = dp[i - 2];
        left += abs(heights[i] - heights[i - 1]);
        right += abs(heights[i] - heights[i - 2]);
        dp[i] = min(left,right);
    }
    return dp[n - 1];
}