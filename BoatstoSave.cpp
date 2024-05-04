class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0; int j = people.size()-1;
        int ans = 0;
        while(i<j) {
            while(i<j && people[i]+people[j]>limit) j--;
            if(i<j && people[i]+people[j]<=limit) {
                people[i] = 0; people[j] = 0;
                ans++; i++; j--;
            }
            else i++;
        }
        for(int x: people) if(x) ans++;
        return ans;
    }
};
