#include <stdio.h>

int main()
{
    int pId[10];
    int arTime[10], bTime[10], taTime[10], wtTime[10];
    int start[10], finish[10];
    int i, n, totwtTime = 0, tottarTime = 0;

    printf("Enter no of Processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter pId, arrTime, burstTime:\n[%d]: ", i + 1);
        scanf("%d %d %d", &pId[i], &arTime[i], &bTime[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[i] = arTime[i];
            wtTime[i] = start[i] - arTime[i];
            finish[i] = start[i] + bTime[i];
            taTime[i] = finish[i] - arTime[i];
        }
        else
        {
            start[i] = finish[i - 1];
            wtTime[i] = start[i] - arTime[i];
            finish[i] = start[i] + bTime[i];
            taTime[i] = finish[i] - arTime[i];
        }
    }

    printf("\npId   arTime  bTime   start   taTime finish");
    for (i = 0; i < n; i++)
    {
        printf("\n %d\t%d\t%d\t%d\t%d\t%d", pId[i], arTime[i], bTime[i], start[i], taTime[i], finish[i]);
        totwtTime += wtTime[i];
        tottarTime += taTime[i];
    }

    printf("\n\n Avg Waiting Wime: %f", (float)totwtTime / n);
    printf("\n Avg Turn Around Time: %f\n", (float)tottarTime / n);

    return 0;
}