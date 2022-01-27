//runtime: 58ms
//memory: 90.2mb

class Solution {
public:
    void mergeArrays(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) { //merge sort
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int i = 0, j = 0, k = 0;
        
        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) {
                //cout << "adding value from 1" << endl;
                nums3.push_back(nums1[i++]);

               // cout <<" done" << endl;
            }
            else {
              //  cout << "adding value from 2" << endl;
               nums3.push_back(nums2[j++]);
              //  cout << "done " << endl;
            }
        }
        
        while (i < n1){
             nums3.push_back(nums1[i++]);
        }
        while(j < n2) {
              nums3.push_back(nums2[j++]);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        mergeArrays(nums1, nums2, nums3);
        int n3 = nums3.size();
        int mid = 0;
        double median = 0;
        
        if(n3 % 2 == 0) { //even size
            mid = (n3 / 2) - 1;
            median = (nums3[mid] + nums3[mid+1]) / 2.0;
        }
        else { //odd size
            mid = (n3 / 2);
            median = nums3[mid];
        }
        
        // for(unsigned i = 0; i < n3; i++) {
        //     cout << nums3.at(i) << " " ;
        // }
        
        return median;
    }  
};