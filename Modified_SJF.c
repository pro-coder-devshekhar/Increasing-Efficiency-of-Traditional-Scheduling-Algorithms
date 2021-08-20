#include <stdio.h>
int main()

{
    int at[10], bt[10], rt[10], rt1[10], endTime, i, smallest, ch;
    int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0, k = -1;
    printf("Enter no of Processes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time for Process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for Process P%d : ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        rt1[i] = bt[i];
    }
    do
    {
        printf("Enter 1 for SJF(Preemptive)\n");
        printf("Enter 2 for modified SJF(Preemptive)\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf(" \n  Sequency of execution for SRTF  \n");
            for (time = 0; remain != n; time++)
            {
                smallest = 9;
                for (i = 0; i < n; i++)
                {
                    if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                    {
                        smallest = i;
                    }
                }
                rt[smallest]--;
                if (k != smallest)
                {
                    printf("p%d |", smallest + 1);
                }
                k = smallest;
                if (rt[smallest] == 0)
                {
                    remain++;
                    endTime = time + 1;
                    sum_wait += endTime - bt[smallest] - at[smallest];
                    sum_turnaround += endTime - at[smallest];
                }
            }

            printf("\n\nAverage waiting time = %f\n", sum_wait * 1.0 / n);
            printf("Average Turnaround time = %f\n", sum_turnaround * 1.0 / n);
            break;
        
        case 2:
            k = -1;
            remain = 0, n, sum_wait = 0, sum_turnaround = 0;
            printf(" \n Sequence of execution for Modified SRTF \n");
            for (time = 0; remain != n; time++)
            {
                smallest = 9;
                for (i = 0; i < n; i++)
                {
                    if (at[i] <= time && rt1[i] < rt1[smallest] / 2 && rt1[i] > 0)
                    {
                        smallest = i;
                    }
                }
                rt1[smallest]--;
                if (k != smallest)
                {
                    printf("p%d |", smallest + 1);
                }
                k = smallest;

                if (rt1[smallest] == 0)
                {
                    remain++;
                    endTime = time + 1;
                    sum_wait += endTime - bt[smallest] - at[smallest];
                    sum_turnaround += endTime - at[smallest];
                }
            }

            printf("\n\nAverage waiting time = %f\n", sum_wait * 1.0 / n);
            printf("Average Turnaround time = %f\n", sum_turnaround * 1.0 / n);
        }
    } while (ch != 0);

    return 0;
}
