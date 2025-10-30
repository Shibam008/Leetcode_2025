class Solution {
public:
// two pointer
    int twoPointerApproach(string haystack, string needle) 
    {
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i <= n-m; i++) 
        {
            int first = i, second = 0;
            while(second < m) 
            {
                if(haystack[first] != needle[second]) 
                {
                    break;
                }
                else
                {
                    first++; second++;
                }
            } 
            if(second == m)
            {
                return first - second;
            }
        }
        return -1;
    }

// KMP approach

    void lpsFind(vector<int>&lps, string s) 
    {
        int pre = 0, suf = 1;
        while(suf < s.size()) 
        {
            if(s[pre] == s[suf])
            {
                lps[suf] = pre + 1;
                pre++; suf++;
            }
            else
            {
                if(pre == 0) 
                {
                    lps[suf] = 0;
                    suf++;
                }
                else 
                {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        //return twoPointerApproach(haystack, needle);

        vector<int> lps(needle.size(), 0);
        lpsFind(lps, needle);
        int first = 0, second = 0;

        while(first < haystack.size() && second < needle.size())
        {
            if(haystack[first] == needle[second])
            {
                first++; second++;
            }
            else
            {
                if(second == 0) 
                    first++;
                else
                    second = lps[second-1];
            }
        }

        if(second == needle.size())
        {
            return first - second;
        }
        return -1;
    }
};