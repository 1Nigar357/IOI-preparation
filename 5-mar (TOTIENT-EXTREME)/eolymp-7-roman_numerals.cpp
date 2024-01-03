#include <bits/stdc++.h>
using namespace std;
char c;
string s1, s2, r,ans;
int f, a[5], k;
int roman(char r)
{
    if( r == 'M' )
        return 1000;
    if( r == 'D' )
        return 500;
    if( r == 'C' )
        return 100;
    if( r == 'L' )
        return 50;
    if( r == 'X' )
        return 10;
    if( r == 'V' )
        return 5;
    return 1;
}
int roman_to_arabic(string s)
{
    int a[10];
    int arabic = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        a[i] = roman(s[i]);
    }
    for( int i = 0; i < s.length() - 1; i++ )
    {
        if( a[i] < a[i+1] )
            a[i] = -a[i];
        arabic += a[i];
    }
    arabic += a[s.length()-1];
    return arabic;
}
string arabic_to_roman(int n)
{
    while( n > 0 )
    {
        k++;
        a[k] = n % 10;
        n = n / 10;
    }
    if( k == 4 )
    {
        for( int i = 1; i <= a[k]; i++ )
            ans += "M";
        k--;
    }
    if( k == 3 )
    {
        if( a[k] < 4 )
        {
            for(int i = 1; i <= a[k]; i++ )
                ans += "C";
        }
        else if( a[k] == 4 )
            ans += "CD";
        else if( a[k] <= 8 )
        {
            ans += "D";
            for( int i = 6; i <= a[k]; i++ )
                ans += "C";
        }
        else
            ans += "CM";
        k--;
    }
    if( k == 2 )
    {
        if( a[k] < 4 )
        {
            for(int i = 1; i <= a[k]; i++ )
                ans += "X";
        }
        else if( a[k] == 4 )
            ans += "XL";
        else if( a[k] <= 8 )
        {
            ans += "L";
            for( int i = 6; i <= a[k]; i++ )
                ans += "X";
        }
        else
            ans += "XC";
        k--;
    }
    if( k == 1 )
    {
        if( a[k] < 4 )
        {
            for(int i = 1; i <= a[k]; i++ )
                ans += "I";
        }
        else if( a[k] == 4 )
            ans += "IV";
        else if( a[k] <= 8 )
        {
            ans += "V";
            for( int i = 6; i <= a[k]; i++ )
                ans += "I";
        }
        else
            ans += "IX";
        k--;
    }
    return ans;
}
int main()
{
    while(cin>>c)
    {
        if( c == '+' )
            f = 1;
        if( f != 1 )
        {
            s1 += c;
        }
        if( c != '+' && f == 1 )
            s2 += c;

    }
    cout<<arabic_to_roman((roman_to_arabic(s1)+roman_to_arabic(s2)))<<endl;
}
