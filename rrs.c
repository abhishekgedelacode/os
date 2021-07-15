#include <stdio.h>

int main()
{
    int i, j, n, qntm, time = 0;
    int pId[10], srTime[10], taTime[10], wtTime[10], b[10];
    int start[10], finish[10];
    float totTaTm = 0.0, totWtTm = 0.0;

    printf("Enter no. processes and time quantum: ");
    scanf("%d %d", &n, &qntm);
    printf("Enter process no and service time: ");
    for (i = 0; i < n; i++)
        scanf("%d %d", pId[i], srTime[i]);

    for (i = 0; i < n; i++)
        b[i] = srTime[i];

    start[0] = 0;

    for (i = 1; i < n; i++)
        start[i] = start[i - 1] + qntm;

    for (i = 0; i < n; i++)
    {
        while (b[i] != 0)
        {
            for (j = 0; j < n; j++)
            {
                if (b[j] == 0)
                    continue;
                if (b[j] > qntm)
                {
                    b[j] = b[j] - qntm;
                    time += qntm;
                }
                else
                {
                    time += b[j];
                    b[j] = 0;
                    finish[j] = time;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        taTime[i] = finish[i];
        wtTime[i] = finish[i] - srTime[i];
        totTaTm += taTime[i];
        totWtTm += wtTime[i];
    }

    printf("\npId \tsT \tfT \ttaT \twT");
    for (i = 0; i < n; i++)
    {
        printf("\n %d \t%d \t%d \t%d \t%d", pId[i], srTime[i], finish[i], taTime[i], wtTime[i]);
    }

    printf("\n Avg Turn Around Time: %f", totTaTm / n);
    printf("\n Avg Waiting Time: %f\n", totWtTm / n);
    return 0;
}