

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;

        // Build the word count map
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> window_count;
            int left = i;
            int right = i;
            int count = 0;

            while (right + word_len <= s.size()) {
                string word = s.substr(right, word_len);
                right += word_len;

                if (word_count.find(word) != word_count.end()) {
                    window_count[word]++;
                    count++;

                    while (window_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        count--;
                        left += word_len;
                    }

                    if (count == num_words) {
                        result.push_back(left);
                    }
                } else {
                    window_count.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
