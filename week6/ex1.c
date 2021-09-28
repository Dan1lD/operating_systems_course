#include <stdio.h>

int num_of_proc;

void FCFS(int arrival_time[], int burst_time[]) {
    int waiting_time[num_of_proc], turn_around_time[num_of_proc], buff[num_of_proc];
    int total_waiting = 0;
    int total_TAT = 0;
    buff[0] = 0;
    waiting_time[0] = 0;

    for (int i = 1; i < num_of_proc; i++) {
        buff[i] = buff[i - 1] + burst_time[i - 1];
        waiting_time[i] = buff[i] - arrival_time[i];
        if (waiting_time[i] < 0)
            waiting_time[i] = 0;
    }

    for (int i = 0; i < num_of_proc; i++)
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    for (int i = 0 ; i < num_of_proc; i++) {
        total_waiting += waiting_time[i];
        total_TAT += turn_around_time[i];
        int completion_time = turn_around_time[i] + arrival_time[i];
        printf("process %d:\nBurst time: %d\nArrival time: %d\nWaiting time: %d\nTurnaround time: %d\n"
               "Completion time: %d\n\n", i + 1, burst_time[i], arrival_time[i], waiting_time[i],turn_around_time[i], completion_time);
    }

    printf("Average Waiting time: %lf\n", (double)total_waiting/(double)num_of_proc);
    printf("Average Average Turnaround time: %lf", (double)total_TAT/(double)num_of_proc);
}


int main() {
    printf("Enter number of processes:\n");
    scanf("%d", &num_of_proc);
    int arrival_time[num_of_proc], burst_time[num_of_proc];
    printf("Enter arrival_time and burst_time for each process:\n");

    for (int i = 0; i < num_of_proc; i++) {
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    FCFS(arrival_time, burst_time);

    return 0;
}