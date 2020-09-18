/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <getopt.h>
#include <time.h>

static void print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

int main(int argc, char** argv) {
    tree t = tree_new();
    
    const char *optstring = "ab:c";
    char option;
    int count = 0;
    clock_t time;
    double time_taken = 0;
    
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'a':
                time = clock();
                while(scanf(" %49[^ \t.\n]%*c", i)) {
                    insert(t, i);
                }
                time = clock() - time;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                fprintf(stderr, "Fill time%6: %f\n", time_taken);
                time = clock();
                while((c = fgetc(fp)) != EOF) {
                    if (c != ' ' || c != '\n') {
                        if (search(t, c) == NULL) {
                            printf("%s\n", c);
                            count++;
                        }
                    }
                }
                time = clock() - time;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                fprintf(stderr, "Search time%6: %f\n", time_taken);
                fprintf(stderr, "Unknown words = %d", count);
            case 'b':
                /* the argument after the -b is available
                   in the global variable 'optarg' */
                if (time_taken == 0) {
                    printf("%d\n", tree_depth(t));
                }
                break;
            case 'c':
                /* do something else */
            default:
                /* if an unknown option is given */
        }
    }
}
