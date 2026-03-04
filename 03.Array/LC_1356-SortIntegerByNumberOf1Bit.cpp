
// Approach 1 L Brute Force
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> temp;

        for(int i = 0; i < arr.size(); i++){
            int num = arr[i];
            int count = 0;

            while(num != 0){
                if(num & 1)
                    count++;
                num = num >> 1;
            }

            temp.push_back({count, arr[i]});
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i < arr.size(); i++){
            arr[i] = temp[i].second;
        }

        return arr;
    }
};