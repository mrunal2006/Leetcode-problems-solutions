class Solution {
    public boolean search(int[] nums, int target) {
 int n=nums.length;
 int low=0;
 int high=n-1;
 while(low<=high){
    int mid= low+(high-low)/2;
       //target found
       if(nums[mid]==target){
        return true;
       }
     
     //if duplicates are there 
    if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
        low++;
        high--;
          continue;
    }

     //if left half sorted
     if(nums[low]<=nums[mid]){
        if(target>=nums[low]&& target<nums[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
     }
     else if(target>nums[mid]&& target<=nums[high]){
            low=mid+1;
        }else{
            high=mid-1;
        }
     
     }
     return false;

 }
        
    
}