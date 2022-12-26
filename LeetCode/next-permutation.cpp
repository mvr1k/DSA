class Solution {
public:
    void reverse(vector<int> &Arr,int l,int r){
        while(l < r)
        {
            swap(Arr,l++,r--);
        }
        return;
    }
    void swap(vector<int> &Arr,int l,int r){
        int temp = Arr[l];
        Arr[l] = Arr[r];
        Arr[r] = temp;
        return;
    }
    void nextPermutation(vector<int>& nums) {
        //finding the index where left < Right
        int n = nums.size();
        int leftPeek = -1;
        for(int i = n - 1;i > 0;i--){
            if(nums[i] > nums[i- 1]){
                leftPeek = i - 1;
                break;
            }
        }
        //reverse the Array if leftPeek is still -1(its in decreasing Order)
        if(leftPeek == -1){
            reverse(nums,0,n-1);
            return;
        }
        //finding the element that is exactly greater than this number on its left
        int justBigEnough = -1;
        for(int i = leftPeek + 1;i < n;i++){
            if(justBigEnough == -1){
                justBigEnough = i;
            } else {
                if(nums[i] > nums[leftPeek] && nums[i] < nums[justBigEnough])
                {
                    justBigEnough = i;
                }
            }
        }
        //after finding the just big enough number swap it with the left peek
        swap(nums,leftPeek,justBigEnough);
        //sort the right haft right after swapping the left half
        sort(nums.begin() + leftPeek + 1,nums.end());
        return;
    }

};