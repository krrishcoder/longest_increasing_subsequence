
## memoization

#include <iostream>
#include <limits.h>
#include <algorithm> // For max()

using namespace std;

int t[7][5]; // Memoization table


int helper(int nums[], int n, int prev) {
 
    if (n == 0) {
        return 0;
    }

  
    if (t[n][prev] != -1) {
        return t[n][prev];
    }

    if (  prev > nums[n - 1] ) {
 
        return t[n][prev] = max(1 + helper(nums, n - 1, nums[n - 1]), helper(nums, n - 1, prev));
    } else {
   
        return t[n][prev] = helper(nums, n - 1, prev);
    }
}

int lengthOfLIS(int nums[], int n) {
 
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 5; ++j) {
            t[i][j] = -1;
        }
    }
    
     for (int j = 0; j < 5; ++j) {
            t[j][0] = 0;
        }

    return helper(nums, n, 4);
}

int main() {
    int nums[] = {0, 1, 0, 3, 2, 3};
    int n = 6;

    cout << "Length of longest increasing subsequence: " << lengthOfLIS(nums, n) << endl;

    return 0;
}





















#include <iostream>
#include <limits.h>

using namespace std;

int helper(int nums[] ,int n , int prev){
        if(n==0){
            return 0;
        }

        if(prev > nums[n-1]){
              return max( 1+ helper(nums, n-1, nums[n-1]) ,helper(nums, n-1, prev))  ;
             
        }else{
           return helper(nums, n-1, prev) ;
          
        }
    }

    int lengthOfLIS(int nums[],int n) {

        return helper(nums, n, INT_MAX);
        
    }

int main() {

    int nums[] = {0,1,0,3,2,3};
    int n = 6;
    cout<<"length of logest increasing subsequence : "<<lengthOfLIS(nums, n);

    return 0;
}
