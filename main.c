/*student (1):
Name: Md. Abir hossian
id:173
Student (2):
Name: Alif
id:*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int password();
void addRecord();
void viewRecord();
void editRecord();
void editPassword();
void deleteRecord();

struct record
{
    char time[10];
    char name[20];
    char place[20];
    char duration[10];
    char note[1000];

};

int main()
{
    int ch;
    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");
    while(1)
    {

                printf("\n\n\t\tMAIN MENU:");
                printf("\n\n\tTO ADD RECORD\tPRESS: [1]");
                printf("\n\tTO VIEW RECORD\tPRESS: [2]");
                printf("\n\tTO EDIT RECORD\tPRESS: [3]");
                printf("\n\tTO DELETE RECORD\t PRESS: [4]");
                printf("\n\tTO EDIT PASSWORD\t PRESS[5]");
                printf("\n\tTO EXIT\t\t PRESS: [6]");
                printf("\n\n\tENTER YOUR CHOICE:");
                scanf("%d",&ch);

                switch(ch)

                    {

                            case 1:
                            addRecord();
                            break;

                            case 2:
                            viewRecord();
                            break;


                            case 3:
                            editRecord();
                            break;

                            case 4:
                            deleteRecord();
                            break;

                            case 5:
                            editPassword();
                            break;

                            case 6:
                            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE");
                            getch();
                            exit(0);

                            default:
                            printf("\nYOUR ENTERED KEY IS WRONG");
                            printf("\nPLEASE PRESS ANY KEY [1 TO 6] TO TRY AGAIN");
                            getch();
                            break;

                    }

                system("cls"); //clears the output screen of the program

        }
        return 0;

}


void addRecord()
{
    system("cls");

    FILE *fp ;
    char another_record='y' , time[10];
    struct record R ;
    char fileName[20];
    int user_choice;
    printf("\t\t ADD MENU ");
    printf("\n\n\tENTER DATE OF YOUR NOTE:- [FORMAT: YY/MM/DD] ");
    fflush(stdin);
    gets(fileName);

    fp = fopen(fileName, "ab+" ) ;

     if ( fp == NULL )
        {
            fp=fopen(fileName,"wb+");

            if(fp==NULL)
            {

                    printf("\nSystem error..");
                    printf("\nPress any key to exit....");
                    getch();
                    return ;

            }

        }

    while ( another_record == 'Y'|| another_record =='y' )

                {

                user_choice=0;
                fflush(stdin);
                printf ( "\n\tENTER TIME:[hh:mm]:");
                scanf("%s",time);
                rewind(fp);

                while(fread(&R,sizeof(R),1,fp)==1)
                {

                    if(strcmp(R.time,time)==0)

                    {

                        printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                        user_choice=1;

                    }

                }



                    if(user_choice==0)

                    {

                        strcpy(R.time,time);
                        printf("\tENTER NAME:");
                        fflush(stdin);
                        gets(R.name);
                        fflush(stdin);

                        printf("\tENTER PLACE:");
                        gets(R.place);
                        fflush(stdin);

                        printf("\tENTER DURATION:");
                        gets(R.duration);
                        fflush(stdin);

                        printf("\tNOTE:");
                        gets(R.note);
                        fwrite ( &R, sizeof ( R ), 1, fp ) ;
                        printf("\nRecord is added...\n");

                    }

                        printf ( "\n\tDo you want to add another record or not...(Y/N) " ) ;
                        fflush ( stdin ) ;
                        another_record = getchar( ) ;

                }


                fclose ( fp ) ;
                printf("\n\n\tPRESS ANY KEY TO EXIT...");
                getch();

    }

void viewRecord()

{

        FILE *fp2 ;
        system("cls");
        struct record VR ;
        char time[10],user_choice,fileName[20];
        int ch;

        printf("\t\t VIEWING MENU: ");
        user_choice=password();
        if(user_choice!=0)

            {
                return ;
            }
        do

            {
                    printf("\n\tEnter the record of the date you want to view: FOrmat[yy-mm-dd]:");
                    fflush(stdin);
                    gets(fileName);
                    fp2=fopen( fileName, "rb" ) ;
                    if ( fp2==NULL)

                            {

                                puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
                                printf("PRESS ANY KEY TO EXIT...");
                                getch();
                                return ;

                            }

                            system("cls");

                printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");
                printf("\n\t1.WHOLE RECORD OF THE DAY.");
                printf("\n\t2.RECORD OF FIX TIME.");
                printf("\n\t\tENTER YOUR CHOICE:");
                scanf("%d",&ch);
                switch(ch)

                {

                    case 1:

                        printf("\nTHE WHOLE RECORD FOR %s IS:",fileName);
                        while ( fread ( &VR, sizeof(VR), 1,fp2) == 1)

                         {

                            printf("\n");
                            printf("\nTIME: %s",VR.time);
                            printf("\nMEETING WITH: %s",VR.name);
                            printf("\nMEETING AT: %s",VR.place);
                            printf("\nDURATION: %s",VR.duration);
                            printf("\nNOTE: %s",VR.note);
                            printf("\n");

                         }

                         break;


                    case 2:

                            fflush(stdin);
                            printf("\nENTER TIME:[hh:mm]:");
                            gets(time);
                            while ( fread ( &VR ,sizeof(VR), 1, fp2)== 1 )
                            {
                                if(strcmp(VR.time,time)==0)

                                {

                                    printf("\nYOUR RECORD IS:");
                                    printf("\nTIME: %s",VR.time);
                                    printf("\nMEETING WITH: %s",VR.name);
                                    printf("\nMEETING AT: %s",VR.place);
                                    printf("\nDUARATION: %s",VR.duration);
                                    printf("\nNOTE: %s",VR.note);

                                }

                            }

                            break;
                    default:
                        printf("\nWhat you typed doesn't exist in this record...\n");

                            break;

                }


               printf("\n\nWould you like to view another record...(Y/N):");
               fflush(stdin);
               scanf("%c",&user_choice);
            }

        while(user_choice=='Y'||user_choice=='y');

            fclose (fp2) ;
            return ;

}


void editRecord()

{

        system("cls");
        FILE *fp2 ;
        struct record VR ;
        char time[10],user_choice,fileName[20];
        int num,count=0;

        printf("\t\t EDITING MENU: ");
        user_choice=password();
        if(user_choice!=0)

            {
                return ;
            }

        do

            {

                    printf("\n\tEnter the date of the record that you want to edit:- [FORMAT yy-mm-dd]:");
                    fflush(stdin);
                    gets(fileName);
                    printf("\n\tEnter Time :[hh:mm]:");
                    gets(time);
                    fp2=fopen(fileName,"rb+" ) ;
                    if ( fp2 == NULL )

                            {
                                printf( "\nRecord doesn't exist: " ) ;
                                printf("\nPress any key to go back: ");
                                getch();
                                return;
                            }

                    while (fread(&VR,sizeof(VR),1,fp2)== 1 )
                    {
                        if(strcmp(VR.time,time)==0)
                        {

                            printf("\nYOUR OLD RECORD WAS AS:");
                            printf("\nTIME: %s",VR.time);
                            printf("\nMEETING WITH: %s",VR.name);
                            printf("\nMEETING AT: %s",VR.place);
                            printf("\nDURATION: %s",VR.duration);
                            printf("\nNOTE: %s",VR.note);

                            printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                                printf("\n1.TIME.");
                                printf("\n2.MEETING PERSON.");
                                printf("\n3.MEETING PLACE.");
                                printf("\n4.DURATION.");
                                printf("\n5.NOTE.");
                                printf("\n6.WHOLE RECORD.");
                                printf("\n7.GO BACK TO MAIN MENU.");
                                do
                                {

                                        printf("\n\tENTER YOUR CHOICE:");

                                        fflush(stdin);
                                        scanf("%d",&num);
                                        fflush(stdin);
                                        switch(num)

                                        {
                                            case 1:
                                                 printf("\nENTER THE NEW DATA:");
                                                    printf("\nNEW TIME:[hh:mm]:");
                                                    gets(VR.time);
                                                    break;


                                            case 2:
                                                printf("\nENTER THE NEW DATA:");
                                                    printf("\nNEW MEETING PERSON:");
                                                    gets(VR.name);
                                                    break;


                                            case 3:
                                                printf("\nENTER THE NEW DATA:");
                                                    printf("\nNEW MEETING PLACE:");
                                                    gets(VR.place);
                                                    break;


                                            case 4:
                                                printf("\nENTER THE NEW DATA:");
                                                    printf("\nDURATION:");
                                                    gets(VR.duration);
                                                    break;


                                            case 5:
                                                printf("ENTER THE NEW DATA:");
                                                    printf("\nNOTE:");
                                                    gets(VR.note);
                                                    break;


                                            case 6:
                                                printf("\nENTER THE NEW DATA:");
                                                     printf("\nNEW TIME:[hh:mm]:");
                                                     gets(VR.time);
                                                     printf("\nNEW MEETING PERSON:");
                                                     gets(VR.name);
                                                     printf("\nNEW MEETING PLACE:");
                                                     gets(VR.place);
                                                     printf("\nDURATION:");
                                                     gets(VR.duration);
                                                     printf("\nNOTE:");
                                                     gets(VR.note);
                                                     break;


                                            case 7:
                                                printf("\nPRESS ANY KEY TO GO BACK...\n");
                                                    getch();
                                                    return ;
                                                    break;


                                            default:
                                                printf("\nYour choice is wrong: try again [1 to 7]\n");

                                                     break;

                                        }


                                }
                                while(num<1||num>8);
                            fseek(fp2,-sizeof(VR),SEEK_CUR);
                            fwrite(&VR,sizeof(VR),1,fp2);
                            fseek(fp2,-sizeof(VR),SEEK_CUR);
                            fread(&VR,sizeof(VR),1,fp2);
                            user_choice=5;
                            break;

                        }

                    }

                    if(user_choice==5)

                    {

                    system("cls");
                    printf("\n\t\tEDITING COMPLETED...\n");
                    printf("THE NEW RECORD IS:\n");
                    printf("\nTIME: %s",VR.time);
                    printf("\nMEETING WITH: %s",VR.name);
                    printf("\nMEETING AT: %s",VR.place);
                    printf("\nDURATION: %s",VR.duration);
                    printf("\nNOTE: %s",VR.note);
                    fclose(fp2);
                    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(yes[y]or no[N] )");
                    scanf("%c",&user_choice);

                    count++;

                    }

                    else

                    {

                        printf("\nTHE RECORD DOES NOT EXIST::\n");
                        printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
                        scanf("%c",&user_choice);

                    }


            }
            while(user_choice=='Y'||user_choice=='y');
            fclose ( fp2 ) ;
            if(count==1)
            printf("\n%d FILE IS EDITED...\n",count);
            else if(count>1)
            printf("\n%d FILES ARE EDITED..\n",count);
            else
            printf("\nNO FILES EDITED...\n");
            printf("\tPRESS ENTER TO EXIT EDITING MENU.");
            getch();

}
