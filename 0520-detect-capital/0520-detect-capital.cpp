class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0;
        for(int i=0;i<word.size();i++)
        {
           if (word[i] >= 'A' && word[i] <= 'Z')
            {
                c++;
            }
        }
        return c==word.length() || c==0 || (c == 1 && word[0] >= 'A' && word[0] <= 'Z');
    }
};