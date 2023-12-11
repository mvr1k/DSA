Problem statement : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

Solution: 
    Approach1 : 
        a duplicate value can be found if and only if a value is present in multiple indices so what I can do is stand at a index and check weather there is the same number in some other index which can be done using 2 for loops and O(n ^ 2) time
    Approach2:
        what will happen if I sort the array ? 
        well if it is a duplicate element then it will stay with its duplicate counter part in the sorted array which means I will simply check the array for that element which is same as its next element it will take O(nlog(n)) time for sorting
    Approach3:
        what if I cant change the input array ? 
        there must be some sort of way to memorize what I have seen so far and what I am seeing now.Did somebody say hashmap :)
        if a number is repetead in the array and I take a walk through that array I will surely go through that number more than once which means :
            1. if I ask hashmap have I seen this number? the hashmap will say no for the first time 
            2. if I ask hashmap have I seen this number? the hashmap will say no for the second time
        did we just solve this problem in O(n) but there is additional space usage of O(n) for that hashmap