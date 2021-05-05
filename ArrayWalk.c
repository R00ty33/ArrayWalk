/** Nicholas Rudolph */
/** ArrayWalk        */
/** Feb 6th 2020     */

/** directives */
#include <stdio.h> /** printf */
#include <stdlib.h>
#include <time.h>  /** seeding */

#define N 10 /** char walk[N][N]

/** generats random walk[N][N] */ 
void generate_random_walk(char walk[N][N]) {
    char c = 'A'; /** char represents the character being displayed */
    int count = 1; /** int represents the current iteration of the alphabet */
    int randNum; /** int represents int generated from rand() */
    int x = 0; /** int represents rows */
    int y = 0; /** int represents columns */
    int z = 1; /** int which terminates program */
    int terminate = 0; /** counts every iteration, if it excedes (26*4), sets z=0 */

/** fills walk[N][N] with '.' */
    for (int i=0 ; i<N ; i++) {
        for (int j=0; j<N ; j++) {
                walk[i][j] = '.';
        } // end of for loop
    }  // end of for loop

/** creates a path in walk[N][N] with chars A-Z (c + count) which connect to each other */
    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            if (count < 26) { /** alphabet */
                if (i == 0 && j == 0) walk[i][j] = 'A'; /** first char in walk[N][N] is 'A' */
                    else {
                    while(z) { /** while true (z=1) */
                        terminate++; /** increments terminate which terminates the program if it == (26*4) */
                        randNum = (rand() % 4); /** generates random number 0,1,2,3 */
                        // printf("\nIteration: %d Dice Roll: %d\n", count, randNum);
                        
                        if (randNum == 0 ) { // the next char will be placed above
                            if (i != 0 && x != 0) { // Exception
                                if (walk[x-1][y] == '.') { // Exception
                                    walk[x-1][y] = c + count;
                                    if (count != 1) {
                                        x += -1;
                                        count++;
                                    } // end of if
                                    else {
                                        x = 0;
                                        y = 0;
                                        count++;
                                    } // end of else
                                    // printf("\nx = %d  y = %d\n", x, y);
                                    break;
                                } // end of if
                            } // end of if
                        } // end of if
                        if (randNum == 1) { // the next char will be placed to the right
                            if (j != 10 && y < 9) { // Exception
                                if (walk[x][y+1] == '.') { // Exception
                                    walk[x][y+1] = c + count;
                                    if (count != 1) {
                                        y += 1;
                                        count++;
                                    } // end of if
                                    else {
                                        x = 0;
                                        y = 1;
                                        count++;
                                    } // end of else
                                    // printf("\nx = %d  y = %d\n", x, y);
                                    break;
                                } // end of if
                            } // end of if
                        } // end of if
                        if (randNum == 2) { // the next char will be go down
                            if (i != 10 && x != 10) { // Exception
                                if (walk[x+1][y] == '.') { // Exception
                                    walk[x+1][y] = c + count;
                                    if (count != 1) {
                                        x += 1;
                                        count++;
                                    }  // end of if
                                    else {
                                        x = 1;
                                        y = 0;
                                        count++;
                                    } // end of else
                                    // printf("\nx = %d  y = %d\n", x, y);
                                    break;
                                } // end of if
                            } // end of if
                        } // end of if
                        if (randNum == 3) { // the next char will be placed to the left
                            if (j != 0 && y != 0) { // Exception
                                if (walk[x][y-1] == '.') { // Exception
                                    walk[x][y-1] = c + count;
                                    if (count != 1) {
                                        y += -1;
                                        count++;
                                    } // end of if
                                    else {
                                        x = 0;
                                        y = 0;
                                        count++;
                                    } // end of else
                                    // printf("\nx = %d  y = %d\n", x, y);
                                    break;
                                } // end of if
                            } // end of if
                        } // end of if
                        if (terminate > (26 * 4)) {
                            printf("\nTerminated: No possible paths\n");
                            z = 0; /** sets z to false */
                            break;
                        } // end of if
                    } // end of while loop
                } // end of else 
            } // end of if
        } // end of for loop
    } // end of for loop
} // end of generate_random_walk()


/** prints array walk[N][N] */
void print_array(char walk[N][N]) {
    for (int i=0 ; i<N ; i++) {
        printf("\n");
        for (int j=0 ; j<N ; j++) {
            printf("%c", walk[i][j]);
            printf(" ");
        } // end of for loop
    } // end of for loop
    printf("\n\n");
} // end of print_array()


/** MAIN */
int main(void) {
    char walk[N][N];

    srand((unsigned) time(NULL));
    generate_random_walk(walk);
    print_array(walk);

    return 0;
} // end of main