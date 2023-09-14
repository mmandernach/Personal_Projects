/**
 *  Mason Mandernach
 *  09/14/2023
 *  Sample solution for CSCE 155E
 *  Exam 1 part 1
 *  
 *  A calculator that predicts the record of a football team 
 *  based on points for and points against for a 12 game season.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv){
    
    if (argc != 3){
        printf("ERROR: invalid number of inputs");
        return 1;
    }

    int ptsFor, ptsAgainst, wins, losses, seasonLength;
    double winPercentage, calculatedWins;

    ptsFor = atoi(argv[1]);
    ptsAgainst = atoi(argv[2]);

    if (ptsAgainst < 0 || ptsFor < 0){
        printf("ERROR: can't have negative points");
        return 1;
    }

    winPercentage = pow(ptsFor, 2.37) / (pow(ptsFor, 2.37) + pow(ptsAgainst, 2.37));
    calculatedWins = winPercentage * 12;
    wins = round(calculatedWins);
    losses = 12 - wins;

    printf("Win Percentage: %.2f%%\n", winPercentage * 100);
    printf("Win/Loss: %d/%d\n", wins, losses);

    return 0;
}