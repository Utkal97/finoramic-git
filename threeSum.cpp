int Solution::threeSumClosest(vector<int> &A, int required_sum) {

	//if length of given array < 3
    if(A.size()<3) {
        int sum = 0;

		//closest sum will be sum of all elements
        for(int i=0;i<A.size();i++) 
            sum+=A[i];

        return sum;
    }

	//sort the array so that we can choose the right combination quickly
    sort(A.begin(), A.begin()+len);

	//initially, let closest sum be the sum of first 3 elements
    int closest_sum = A[0]+A[1]+A[2];
    
    int len = A.size();

	//for every element
    for(int i=0; i<len-2; i++) {

        int left=i+1, right=len-1;

		//check for every combination including the current element, which is closest
        while(left<right) {

            int current_sum = A[i]+A[left]+A[right];

            if(current_sum == required_sum)
                return required_sum;

			//if current sum is nearer to required sum than the closest sum 
            else if( abs(closest_sum - required_sum) > abs(current_sum - required_sum) )
            	//closest sum is the current sum
                closest_sum = current_sum;

			//get the next combination by comparing the value of current sum to required sum
            if(currSum<required_sum)
                left++;
            else
                right--;
        }
    }
    return closest_sum;
}

