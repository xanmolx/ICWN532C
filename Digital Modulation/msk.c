#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
    double d[1000];
    double n;
    int length=0;;
    while(scanf("%lf",&n))
    {
        if(n==-1)
        {
            break;
        }
        d[length++]=n;
    }
    int j=0;
    double t=0;
    FILE *fp=fopen("msk.txt","w");
    FILE *fp1=fopen("inp.txt","w");
    int flag=0;
    for(j=0;j<length;j++)
    {
        int k=0;
        if(d[j]==0)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
        for(;k<50;k++)
        {
            if(flag==0)
            {
                fprintf(fp,"%lf %lf\n",t,sin(2*PI*0.08*t));
                fprintf(fp1,"%lf %lf\n",t,d[j]);
                t++;
            }
            else
            {
                fprintf(fp,"%lf %lf\n",t,sin(2*PI*0.02*t+PI));
                fprintf(fp1,"%lf %lf\n",t,d[j]);
                t++;
            }
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
