class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> help;
        int total = nums1.size() + nums2.size();
        //cout << "Total # of elements: " << total << "." << endl;
        int count = 0;
        double result = 0;
        double pre = 0;
        while (count != total) {
            double cur;
            count++;
            if (!nums1.empty() && (nums2.empty() || nums1[0] <= nums2[0])) {
                cur = nums1[0];
                if (count == (total/2 + 1)) {
                    //cout << pre << endl;
                    //cout << cur << endl;
                    if (total % 2 != 0) {
                        result = cur;
                        break;
                    }
                    else {
                        result = (cur + pre)/2;
                        break;
                    }
                }
                help.push_back(nums1[0]);
                //cout << nums1[0] << " nums1 pushed." << endl;
                nums1.erase(nums1.begin());
            }
            else if (!nums2.empty() && (nums1.empty() || nums1[0] > nums2[0])) {
                cur = nums2[0];
                if (count == (total/2 + 1)) {
                    //cout << pre << endl;
                    //cout << cur << endl;
                    if (total % 2 != 0) {
                        result = cur;
                        break;
                    }
                    else {
                        result = (cur + pre)/2;
                        break;
                    }
                }
                help.push_back(nums2[0]);
                //cout << nums2[0] << " nums2 pushed." << endl;
                nums2.erase(nums2.begin());
            }
            pre = cur;
        }
        return result;
    }
};
