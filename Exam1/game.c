/**
 *  Mason Mandernach
 *  09/14/2023
 *  Sample solution for CSCE 155E
 *  Exam 1 part 2
 *  
 *  A game that takes a positive integer value and if it's even 
 *  player A gets a point and the number is halved. If the number 
 *  is odd player B gets a point and the value is multiplied by 3
 *  and 1 is added (3n + 1). The game ends when the number is reduced
 *  to one. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int main(int argc, char** argv){

    if (argc != 2){
        printf("ERROR: invalid number of inputs");
        return 1;
    }

    int num, aScore, aPoints, bScore, bPoints, gameOver;
    
    num = atoi(argv[1]);
    aPoints = 0;
    bPoints = 0;
    gameOver = 0;

    if (num < 0){
        printf("ERROR: can't input a negative number");
        return 1; 
    }

    printf("Starting Value: %d\n", num);

    int i = 1;
    while(gameOver == 0){
        if (num == 1){
            printf("Game Over!\n\n");
            gameOver = 1;  
        } else if ((num % 2) == 0){
            printf("Round%3d:%4d... even, player A scores!\n", i, num);
            num = num / 2;
            aPoints += 1;
        } else if ((num % 2) == 1){ 
            printf("Round%3d:%4d...  odd, player B scores!\n", i, num);
            num = (3*num) + 1;
            bPoints += 1;
        }
        i++;
    }

    aScore = ((2 * aPoints) - 1) / 3;
    bScore = ((3 * bPoints) + 1) / 2;
    
    printf("Results:\n");
    printf("%-9s%-9s%s\n", "Player", "Points", "Total Score"); 
    printf("%-9c%-9d%d\n", 'A', aPoints, aScore);
    printf("%-9c%-9d%d\n", 'B', bPoints, bScore);
    aScore > bScore ? printf("A wins!\n") : printf("B wins!\n");


    return 0; 
}