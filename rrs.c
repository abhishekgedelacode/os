#include <stdio.h>

int main()
{
    int i, j, n, qntm, time = 0;
    int pId[10], srTime[10], taTime[10], wtTime[10];
    int start[10], finish[10];

    printf("Enter no. processes and time quantum: ");
    scanf("%d %d", &n, &qntm);
    printf("Enter process no and service time: ");
    for (i = 0; i < n; i++)
        scanf("%d %d", pId[i], srTime[i]);
    return 0;
}