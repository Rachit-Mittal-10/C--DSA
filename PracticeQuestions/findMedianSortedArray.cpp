#include<iostream>
#include<vector>
using namespace std;

class Solution {
vector<int> Merge(vector<int>& nums1, vector<int>& nums2){
    int i1 = 0;
    int i2 = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int> sorted_array;
    while(i1<size1 && i2<size2){
        if(nums1[i1]<=nums2[i2]){
            sorted_array.push_back(nums1[i1]);
            i1++;
        }else{
            sorted_array.push_back(nums2[i2]);
            i2++;
        }
    }
    while(i1<size1){
        sorted_array.push_back(nums1[i1]);
        i1++;
    }
    while(i2<size2){
        sorted_array.push_back(nums2[i2]);
        i2++;
    }
    return sorted_array;
}

double Median(vector<int> array){
    int size = array.size();
    double median;
    if(size&1){
        // Odd Size
        int median_index = size/2;
        median =  (double)array[median_index];
    }else{
        // even size
        int median_index_2 = size/2;
        int median_index_1 = median_index_2 - 1;
        median = (double)array[median_index_2] + ((double)(array[median_index_1] - array[median_index_2]))/2;
    }
    return median;
}
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sort = Merge(nums1,nums2);
        double median = Median(sort);
        return median;
    }
};

int main(void){
    vector<int> nums1, nums2;

    nums1.push_back(1);
    nums1.push_back(3);
    nums2.push_back(2);

    Solution S;
    cout << S.findMedianSortedArrays(nums1,nums2);
}