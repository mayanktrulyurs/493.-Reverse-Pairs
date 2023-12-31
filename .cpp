/*
Time Complexity: O(2N*logN), where N = size of the given array.
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.

*/
class Solution {
public:
   
    void merge(int low, int mid, int high, vector<int>& nums){

        int start=low, end=mid+1;
        vector<int>temp;

        while (start<=mid && end<=high){
            if (nums[start]<=nums[end]){
                temp.push_back(nums[start]);
                start++;
            }
            else{
                temp.push_back(nums[end]);
                end++;
            }
        }
        while (start<=mid){
            temp.push_back(nums[start]);
            start++;
        }
        while (end<=high){
            temp.push_back(nums[end]);
            end++;
        }

        for (int idx=low;idx<=high;idx++){
            nums[idx]=temp[idx-low];
        }
    }
    int findReversePairs (int low, int mid, int high, vector<int>& nums){

        int cnt=0;
        int j=mid+1;
        for (int i=low;i<=mid;i++){
            while (j<=high && nums[i]> (long long)2*nums[j]){
                j++;
            }
            cnt+=(j-(mid+1));
        }
        return cnt;
       
    }
    int mergeSort(int low, int high, vector<int>& nums){

        int cnt=0;
        if (low>=high){
            return cnt;
        }
        int mid=(low+high)/2;

        cnt+=mergeSort(low,mid,nums);
        cnt+=mergeSort(mid+1,high,nums);

        cnt+=findReversePairs(low,mid,high,nums);
        merge(low,mid,high,nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
        
    }
};
/*
using global variable cnt=0

class Solution {
public:
    int cnt=0;
    void merge(int low, int mid, int high, vector<int>& nums){

        int start=low, end=mid+1;
        vector<int>temp;

        while (start<=mid && end<=high){
            if (nums[start]<=nums[end]){
                temp.push_back(nums[start]);
                start++;
            }
            else{
                temp.push_back(nums[end]);
                end++;
            }
        }
        while (start<=mid){
            temp.push_back(nums[start]);
            start++;
        }
        while (end<=high){
            temp.push_back(nums[end]);
            end++;
        }

        for (int idx=low;idx<=high;idx++){
            nums[idx]=temp[idx-low];
        }
    }
    void findReversePairs (int low, int mid, int high, vector<int>& nums){

        int j=mid+1;
        for (int i=low;i<=mid;i++){
            while (j<=high && nums[i]>2*nums[j]){
                j++;
            }
            cnt+=(j-(mid+1));
        }
       
    }
    void mergeSort(int low, int high, vector<int>& nums){

        if (low>=high){
            return;
        }
        int mid=(low+high)/2;

        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);

        findReversePairs(low,mid,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return cnt;
    }
};

*/
