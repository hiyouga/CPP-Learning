#include<cstdio>

#include<cmath>

main()

{

    long long n;

    for(long long j = 1; j < 100; j++)
    {
n = j;
        if(n%2==0)

            {

                while((n/2)%2==0)

                {

                    n=n/2;

                }

            }

        int I=3;

        while(I<=sqrt(n))

        {

            if(n%I==0)

            {

                while((n/I)%I==0)

                {

                    n=n/I;

                }

            }

            I+=2;

        }

        printf("%lld\n",n);

    }

}
