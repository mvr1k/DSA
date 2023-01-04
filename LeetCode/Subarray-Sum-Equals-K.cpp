//algorithm->
//create a hashmap to memoise a sum and 
//how many times we have seen that sum

//in each iteration check wheather we have seen
//sum - k some where if yes then add the numebr of times 
//we have seen that sum to count and then add 1 cause we have seen a sum now





class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //creating the map to memorise the sum and its number of occurances
        unordered_map<int,int> hashmap;

        //init sum as 0
        int sum = 0;

        //memorising that we have seen a sum 0 once
        hashmap[sum] = 1;
        int count = 0;

        for(int i = 0;i < nums.size();i++){
            //1.add the current element to sum
            sum += nums[i];
            //if you have seen the sum - k before n times 
            //than there are n subarrays with the current index
            if(hashmap.find(sum - k) != hashmap.end()){
                count+=hashmap[sum - k];
            }
            //the sum can be a new sum or can be an existing one so
            //we must add one to it cause we are currently seeing it
            hashmap[sum]++;
          
        }
    
        return count;
    }
};