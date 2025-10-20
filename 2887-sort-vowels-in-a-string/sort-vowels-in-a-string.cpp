class Solution {
public:
    string sortVowels(string s) {
        // store which vowel is present how many times.
        vector<int> smallVowels(26,0);
        vector<int> capitalVowels(26, 0);

        // step 1;
        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') 
            {
                smallVowels[s[i] - 'a']++;
                s[i] = '#';
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                capitalVowels[s[i] - 'A']++;
                s[i] = '#';
            }
        }

        // step 2
        string sortedVowels;

        for(int i = 0; i < 26; i++) 
        {
            char ch = 'A' + i;
            while(capitalVowels[i]) 
            {
                sortedVowels += ch;
                capitalVowels[i]--;
            }
        }
        for(int i = 0; i < 26; i++) 
        {
            char ch = 'a' + i;
            while(smallVowels[i]) 
            {
                sortedVowels += ch;
                smallVowels[i]--;
            }
        }

        // step 3
        int first = 0, second = 0;
        while(second < sortedVowels.size()) 
        {
            if(s[first] == '#') 
            {
                s[first] = sortedVowels[second];
                second++;
            }
            first++;
        }
        return s;
    }
};