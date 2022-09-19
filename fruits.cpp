
class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i,j = 0;
        int ans = INT_MIN;
        unordered_map<int,int>mp; // map to check the uniqueness of fruits
        while(j<n){
        	mp[nums[j]]++;

        	if(mp.size() < 2){
        		int cnt = 0;

        		for(auto it : mp){
        			cnt += it.second;
        		}
        		ans = max(cnt,ans);
        	}
        	if(mp.size() > 2){
        		while(mp.size() > k){
        			mp[nums[i]]--;
        			i++;
        		}
        		j++;
        	}
        }
        return ans;
    }
};