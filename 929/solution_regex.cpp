// regex
// Reference
// 1. https://stackoverflow.com/questions/16749069/c-split-string-by-regex/16752826
// 2. https://www.cplusplus.com/reference/regex/regex_replace/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::regex emailDilim("@");
        std::regex dotDilim("\\.");
        std::regex local_nameDilim("\\+");
        unordered_set<string> real_emails;

        for(string email : emails) {
            std::sregex_token_iterator iter(email.begin(),
                                            email.end(),
                                            emailDilim,
                                            -1);

            // get local name
            string local_name = *iter;
            local_name = std::regex_replace(local_name, dotDilim, "");
            // get domain name
            ++iter;
            string domain_name = *iter;

            // get real local name i.e., without dot and plut notation
            std::sregex_token_iterator real_local_name_iter(local_name.begin(),
                                                            local_name.end(),
                                                            local_nameDilim,
                                                            -1);
            string real_local_name = *real_local_name_iter;

            // push real email address to container
            cout << real_local_name << " " << domain_name << endl;
            real_emails.insert(real_local_name + "@" + domain_name);
            }

        return real_emails.size();
    }
};
