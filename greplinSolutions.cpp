// http://challenge.greplin.com/

/*
   Level 1
	
	----------------------------------------

	Embedded in this block of text is the password for level 2.
	The password is the longest substring that is the same in reverse.
	
	As an example, if the input was "I like racecars that go fast"
	the password would be "racecar".
	
	Enter the password to access level 2: 
*/
#include<iostream>
using namespace std;
class LongestPalindromicSubstring {
private:
    string s;
public:
    LongestPalindromicSubstring()
    {
         s="FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    }
    string longestPalindrome() {
        int N=s.size();
        if(N==0)return "";
        if(N==1)return s;
        int i,j,l,r,start=0,len,x=1;
        for(i=0;i<N;i++)
        {
            for(j=0;j<2;j++)
            {
                l=i-j;
                r=i+1;
                while(l>=0 && r<N && s[l]==s[r]){l--;r++;}
                l++;r--;
                len=r-l+1;
                if(len>x){x=len;start=l;}
            }
        }
        return s.substr(start,x);
    }
};
int main()
{
   LongestPalindromicSubstring lps;
   cout<<"Longest Palindromic Substring = "<<lps.longestPalindrome();
   cout<<endl;
   return 0;
}

/*
   Level 2
	
	----------------------------------------

	Congratulations.  You have reached level 2.
	
	To get the password for level 3, write code to find the first prime
	fibonacci number larger than a given minimum.  For example, the first
	prime fibonacci number larger than 10 is 13.

	When you are ready, go here or call this automated
	number (415) 799-9454.
	
	You will receive additional instructions at that time.  For the second portion
	of this task, note that for the number 12 we consider the sum of the prime divisors
	to be 2 + 3 = 5.  We do not include 2 twice even though it divides 12 twice.
	
	Enter the password to access level 3: 
*/
#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int n)
{
   for(int i=2;i<=pow(n,0.5);i++)
   {
      if(n%i==0)return 1;
   }
   return 0;
}
int main(void )
{
   int a=0, b=1, c=a+b, n=227000;
   int i,sum=0;
   while(c<n)
   {
      c=a+b;
      a=b;
      b=c;
   }
   while(isPrime(c))
   {
      c=a+b;
      a=b;
      b=c;
   }
   cout<<"Prime fibonacci = "<<c<<endl;
   for(i=2;i<=pow(c+1,0.5);i++)
   {
      if(isPrime(i)==0 && (c+1)%i==0)
      {
         sum+=i;
      }
   }
   cout<<"Sum of prime divisors = "<<sum;
   cout<<endl;
   return 0;
}

/*
   Level 3
	
	----------------------------------------

	Congratulations.  You have reached the final level.
	
	For the final task, you must find all subsets of an array
	where the largest number is the sum of the remaining numbers.
	For example, for an input of:

	(1, 2, 3, 4, 6)

	the subsets would be

	1 + 2 = 3
	1 + 3 = 4
	2 + 4 = 6
	1 + 2 + 3 = 6
	
	Here is the list of numbers you should run your code on.
	The password is the number of subsets.  In the above case the
	answer would be 4.
	
	Enter the password to complete the challenge: 
*/
#include<iostream>
#include<vector>
using namespace std;
void help(vector<int> &v, vector<vector<int> > &r, vector<int> x, int sum, int level)
{
   if(level==v.size())return;
   if(x.size()>=2)
   {
      if(find(v.begin(),v.end(),sum)!=v.end() && find(r.begin(),r.end(),x)==r.end())
      {
         r.push_back(x);
      }
   }
   help(v,r,x,sum,level+1);
   x.push_back(v[level]);
   help(v,r,x,sum+v[level],level+1);
   x.pop_back();
}
int main(void )
{
   int a[]={3, 4, 9, 14, 15, 19, 28, 37, 47, 50, 54, 56, 59, 61, 70, 73, 78, 81, 92, 95, 97, 99};
   int i, n=sizeof(a)/sizeof(int);
   vector<int> v,x;
   vector<vector<int> > r;
   for(i=0;i<n;i++)v.push_back(a[i]);
   help(v,r,x,0,0);
   cout<<"Total number of sets = "<<r.size();
   cout<<endl;
   return 0;
}
