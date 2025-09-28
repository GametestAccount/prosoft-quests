#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct cmd
{
    char operation[6];
    char arg_1[7];
    char arg_2[7];
    bool is_executed;
};

int get_value(const char *arg, const int *sheet)
{
    if (arg[0] == '$')
    {
        int index = atoi(&arg[1]);

        return sheet[index];
    }

    return atoi(arg);
}

bool execute_op(const struct cmd *op, int *sheet, int i)
{
    int arg_1 = get_value(op->arg_1, sheet);
    int arg_2 = get_value(op->arg_2, sheet);

    if ((arg_1 == INT_MAX) || (arg_2 == INT_MAX))
        return false;

    if (!strcmp(op->operation, "VALUE"))
        sheet[i] = arg_1;
    else if (!strcmp(op->operation, "ADD"))
        sheet[i] = arg_1 + arg_2;
    else if (!strcmp(op->operation, "SUB"))
        sheet[i] = arg_1 - arg_2;
    else if (!strcmp(op->operation, "MULT"))
        sheet[i] = arg_1 * arg_2;

    return true;
}

int main()
{
    int N;
    scanf("%d", &N);

    int sheet[N];

    struct cmd commands[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%5s %6s %6s", commands[i].operation, commands[i].arg_1, commands[i].arg_2);

        commands[i].is_executed = false;

        sheet[i] = INT_MAX;
    }
    
    int executed_command = 0;

    int next_command_index = 0;

    int down_lim = 0; bool count_down_lim = true;

    while (executed_command < N)
    {
        if (next_command_index >= N)
        {
            next_command_index = down_lim;
            count_down_lim = true;
        }

        if (!commands[next_command_index].is_executed)
        {
            if (execute_op(&commands[next_command_index], sheet, next_command_index))
            {
                commands[next_command_index].is_executed = true;
                executed_command++;

                if (count_down_lim)
                    down_lim++;
            }
            else
            {
                count_down_lim = false;
            }
        }

        next_command_index++;
    }

    for (int i = 0; i < N; i++)
    {
        // Write an answer using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        printf("%d\n", sheet[i]);
    }

    return 0;
}