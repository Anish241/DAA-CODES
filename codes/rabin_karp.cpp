#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<char,int>> hash_table = {{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8},{'i',9},{'j',10},{'k',11},{'l',12},{'m',13},{'n',14},{'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},{'u',21},{'v',22},{'w',23},{'x',24},{'y',25},{'z',26}};
int getHash(vector<char> pattern)
{
    int hash_value = 0;
    int n = pattern.size();
    for(int i=0;i<n;i++)
    {
       int hash_code = (hash_table[pattern[i]-'a'].second)%11;
       
         hash_value += hash_code*pow((double)10,(double)(n-i-1));
        
    
    }
    return hash_value+1;
}

vector<int> rabin_karp(vector<char> text,vector<char> pattern)
{
    int n = text.size();
    int m = pattern.size();
    int hash_value = getHash(pattern);
    vector<int> result;
    int curr_hash = getHash(vector<char>(text.begin(),text.begin()+m));
    if(curr_hash==hash_value)
    {
        result.push_back(0);
    }
    for(int i=1;i<=n-m;i++)
    {
        curr_hash = (curr_hash-(hash_table[text[i-1]-'a'].second)%11)/10;
        curr_hash += (hash_table[text[i+m-1]-'a'].second)%11*pow((double)10,(double)(m-1));
        if(curr_hash==hash_value)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    
    vector<char> text = {'a','b','c','d','e','f','g','h','a','b','c','l','m','n'};
    vector<char> pattern = {'a','b','c'};
    vector<int> result = rabin_karp(text,pattern);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;

}
