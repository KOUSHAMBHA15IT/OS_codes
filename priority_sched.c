#include <stdio.h>
int main()
{
    int n = 5;
    int id[] = {1, 2, 3, 4, 5};
    int at[] = {0, 5, 12, 2, 9}; 
    int bt[] = {11, 28, 2, 10, 16};
    int priority[] = {2, 0, 3, 1, 4};

    int bt_left[5],ct[5],tat[5],wt[5];

    for(int i=0;i<n;i++){
        bt_left[i] = bt[i];
    }

    int t=0,complete=0,maxi_priority=-1,highest=-1;
    int check = 0;
    while(complete!=n){

        for(int i=0;i<n;i++){
            if((priority[i]>maxi_priority) && (at[i]<=t) && (bt_left[i]>0)){ 
                maxi_priority = priority[i];
                highest = i;
                check = 1;
            }
        }
            if(check == 0){
                t++;
                continue;
            }
            bt_left[highest]--;
            maxi_priority = priority[highest];

            if(bt_left[highest] == 0){
                complete++;
                check=0;
                ct[highest] = t+1;

                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];
            }
        t++;
        maxi_priority = -1;
    }
    float avg_wt = 0;
    int s=0;
    for (int i = 0; i < n; i++) {
        s+=wt[i];
    }
     avg_wt = (float)s/n;
   

    printf("Average waiting time: %.2f\n", avg_wt);
    return 0;
}