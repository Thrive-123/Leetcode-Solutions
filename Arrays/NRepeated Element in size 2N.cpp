Class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
      /*BruteForce approach*/
        int n=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            int c=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    c++;
                }
            }
            if(c==n){
                return nums[i];
            }
        }
        return -1;
    }
};
      /*optimal approach*/
        unordered_set<int>s;
        for(int x:nums){
            if(s.count(x)){
             return x;
            }
            s.insert(x);
        }
        return -1;
        
    }
};
