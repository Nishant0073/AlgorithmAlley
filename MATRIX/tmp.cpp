/*

We will generate all possible subsets using the recusion.
While genertaing subset we will check for if any element is selected 
that make the absolute diff is k, if yes then we will skip that element


*/


class Solution {
public:
     int v[1001];
     int getSubsets(vector<int> nums,int i,int k)
     {
        if(i==nums.size())
            return 1;
        int taken = 0;

        if(nums[i]-k<0 || v[nums[i]-k]==0)
        {
            v[nums[i]]++;
            taken += getSubsets(nums,i+1,k);
            v[nums[i]]--;
        }

        taken+=getSubsets(nums,i+1,k);
        return taken;
     }

     int beautifulSubsets(vector<int>& nums, int k) {
        
    }
};