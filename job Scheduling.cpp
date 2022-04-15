#include<climits>
#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int>> cost
{
    {3,2,4},
    {3,1,5},
    {1,4,7}
};

int count_set_bits(int n)
{
    int ans = 0;
    while(n)
    {
        if(n & 1)
        ans++;
        n = n>>1;
    }
    return ans;
}

int assign_job(int n)
{
    vector<int> dpt(pow(2,n),INT_MAX);
    dpt[0] = 0;
    int tp = pow(2,n),row;
    for(int mask = 0; mask<tp; mask++)
    {
        row = count_set_bits(mask);
        for(int j=0; j<3; j++)
            if(!((1<<j)&mask))
                dpt[mask|(1<<j)] = min((dpt[mask|(1<<j)]),(dpt[mask] + cost[row][j]));
    }
    return dpt[pow(2,n)-1];
}

int main()
{
    cout<<assign_job(3);
    return 0;
}