#include <cmath> //for min and sqrt function
#define M 100000 //number upto which function will run
int smallestPrime[M];
void findSmallestPrimeFactor(){
    for(int i=1; i<M; i++)
    {
        smallestPrime[i]=i;
    }
    for(int i=2; i<M; i+=2)
    {
        //setting 2 for all even numbers to improve time
        smallestPrime[i]=2;
    }
    for(int i=3; i<sqrt(M); i+=2)
    {
        if(smallestPrime[i]==i)
        {
            for(int j=i*i; j<M; j+=i)
            {
                //it maybe possible that some earlier number is prime factor of j
                //so we need to check it must be minimum
                smallestPrime[j]=min(smallestPrime[j], i);
            }
        }
    }
}
