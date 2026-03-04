// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int right = num.size() - 1;
        int carry = 0;
        while (right >= 0 || k > 0 || carry > 0) {
            int digit = k % 10;
            if (right >= 0) 
                digit += num[right];
            
            int sum = digit + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            if (right >= 0)
                num[right] = value;
            else
                num.insert(num.begin(), value);
            
            k /= 10;
            right--;
        }
        
        return num;
    }
};