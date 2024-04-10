class Solution {
public:
    string reverseWords(string s) {
       istringstream iss(s);

    // Create a vector to store individual words
    vector<string> words;

    // Extract words from the input string and store in the vector
    copy(istream_iterator<string>(iss),
              istream_iterator<string>(),
              back_inserter(words));

    // Reverse the order of words in the vector
    reverse(words.begin(), words.end());

    // Join the words back into a single string
    ostringstream oss;
    copy(words.begin(), words.end(), ostream_iterator<string>(oss, " "));
    
    // Get the joined string
    string reversed = oss.str();

    // Remove the trailing space
    if (!reversed.empty()) {
        reversed.pop_back();
    }

    return reversed;
    }
};
