class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ts=0;
        for(int x:nums){
        int c=0;
        int s=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int d1=i;
                int d2=x/i;
                c++;
                s+=d1;
                if(d1!=d2){
                    c++;
                    s+=d2;
                }
                if(c>4)
                break;
            }
        }
        if(c==4){
            ts+=s;
        }
        }
        return ts;
    }
};
