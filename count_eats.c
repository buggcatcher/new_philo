#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHILO 100

int main(void)
{
    char line[256];
    int counts[MAX_PHILO] = {0};
    int philo_num;

    while (fgets(line, sizeof(line), stdin))
    {
        if (strstr(line, "is eating"))
        {
            if (sscanf(line, "%*d %d is eating", &philo_num) == 1)
            {
                if (philo_num > 0 && philo_num < MAX_PHILO)
                    counts[philo_num]++;
            }
        }
    }

    printf("Conteggio pasti per filosofo:\n");
    for (int i = 1; i < MAX_PHILO; i++)
    {
        if (counts[i] > 0)
            printf("Filosofo %d ha mangiato %d volte\n", i, counts[i]);
    }

    return 0;
}
