class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0;
        int write = 0;

        while (read < n) {
            char current_char = chars[read];
            int count = 0;

            while (read < n && chars[read] == current_char) {
                read++;
                count++;
            }

            chars[write] = current_char;
            write++;

            if (count > 1) {
                string cnt = to_string(count);
                for (auto ch : cnt) {
                    chars[write] = ch;
                    write++;
                }
            }
        }
        return write;
    }
};