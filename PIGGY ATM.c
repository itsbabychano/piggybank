#include<stdio.h>
#include<windows.h>
#include<time.h>

int main()
{   
    system("color 1F");
    
    int pin=123456;
    int opt;
    int pinenter;
    int try = 0;
    int amt = 1;
    int transac = 1;
    float bal = 0;
   
    time_t now;
    time(&now);
    printf("\n");
    printf("\n\t\t\t\t\t\t %s",ctime(&now));
    printf("\t\t\t\t\t PIGGY BANK AUTOMATED TELLER MACHINE (ATM)");

    while (pin != pinenter)
        {   
            printf("\n");
            printf("\t\t\t\t===============================================================\n");
            printf("\n");
            printf("\t\t\t\t\t\tEnter your 6-digit PIN: ");
            scanf("%d", &pinenter);
            printf("\n");
            printf("\t\t\t\t===============================================================\n");
            if(pinenter != pin)
            {
                Beep(500,700);
                printf("\n");
                printf("\t\t\t\t\t\t\tINVALID PIN\n");
            }
            try++;
            if(try == 3 && pin != pinenter)
            {
                printf("\t\t\t\t\t              TRY AGAIN LATER\n");
                exit(0);
            }
        }
       
        while (transac >= 1)
        {
            Beep(500,700);
            printf("\n");
            printf("\t\t\t\t\t PLEASE SELECT A TRANSACTION\n");
            printf("\t\t\t\t\t 1. Balance Inquiry\n");
            printf("\t\t\t\t\t 2. Deposit\n");
            printf("\t\t\t\t\t 3. Withdraw\n");
            printf("\n");
            printf("\n\t\t\t\t\t SELECT: ");
            scanf("%d", &opt);
            printf("\t\t\t\t===============================================================\n");
            switch (opt)
            {
            case 1:
                Beep(500,700);
                printf("\n");
                printf("\t\t\t\t\tCurrent balance: Php %.2lf\n", bal);
                break;
                
            case 2:
                Beep(500,700);
                printf("\n");
                printf("\t\t\t\t\tEnter amount: Php ");
                scanf("\t\t\t\t\t%d", &amt);
                bal +=amt;

                printf("\n");
                printf("\t\t\t\t\tAmount deposited: Php %d\n", amt);
                printf("\t\t\t\t\tNew balance: Php %.2lf\n", bal);
                amt = 1; 
                break;

            case 3:
                while (amt % 5 != 0)
                {
                    Beep(500,700);
                    printf("\n\t\t\t\t\tAmount should be divisible by 10");
                    printf("\n\t\t\t\t\tEnter the amount: Php ");
                    scanf("%d", &amt);
                    
                }

                if(bal < amt)
                {
                    Beep(500,700);
                    printf("\n");
                    printf("\t\t\t\t===============================================================\n");
                    printf("\t\t\t\t\tSorry, Insufficient balance\n");
                    printf("\t\t\t\t\tCurrent balance: Php %.2lf\n", bal);
                    amt= 1;
                    break;
                }
                else
                {
                    Beep(500,700);
                    bal -= amt;
                    printf("\n");
                    printf("\t\t\t\t\tAmount withdrawn: Php %d\n", amt);
                    printf("\t\t\t\t\tNew balance: Php %.2lf\n", bal);
                    amt=1;
                    break;
                }

            default:
                Beep(500,700);
                printf("\t\t\t\t\tInvalid option\n");

            }
            Beep(500,700);
            printf("\n");
            printf("\t\t\t\t===============================================================\n");
            printf("\t\t\t\t\tPerform another transaction?\n");
            printf("\n\t\t\t\t\tPress 1 if YES, 0 if NO: ");
            scanf("%d", &transac);
            printf("\t\t\t\t===============================================================\n");
            printf("\n");
            if(transac == 0)
            {
                Beep(500,700);
                printf("\t\t\t\t\tThank you for using Piggy Bank ATM!\n");
                printf("\n");
                printf("\t\t\t\t===============================================================\n");
                break;
            }
            
        }
        
    return 0;
}
