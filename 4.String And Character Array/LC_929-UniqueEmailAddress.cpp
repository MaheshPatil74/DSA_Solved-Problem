class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;   
        for(string email : emails) {
            string local = "";
            string domain = "";
                                                                    
            int i = 0;                                                               
            // local part process
            while(email[i] != '@') {
                if(email[i] == '+')
                    break;
                if(email[i] != '.')
                    local += email[i];
                i++;
            }

            // skip till '@
            while(email[i] != '@')
                i++;
                                                 
            // domain part
            domain = email.substr(i) ;
        `                                                
            st.insert(local + domain);
        }
        return st.size();
    }
};