class Solution {
public:

    void  heapify(vector<int>& nums , int n , int i){
        int largest = i; 

        while(n>=0){
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && nums[left] > nums[largest]){

            largest = left;
        }
         if(right < n && nums[right] > nums[largest]){

            largest = right;
        }

        if(largest != i){
            swap(nums[largest] , nums[i]);
             i = largest;
        }else{

            break;
        }

        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
          // Build heap (rearrange array)
        for (int i = size/ 2 - 1; i >= 0; i--) {
            heapify(nums, size, i);
        }

        while(size - 1> 0){

            swap(nums[0], nums[size-1]);
            size--;

            heapify(nums, size , 0 );
        }

        return nums;
    }
};