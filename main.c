#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"
/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}*/
int main()
{
    int choice,ticket_no,result,pmob_no,pticket_no;
    char trno[10];
    char* ptrain_no;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);

    switch(choice)
    {
        case 1:
            clrscr();
            view_trains();
            textcolor(WHITE);
            printf("enter any key to go back to main screen");
            getch();
            clrscr();
            break;

        case 2:
             clrscr();
             Passenger *ptr;
             ptr=get_passenger_details();
             if(ptr!=NULL)
             {
               ticket_no=book_ticket(*ptr);
               if(ticket_no==-1)
               {
                   textcolor(RED);
                   printf("bokking failed!");
               }
               else
                {
                  textcolor(GREEN);
                  printf("\nTicket Successfully booked \nyour ticket no is %d\n",ticket_no);
                }
                textcolor(WHITE);
                printf("\npress any key to go back to the main screen");
                getch();
                clrscr();
                break;
             }
            //printf("enter train no for search\n");
            //scanf("%s",trno);
            //check_train_no(trno);
           // book_ticket(s);
            break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\npress any key to go back to the main screen");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;

        case 5:
            clrscr();
            view_all_bookings();
            break;
        case 6:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
                view_booking(ptrain_no);
            break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(RED);
                    printf("Sorry!no tickets booked against ticket no %d",ticket_no);
                }
                else if(result==1)
                {
                    textcolor(GREEN);
                    printf("Ticket no %d successfully cancelled!",ticket_no);
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
            }
            getch();
            clrscr();
            break;
        case 8:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            {
              result=cancel_train(ptrain_no);
                if(result==1)
                {
                    textcolor(GREEN);
                    printf("Train successfully cancelled!");
                }
                else
                {
                    textcolor(RED);
                    printf("No booking in this train for cancel");
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
            }
            getch();
            break;
        default:
            textcolor(RED);
            printf("Wrong choice!Try again\n");
            getch();
    }
    }
    return 0;
}
