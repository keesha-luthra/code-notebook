class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector <int> answer;
    //     unordered_map <int, int> mpp;
    //     stack <int> st;
    //     for(int i = nums2.size() - 1; i >= 0; i--){
    //         while(!st.empty() && st.top() <= nums2[i])
    //             st.pop();
    //         if(st.empty()) mpp[nums2[i]] = -1;
                
    //         else mpp[nums2[i]] = st.top();

    //         st.push(nums2[i]);
    //     }

    //     for(int i = 0; i < nums1.size(); i++){
    //         answer.push_back(mpp[nums1[i]]);
    //     }

    //     return answer;
    vector<int> answer;
    stack<int> st;
    int n = nums2.size();
    unordered_map<int, int> mpp;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
        if(st.empty()) mpp[nums2[i]] = -1;
        else{
        mpp[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    for(int i = 0; i < nums1.size(); i++){
        answer.push_back(mpp[nums1[i]]);
    }
    return answer;
    }
};