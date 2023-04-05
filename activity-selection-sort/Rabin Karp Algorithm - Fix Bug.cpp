/*
Given a text T and a pattern P, implement rabin karp algorithm to print all occurrences of P in T. Assume that only digits will be given as input. For example, if T is "235902314152673992" and P is "31415" then print 6 (programming index).

Note: The code given has a bug fix it

Input Format

First line contains the text, T

Next line contains the pattern, P

Output Format

Print all indices of occurrence of P in T

Print one index in one line
*/

#include<iostream>
using namespace std;
#include<string>
#include<math.h>

Your code has Passed Execution!
int valueOf(char ch)
{
    return (ch-'0');
}

bool check_characters(string T, string P, int s)
{
    int n = T.length();
    int m = P.length();
    for(int i=0; i<m; i++)
    {
        if(P[i] != T[s+i])
            return false;
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n = T.length();
    int m = P.length();
    int h = 1;
    int p = 0;
    int t0 = 0;

    for(int i=0; i<m-1; i++)
    {
        h = (h * d) % q;
    }
    for(int i=0; i<m; i++)
    {
        p = (d*p + valueOf(P[i])) % q;
        t0 = (d*t0 + valueOf(T[i])) % q;
    }
    for(int s=0; s<=n-m; s++)
    {
        if(p == t0)
        {
            if(check_characters(T, P, s))
            {
                cout << s << endl;
            }
        }
        if(s < n-m)
        {
            // Update the hash value of T
            t0 = (d*(t0-valueOf(T[s])*h) + valueOf(T[s+m])) % q;
            if(t0 < 0)
            {
                t0 += q;
            }
        }
    }
}

int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}
