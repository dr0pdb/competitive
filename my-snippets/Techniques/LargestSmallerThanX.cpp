/*
	Returns the largest number smaller than or equal to x using binary search in a sorted vector. 
*/

int searchLargestConstrained(vll &arr, int low, int high, ll x){
	if(low > high){
		return -1;
	}

	if (x>=arr[high])
	{
		return high;
	}

	int mid = (low+high)/2;

	if (arr[mid]==x)
	{
		return mid;
	}

	if (mid > 0 && arr[mid-1] <= x && x < arr[mid]){
        return mid-1;
	}

	if (x < arr[mid]){
        return searchLargestConstrained(arr, low, mid-1, x);
	}

	return searchLargestConstrained(arr,mid+1,high,x);
}

int getIndex(const std::vector<ll>& V, ll val)
{
    auto iter = std::upper_bound(V.begin(), V.end(), val);
    if (iter != V.begin())
       return std::distance(V.begin(), std::prev(iter));

    return 0;
}
