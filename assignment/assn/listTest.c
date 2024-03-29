/**
 * Crude driver program to test list ADT for COMP9024 Pagerank Assignment
 *
 * Written by: Tim Arney <t.arney@unsw.edu.au>
 * Date: 17/07/2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "list.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <queue|stack|set|all>\n", argv[0]);
        return EXIT_FAILURE;
    }

    string line = NULL;
    size_t len = 0;
    ssize_t read;

    if (strcmp(argv[1], "queue") == 0) {
            list queue = list_create();
            printf("Queue length: %zu\n", list_length(queue));

            while ((read = getline(&line, &len, stdin)) != -1) {
                list_enqueue(queue, line);
                printf("Enqueue: %s", line);
            }

            free(line);

            if (ferror(stdin)) {
                return EXIT_FAILURE;
            }

            printf("Queue length: %zu\n", list_length(queue));

            while (!list_is_empty(queue)) {
                line = list_dequeue(queue);
                printf("Dequeue: %s", line);
                free(line);
            }

            printf("Queue length: %zu\n", list_length(queue));

            list_destroy(queue);
    } else if (strcmp(argv[1], "stack") == 0) {
        list stack = list_create();
        printf("Stack height: %zu\n", list_length(stack));

        while ((read = getline(&line, &len, stdin)) != -1) {
            list_push(stack, line);
            printf("Push: %s", line);
        }

        free(line);

        if (ferror(stdin)) {
            return EXIT_FAILURE;
        }

        printf("Stack height: %zu\n", list_length(stack));

        while (!list_is_empty(stack)) {
            line = list_pop(stack);
            printf("Pop: %s", line);
            free(line);
        }

        printf("Stack height: %zu\n", list_length(stack));

        list_destroy(stack);
    } else if (strcmp(argv[1], "set") == 0) {
        list set = list_create();
        printf("Set size: %zu\n", list_length(set));

        int i = 0;

        while ((read = getline(&line, &len, stdin)) != -1) {
            printf("Add: %s", line);
            list_add(set, line);

            if (i % 2 == 0) {
                list_remove(set, line);
                printf("Remove: %s", line);
            }

            printf("%s: %s", list_contains(set, line) ? "Contains" : "Doesn't contain", line);

            i++;
        }

        free(line);

        if (ferror(stdin)) {
            return EXIT_FAILURE;
        }

        printf("Set size: %zu\n", list_length(set));

        list_destroy(set);
    } else if (strcmp(argv[1], "all") == 0) {
        list queue = list_create();
        list stack = list_create();
        list set = list_create();

        while ((read = getline(&line, &len, stdin)) != -1) {
            if (!list_contains(set, line)) {
                list_push(stack, line);
                printf("Push: %s", line);
            }

            list_add(set, line);
            printf("Add: %s", line);
        }

        free(line);

        if (ferror(stdin)) {
            return EXIT_FAILURE;
        }

        while (!list_is_empty(stack)) {
            line = list_pop(stack);
            printf("Pop: %s", line);
            list_enqueue(queue, line);
            printf("Enqueue: %s", line);
            free(line);
        }

        while (!list_is_empty(queue)) {
            line = list_dequeue(queue);
            printf("Dequeue: %s", line);
            list_push(stack, line);
            printf("Push: %s", line);
            free(line);
        }

        while (!list_is_empty(stack)) {
            line = list_pop(stack);
            printf("Pop: %s", line);
            free(line);
        }

        printf("Queue length: %zu\n", list_length(queue));
        printf("Stack height: %zu\n", list_length(stack));
        printf("Set size: %zu\n", list_length(set));

        list_destroy(queue);
        list_destroy(stack);
        list_destroy(set);
    } else {
        fprintf(stderr, "Usage: %s <queue|stack|set|all>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
