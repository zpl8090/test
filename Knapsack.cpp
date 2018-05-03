#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;
int w[MAX],v[MAX];
float s[MAX],f[MAX];
void Knapsack(int n,int p)
{
	int n1,p1;
	if(n == 0 || p == 0)
	{
		printf("无效数据请重新输入!\n");
		printf("请输入物品个数和背包载重:");
        scanf("%d%d",&n1,&p1);
        Knapsack(n1,p1);
	}
    else
    {
    	for(int i = 1; i <= n; ++i)
    	{
    		printf("请输入第%d件物品的重量和价值:",i);
    		scanf("%d%d",&w[i],&v[i]);
    		s[i]=v[i]*1.0/w[i];
		}
        for(int i = 1; i <= n; ++i)
        {
            for(int j = p; j >= w[i]; --j)
            {
                if(f[j]<=f[j-w[i]]+v[i])
                {
                	f[j]=f[j-w[i]]+v[i];
				}
				else
				{
					f[j]=f[j];
				}
                
            }
        }
        printf("采用整数背包法的最大价值:%f\n",f[p]);
        for(int j=2;j<=n;j++)      //按单位价值从高到低对物品排序 
	    {
	        float key1=s[j];
	        int key2=w[j];
	        int key3=v[j];
	        int i=j-1;
	        while(i>=1&&s[i]>key1)
	        {
	   	        s[i+1]=s[i];
	   	        w[i+1]=w[i];
	   	        v[i+1]=v[i];
	   	        i=i-1;
	        }
	        s[i+1]=key1;	
	        w[i+1]=key2;
	        v[i+1]=key3;
	    }
	    int weight=0;
		float value=0;
	    for(int i=n;i>=1;i--)
	    {
	
	    	if(weight<=p)
	    	{
	    		if(w[i]<=p-weight)
        	    {
        		    value=value+v[i];
        		    weight=weight+w[i];
        		
			    }
			    else
			    {
			    	value=value+(float)(p-weight)*v[i]/w[i];
			    	weight=weight+w[i];
			    }
			}
			
	    	
		}
		printf("采用分数背包法的最大价值:%f\n",value);
       
	}
       
        
}
int main()
{
    int n, p;
    printf("请输入物品个数和背包载重:");
    scanf("%d%d",&n,&p);
    Knapsack(n,p);
    system("pause");
    return 0;
}
