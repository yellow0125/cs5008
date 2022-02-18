// Created by Yellow on 2021/11/29.
// Name: Cuiting Huang
// CS5008 20018 Data Str, Algo & App in CmpSys SEC 03 Fall 2021 [VAN-2-HY]
// LeetCode link: https://leetcode.com/problems/candy/
// [Greedy][Array]
//
// 135.Candy [hard]
// There are n children standing in a line. Each child is assigned a rating value
// given in the integer array ratings.
//
// You are giving candies to these children subjected to the following requirements:
//
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.
// n == ratings.length, 1 <= n <= 2 * 104 ratings is not empty.

// Greedy Algorithm
// Return the minimum number of candies you need to have to
// Distribute the candies to the children, according to the requirements.
int candy(int *ratings, int ratingsSize) {
    int total = 0;
    int candy[ratingsSize];

    for (int i = 0; i < ratingsSize; i++) {
        candy[i] = 1;
    }

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    for (int i = ratingsSize - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i] && candy[i - 1] <= candy[i]) {
            candy[i - 1] = candy[i] + 1;
        }
    }

    for (int i = 0; i < ratingsSize; i++) {
        total = candy[i] + total;
    }
    return total;
}
