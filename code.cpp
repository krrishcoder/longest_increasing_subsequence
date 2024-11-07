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
