#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k;
	int count, n, time, remain, flag = 0, time_quantum;
	int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
	printf("Enter Total Process:\t ");
	scanf("%d", &n);
	remain = n;

	for (count = 0; count < n; count++)
	{
		printf("Enter Arrival Time and Burst Time for Process Process Number %d :", count + 1);
		scanf("%d", &at[count]);
		scanf("%d", &bt[count]);
		rt[count] = bt[count];
	}

	printf("Enter Time Quantum:\t");
	scanf("%d", &time_quantum);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

	//First Mandatory Pass

	for (k = 0, time = 0, count = 0; k < n; k++)
	{
		if (rt[count] <= time_quantum && rt[count] > 0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}

		else if (rt[count] > 0)
		{
			rt[count] -= time_quantum;
			time += time_quantum;
		}

		if (rt[count] == 0 && flag == 1)
		{
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
			wait_time += time - at[count] - bt[count];
			turnaround_time += time - at[count];
			flag = 0;
		}

		if (count == n - 1)
			count = 0;

		else if (at[count + 1] <= time)
			count++;

		else
			count = 0;
	}

	printf("After first pass: \nTAT= %d", turnaround_time);
	printf("\nWT= %d", wait_time);
	printf("\n");

	//Processes Having time Remaining which is less than time quantum

	for (k = 0; k < n; k++)
	{
		if (rt[k] > 0 && rt[k] <= time_quantum)
		{
			remain--;
			time += rt[k];
			rt[k] = 0;
			printf("P[%d]\t|\t%d\t|\t%d\n", k + 1, time - at[k], time - at[k] - bt[k]);
			wait_time += time - at[k] - bt[k];
			turnaround_time += time - at[k];
			count = k;
		}
	}

	printf("After second pass: \nTAT= %d", turnaround_time);
	printf("WT= %d", wait_time);
	printf("\n");

	//Context switch to place pointer at the location of first remaining Process in the array

	if (count == n - 1)
		count = 0;

	else if (at[count + 1] <= time)
		count++;

	else
		count = 0;

	//Processing the remaining processes

	while (remain != 0)
	{
		if (rt[count] <= time_quantum && rt[count] > 0)
		{
			time += rt[count];
			rt[count] = 0;
			flag = 1;
		}

		else if (rt[count] > 0)
		{
			rt[count] -= time_quantum;
			time += time_quantum;
		}

		if (rt[count] == 0 && flag == 1)
		{
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
			wait_time += time - at[count] - bt[count];
			turnaround_time += time - at[count];
			flag = 0;
		}

		if (count == n - 1)
			count = 0;

		else if (at[count + 1] <= time)
			count++;

		else
			count = 0;
	}

	printf("After third pass: \nTAT= %d", turnaround_time);
	printf("\nWT= %d", wait_time);
	printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
	printf("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);
	printf("\n");
	return 0;
}
