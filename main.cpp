#include <iostream>
#include <map>

bool isAnagram(std::string word, std::string anagram)
{
    std::map<char, int> chars;

    for(int i=0;i<word.length();i++)
    {
        if(chars.find(word[i])!=chars.end())
            chars[word[i]]++;
        else
            chars[word[i]]=1;
    }

    std::map<char,int>::iterator it;

    for(int i=0;i<anagram.length();i++)
    {
        it=chars.find(anagram[i]);

        if(it!=chars.end())
        {
            if(it->second==1)
                chars.erase(it);
            else
                it->second--;
        }
        else
            return false;
    }

    if(chars.empty())
        return true;
    else
        return false;
}

int main()
{
    std::cout << "Type word: ";
    std::string word;
    std::cin >> word;

    std::cout << "Type its anagram: ";
    std::string anagram;
    std::cin >> anagram;

    std::cout << isAnagram(word, anagram);
    return 0;
}
