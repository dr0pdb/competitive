//dp table
ll dp[20][185][2];

void getDigits(long long x, vector <int> &digit)
{
    while (x)
    {
        digit.push_back(x%10);
        x /= 10;
    }
}

long long value(int idx, ll sum, bool tight,
                          vector <int> &digit)
{
    // base case
    if (idx == -1)
       return sum;
 
    if (dp[idx][sum][tight] != -1 and !tight)
        return dp[idx][sum][tight];
 
    long long ret = 0;
 
    // calculating range value
    int k = (tight)? digit[idx] : 9;
 
    F(i,0,k+1)
    {
        // caclulating newTight value for next state
        int newTight = (digit[idx] == i)? tight : 0;
 
        // fetching answer from next state
        ret += value(idx-1, sum+i, newTight, digit);
    }
 
    if (!tight)
      dp[idx][sum][tight] = ret;
 
    return ret;
}

ll rangeValue(ll left, ll right){

	//initialise dp table
	memset(dp,-1,sizeof(dp));

	vi digitLeft;
	getDigits(left-1, digitLeft);

	ll ans1 = value(digitLeft.size()-1,0,true,digitLeft);
	if (left<=1)
	{
		ans1 = 0;
	}

	vi digitRight;
	getDigits(right,digitRight);

	ll ans2 = value(digitRight.size()-1, 0, true, digitRight);
	if (right<=1)
	{
		ans2 = 0;
	}
	
	return ans2 - ans1;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    ll l,r;
    cin>>l>>r;
    cout<<rangeValue(l,r);

	return 0;       
}
