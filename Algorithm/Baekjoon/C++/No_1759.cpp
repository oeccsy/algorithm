#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char alphabets[15];
char selected[15];
bool is_used[15];

bool IsVowel(char a)
{
    if(a == 'a' || a=='e' || a=='i' || a=='o' || a=='u') return true;
    return false;
}

void Select(int index)
{
    if(index == l)
    {
        int consonant_count = 0;
        int vowel_count = 0;
        
        for(int i=0; i<l; i++)
        {
            if(IsVowel(selected[i]))
                vowel_count++;
            else
                consonant_count++;
        }
        
        if(vowel_count >= 1 && consonant_count >= 2)
        {
            for(int i=0; i<l; i++)
            {
                cout << selected[i];
            }
            cout << '\n';
        }
        
        return;
    }
    
    for(int i=0; i<c; i++)
    {
        if(is_used[i]) continue;
        if(index > 0 && selected[index-1] > alphabets[i]) continue;
        
        selected[index] = alphabets[i];

        is_used[i] = true;
        
        Select(index+1);

        is_used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;

    for(int i = 0; i<c; i++)
    {
        char input;
        cin >> input;
        alphabets[i] = input;
    }

    sort(alphabets, alphabets+c);

    Select(0);
}