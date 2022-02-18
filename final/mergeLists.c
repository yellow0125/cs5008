// Created by Yellow on 2021/11/27.
// Name: Cuiting Huang
// CS5008 20018 Data Str, Algo & App in CmpSys SEC 03 Fall 2021 [VAN-2-HY]
// LeetCode link: https://leetcode.com/problems/merge-k-sorted-lists/
//  [Heap (Priority Queue)][Merge sort][Linked lists]
//
// 23.Merge k Sorted Lists[hard]
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

#include <stdio.h>
#include <malloc.h>

// =============== Definition for singly-linked list. ===============
// This definition is not allowed in the leetCode webpage.
// But in .c it is needed.

/**
struct ListNode {
   int val;
   struct ListNode *next;
};
*/

// =============== Helper Functions ===============
//merge two lists
//If the given lists both NULL, return NULL.
//If list is null return other, on the contrary return list.
//If fail to allocate memory for the new node return NULL.
//Find the new head first, then merge two lists.
//Return new list.
struct ListNode *mergeTwoLists(struct ListNode *list, struct ListNode *other) {
    if (list == NULL && other == NULL)return NULL;
    if (list == NULL)return other;
    if (other == NULL)return list;

    struct ListNode *newHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (newHead == NULL)return NULL;
    if (list->val > other->val) {
        newHead = other;
        other = other->next;
    } else {
        newHead = list;
        list = list->next;
    }

    struct ListNode *temp = newHead;
    while (list != NULL & other != NULL) {
        if (list->val > other->val) {
            temp->next = other;
            other = other->next;
        } else {
            temp->next = list;
            list = list->next;
        }
        temp = temp->next;
    }
    while (list != NULL) {
        temp->next = list;
        list = list->next;
        temp = temp->next;
    }
    while (other != NULL) {
        temp->next = other;
        other = other->next;
        temp = temp->next;
    }
    //free(temp);
    return newHead;
}

// Merge lists array. from start position to the end
// If the lists is NULL, return NULL
// Use recursion
// If the start == end return list, then use helper function merge two lists.
struct ListNode *mergeLists(struct ListNode **lists, int start, int end) {
    if (lists == NULL) return NULL;
    if (start == end)return lists[start];

    int middle = (start + end) / 2;
    struct ListNode *list = mergeLists(lists, start, middle);
    struct ListNode *other = mergeLists(lists, middle + 1, end);

    return mergeTwoLists(list, other);

}

// =============== Merge K Lists ===============
// Return NULL, if lists or listsSize is NULL
// Return a merge lists sorted in ascending order.
struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (lists == NULL || listsSize == 0)return NULL;
    return mergeLists(lists, 0, listsSize - 1);

}
