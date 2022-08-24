class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int N = arr.size();
        if(arr[N - 1] != 9){
            arr[N - 1] += 1;
            return arr;
        }
        int i = N - 1;
        while(i >= 0){
            if(arr[i] == 9){
                if(i != 0){
                    arr[i] = 0;
                    i--;
                }
                else{
                    arr[i] = 0;
                    arr.push_back(1);
                    reverse(arr.begin(), arr.end());
                    break;
                }
            }
            else{
                arr[i] += 1;
                break;
            }
        }
        return arr;
    }
};