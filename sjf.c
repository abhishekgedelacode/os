#include <stdio.h>

int main()
{
    int pId[10], exeTime[10], arTime[10], wtTime[10], taTime[10];
    int start[10], finish[10];
    int n, i, j, temp, totWt = 0, totTat = 0;

    printf("Enter no of Processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter pId, arTime, exeTime:\n[%d]: ", i + 1);
        scanf("%d %d %d", &pId[i], &arTime[i], &exeTime[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (exeTime[i] < exeTime[j])
            {
                temp = arTime[i];
                arTime[i] = arTime[j];
                arTime[j] = temp;

                temp = exeTime[i];
                exeTime[i] = exeTime[j];
                exeTime[j] = temp;

                temp = pId[i];
                pId[i] = pId[j];
                pId[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[i] = arTime[i];
            wtTime[i] = start[i] - arTime[i];
            finish[i] = start[i] + exeTime[i];
            taTime[i] = finish[i] - arTime[i];
        }
        else
        {
            start[i] = finish[i - 1];
            wtTime[i] = start[i] - arTime[i];
            finish[i] = start[i] + exeTime[i];
            taTime[i] = finish[i] - arTime[i];
        }
    }

    printf("\npId \taT \tsT \teT \twT \ttaT");
    for (i = 0; i < n; i++)
    {
        printf("\n %d \t%d \t%d \t%d \t%d \t%d", pId[i], arTime[i], start[i], exeTime[i], wtTime[i], taTime[i]);
        totWt += wtTime[i];
        totTat += taTime[i];
    }

    printf("\n Avg Waiting Time: %f", (float)totWt / n);
    printf("\n Avg Turn Around Time: %f\n", (float)totTat / n);

    return 0;
}