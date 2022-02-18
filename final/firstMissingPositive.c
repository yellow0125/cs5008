// Created by Yellow on 2021/11/28.
// Name: Cuiting Huang
// CS5008 20018 Data Str, Algo & App in CmpSys SEC 03 Fall 2021 [VAN-2-HY]
// LeetCode problem link: https://leetcode.com/problems/first-missing-positive/
// [Array]
//
// 41.First Missing Positive [hard]
// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include <stdio.h>

// =============== Helper Function =====================
// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// =============== First Missing Positive ===============
//Return -1, if list is NULL
//For list with size n, put 1 at the list[0], put 2 at list[1]
//If value equals to 0 or smaller than it, or bigger than size n ignore.
//First, Put the positive number at the right position
//Second, Find the number list[i]!= list[list[i]-1]
//Return i+1 is the first missing positive
//Return size n+1, if all value at the right position
int firstMissingPositive(int *nums, int numsSize) {
    if (nums == NULL) return -1;
    if (numsSize == 0)return 1;

    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] < numsSize && nums[i] != nums[nums[i] - 1]) {
            swap(&nums[i],&nums[nums[i] - 1]);
        }
    }

    for (int j = 0; j < numsSize; ++j) {
        if (nums[j] != j + 1) {
            return j + 1;
        }
    }
    return numsSize + 1;
}
