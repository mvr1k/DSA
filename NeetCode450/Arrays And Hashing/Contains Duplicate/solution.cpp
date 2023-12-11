//I am only including the hashmap solution cause it is the most 
//time optimised solution PLEASE DONT COPY PASTE THE CODE if you dont
//understand the code this made you a dumb coder 


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> hashmap;
        
        //going over each element in the array
        for(auto it : nums){
            //have i seen this element ?
            if(hashmap.find(it) != hashmap.end()){
                //yes I have definetly seen this element 
                return true;
            }
        }
        //uff I went thorough the whole array but could not find
        //the element which I have seen more then once
        return false;
    }
};