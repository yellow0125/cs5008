// Created by Yellow on 2021/11/26.
// Name: Cuiting Huang
// CS5008 20018 Data Str, Algo & App in CmpSys SEC 03 Fall 2021 [VAN-2-HY]
// LeetCode link: https://leetcode.com/problems/median-of-two-sorted-arrays/
//  [Array]
//
// 4.Median of Two Sorted Arrays[hard]
// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

double findMedianSortedArrays(int *nums1, int m, int *nums2, int n) {
    int total = m + n;
    int middle;
    if (total %2==1){
      middle = (total+1)2;
      return findKth();
    }
    else{
      middle = (total/2+(total/2+1))/2;
      return findKth();
    }
  }

  double findKth(int *nums1,int *nums2){


  }

// Since two array are sorted
// we can have the following cases
//if m =0; we need to find the median of nums2
//if n =0 we just need to find the median of nums1
// if all elements in nums2 bigger than each element of num1 and m=n
// the median's position is the average of (m+m+1)/2
// kth smallest  k = middle

    if (total % 2 == 1) {
        return findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, (total + 1) / 2);
    } else {
        return (findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, total / 2)
                + findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, total / 2 + 1)) / 2;
    }
}





// =============== Helper Functions ==================
// Return the minimum between two integers.
int min(int a, int b) {
    if (a < b)return a;
    return b;
}

// Find the kth number which is the smaller number in both array nums1 and nums2
// Always assume that num1size is always equal or smaller than nums2size.
// In this case, kth is the median.
double findKth(int *nums1, int start1, int end1, int *nums2, int start2, int end2, int k) {
    int size1 = end1 - start1 + 1;
    int size2 = end2 - start2 + 1;
    if (size1 > size2)
        return findKth(nums2, start2, end2, nums1, start1, end1, k);
    if (size1 == 0)
        return nums2[start2 + k - 1];
    if (k == 1)
        return min(nums1[start1], nums2[start2]);

    int m = start1 + min(size1, k / 2);
    int n = start2 + min(size2, k / 2);

    if (nums1[m] < nums2[n])
        return findKth(nums1, m, end1, nums2, start2, end2, k - (m - start1));
    else return findKth(nums1, start1, end1, nums2, n, end2, k - (n - start2));

}

// =============== Find Median Function===============
// Find the median number of two given array, and their size.
// If the total size is odd, the median is the kth number, k=(total+1)/2
// If the total size if even, the median is the average of kth and k+1, k=total/2
// Constraints: 1 <= m + n <= 2000  the array will not be empty both.
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if (total % 2 == 1) {
        return findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, (total + 1) / 2);
    } else {
        return (findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, total / 2)
                + findKth(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, total / 2 + 1)) / 2;
    }
}
