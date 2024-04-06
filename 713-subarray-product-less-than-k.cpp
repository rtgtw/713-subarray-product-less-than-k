/*

713. Subarray with product less than a target

Given an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30                                              
Output: [2], [5], [2, 5], [3], [5, 3], [10]                           
Explanation: There are six contiguous subarrays whose product is less than the target.



Solution:

To solve this, we can employ the sliding window and two pointer techniques

1. Our goal is to find all subarrays within the integer array where the product
is less than the specified target value


2.We are going to use the two pointer + sliding window approach





*/



#include <iostream>
#include <vector>



class Solution {
public:
	std::vector<std::vector<int>> findSubarrays(const std::vector<int>& arr, int target);
};



std::vector<std::vector<int>> Solution::findSubarrays( const std::vector<int>& arr, int target) {

	//Variables needed:
	//product counter
	//Left Pointer and right pointer
	// Result vector to hold all of the results
	//A temp vector which will be used to insert all element combinations

	//Result vector, this will be a vector of vectors (array of arrays)
	//We will pass our temp vector results to the official result vector
	std::vector<std::vector<int>> result;

	//Product variable, which starts at 1 so we can multiply the elements we come in contact with
	double product = 1;

	//Left pointer which will start at the first element
	int left = 0;

	//Right pointer which will also start at the first element

	int right = 0;




	//To achieve the sliding window we want to expand the right pointer and
	//have the left pointer trail the right
	//To achieve this we can create a for loop that will iterate through the length 
	//of the vector
	for (right; right < arr.size(); right++) {

		//Now at each iteration of the array, we can create our logic

		//First we want to find the product of the element at right
		product = product * arr[right];

		//Now that we have the product, our goal is to find all subarrays that have a product less than the target
		//We can start by creating logic if the product is more than the target, this means we need to 
		//divide left by the product, we want to continue to do this until our product is less than the target
		//Once this operation is done, left will potentially be more than right, so with that in mind
		//all further operations will only be if left is less than or equal to right (since they start at the same spot), if left is more than right
		//then we want to continue to iterate right along the array
		while (left < arr.size() && product >= target) {

			//We want to reduce the size of our product by the element at left
			//then we want to increment left along the array

			product = product / arr[left];
			left++;
		}


		//Approaching this point within the for loop, there can be two potential scenarios
		//the product was more than the target, and we incremented left, at this point though, left is greater than right,
		//so we want to move forward within the array

		//if the product was never larger than the target, then we want to create logic that 
		//Inserts all combinations of elements that are smaller than the target
		//We can create a temp vector to insert the elements , and to push it to our result
		//A new vector should be created before entering the for loop
		//this means that a new vector is created upon each iteration of the array, which is what we want
		std::vector<int> tempArr;

		//We want to create a for loop that works backwards, we already know that from right to left
		//these element's product is less than the target, so we want to individually include the single element
		//and then include all of the other combinations.
		//This can be achieved through a for loop, that keeps track of what we have already inserted,
		//And then works towards left to insert the other elements that are between right - left
		//We want to give i its own variable which is right, so we dont mess with right or left
		for (int i = right; i >= left; i--) {

			//Insert the element at arr[i] inside of the temp array
			//At the beginning 
			//This will account for all combinations because the elements stay within
			//the temp array until this loop finishes
			tempArr.insert(tempArr.begin(), arr[i]);

			//Then we want to push to the end of the result array
			result.push_back(tempArr);
			
		}

	}


	//After the for loop, results should have all of the combinations

	return result;

}


int main() {

	Solution solution;

	std::vector<int> array1 = { 2, 5, 3, 10 };

	int target = 30;

	std::vector<std::vector<int>> answer = solution.findSubarrays(array1, target);



	for (std::vector<int> row : answer) {
		for (int num : row) {

			std::cout << num;

		}
		std::cout << ' ';
	}

	//Time complexity: O(n^2)
	// Space complexity: O(n)
	//Time spent 4H


	return 0;
}