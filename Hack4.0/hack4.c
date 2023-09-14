/* 
 *  Mason Mandernach
 *  CSCE 155E Hack 4.0 Demo
 *  09/13/2023
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char** argv){

    if (argc != 6){
        printf("ERROR: invalid number of inputs");
        return 1;
    }

    double balance, monthlyContribution, avgReturnRate, avgInflationRate, totalInterest, interest, yearsTillRetirement;

    balance = atof(argv[1]);
    monthlyContribution = atof(argv[2]);
    avgReturnRate = atof(argv[3]);
    avgInflationRate = atof(argv[4]);
    yearsTillRetirement = atof(argv[5]);

    double adjustedRate = ((avgReturnRate+1)/(avgInflationRate+1))-1;
    double monthlyRate = adjustedRate/12;
    
    printf("%-5s%11s%13s\n", "Month", "Interest", "Balance");
    for (int i = 0 ; i < 30 ; i++){
        printf("-");
    }
    printf("\n");

    for (int i = 0 ; i < (yearsTillRetirement*12.0) ; i++){
        interest = balance * monthlyRate; 
        totalInterest += interest;
        balance += interest;
        balance += monthlyContribution; 

        printf("%5d  $%8.2f  $%10.2f\n", i+1, interest, balance);
    }
    printf("\nTotal nest egg is: $%.2f\n", balance);
    printf("Total interest is: $%.2f\n", totalInterest);

    return 0;
}