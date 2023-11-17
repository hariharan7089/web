#include <stdio.h>
int main()
{
    int n, i, j, temp;
    float avg_wt, avg_tat;
    int bt[20], pr[20], wt[20], tat[20] ,p[20];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i]=i+1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    avg_wt = 0;
    tat[0] = bt[0];
    avg_tat = tat[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        avg_wt += wt[i];
        tat[i] = tat[i - 1] + bt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    for(i=0;i<n;i++){
        printf("\n------------------------------\n");
        printf("p[%d]\t",p[i]);
        printf("\n------------------------------");

    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\n\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
    return 0;
}
