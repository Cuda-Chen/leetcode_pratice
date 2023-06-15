// https://walkccc.me/LeetCode/problems/0271/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;

        for(auto s : strs)
            encoded += to_string(s.size()) + '/' + s;

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;

        for(int i = 0; i < s.size();) {
            int slash = s.find('/', i);
            int len = stoi(s.substr(i, slash - i));
            i = slash + len + 1;
            decoded.push_back(s.substr(slash + 1, i - slash - 1));
        }

        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
