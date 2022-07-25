class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1, count = 0;
        while(low < high){
            if(people[low] + people[high] <= limit){
                count++;
                low++;
                high--;
            }
            else{
                count++;
                high--;
            }
        }
        if(low == high) count++;
        return count;
    }
};