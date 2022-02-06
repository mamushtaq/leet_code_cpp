#include <iostream>
#include<vector>
using namespace std;

//Given two sorted arrays nums1and nums2 of size mand n respectively, return the median of the two sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>complete_arr = nums1, sorted;
        int smallest = 0, min;
        //Adding nums2 to complete_arr
        for (int i = 0; i < nums2.size(); i++) {
            complete_arr.push_back(nums2[i]);
        }
        for (int i = 0; i < complete_arr.size(); i++) {
            min = i;
            for (int j = i + 1; j < complete_arr.size(); j++)
                if (complete_arr[j] < complete_arr[min])
                    min = j;
            smallest = complete_arr[i];
            complete_arr[i] = complete_arr[min];
            complete_arr[min] = smallest;
        }
        int medium;
        double median;
        medium = complete_arr.size() % 2;
        int position = complete_arr.size() / 2;
        if (medium == 0) {
            median = (complete_arr[position] + complete_arr[position-1]);
            median = median / 2;
            
        }
        else {
            median = complete_arr[position];
        }
        return median;
    }
};

int main() {
    Solution* ptr = new Solution;
    vector<int> arr1, arr2;
    arr1.push_back(1);
    arr1.push_back(3);
    arr2.push_back(2);
    arr2.push_back(4);
    cout << ptr -> findMedianSortedArrays(arr1, arr2);
    return 0;
}