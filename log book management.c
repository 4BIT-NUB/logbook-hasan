#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>


int password();

void addrecord();

void viewrecord();

void deleterecord();




struct record

{

    char time[6];

    char name[30];

    char place[25];

    char duration[10];

    char note[500];

} ;


int main()

{

    int ch;

    printf("\n\n\t**********************************\n");

    printf("\t*   WELCOME TO YOUR LOG BOOK     *\n");

    printf("\t**********************************");


   while(1)


        {

                printf("\n\n\t\tMAIN MENU:");

                printf("\n\n\tADD RECORD\t[1]");

                printf("\n\tVIEW RECORD\t[2]");

                printf("\n\tDELETE RECORD\t[3]");

                printf("\n\tABOUT GROUP\t[4]");

                printf("\n\tEXIT\t\t[5]");

                printf("\n\n\tENTER YOUR CHOICE:");

                scanf("%d",&ch);


            switch(ch)

                    {

                            case 1:

                            addrecord();

                            break;


                            case 2:

                            viewrecord();

                            break;


                            case 3:

                            deleterecord();

                            break;


                            case 4:

                            printf("\n\n\t\t*ABOUT GROUP* \n\t_________________________________\n\tGroup Name:Robust Engineering\n\tProject Name:Log Book Management\n\tSemester: 2A\n\tGroup Member Name:Shakil Ahammed\n\t\t\t :Mst Sumaiya Khatun\n\t\t\t :Md Mostafijur Rahman\n\t\t\t :Md Hasan Ali\n\n\tNORTHERN UNIVERSITY_BANGLADESH");

                            getch();

                            break;



                            case 5:

                            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE BY:Hasan*shakil*sumaiya*mostafiz ");

                            getch();

                            exit(0);


                            default:

                            printf("\nYOU ENTERED WRONG CHOICE..");

                            printf("\nPRESS ANY KEY TO TRY AGAIN");

                            getch();

                            break;

                    }

                system("cls");

        }

            return 0;

}

void addrecord( )

{

                system("cls");

                FILE *fp ;

                char another = 'Y' ,time[10];

                struct record e ;

                char filename[15];

                int choice;

                printf("\n\n\t\t***************************\n");

                printf("\t\t* WELCOME TO THE ADD MENU *");

                printf("\n\t\t***************************\n\n");

                printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "ab+" ) ;

                if ( fp == NULL )

                {

                fp=fopen(filename,"wb+");

                if(fp==NULL)

                {

                    printf("\nSYSTEM ERROR...");

                    printf("\nPRESS ANY KEY TO EXIT");

                    getch();

                    return ;

                }

                }



                while ( another == 'Y'|| another=='y' )

                {

                    choice=0;

                    fflush(stdin);

                printf ( "\n\tENTER TIME:[hh:mm]:");

                scanf("%s",time);

                rewind(fp);

                while(fread(&e,sizeof(e),1,fp)==1)

                {

                    if(strcmp(e.time,time)==0)

                    {

                        printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                        choice=1;

                    }

                }

                    if(choice==0)

                    {

                        strcpy(e.time,time);

                        printf("\tENTER NAME:");

                        fflush(stdin);

                        gets(e.name);

                        fflush(stdin);

                        printf("\tENTER PLACE:");

                        gets(e.place);

                        fflush(stdin);

                        printf("\tENTER DURATION:");

                        gets(e.duration);

                        fflush(stdin);

                        printf("\tNOTE:");

                        gets(e.note);

                        fwrite ( &e, sizeof ( e ), 1, fp ) ;

                        printf("\nYOUR RECORD IS ADDED...\n");

                    }

                        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;

                        fflush ( stdin ) ;

                        another = getchar( ) ;

                }


                fclose ( fp ) ;

                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();

    }


void viewrecord( )

{

        FILE *fpte ;

        system("cls");

        struct record customer ;

        char time[6],choice,filename[14];

        int ch;

        printf("\n\n\t\t*******************************\n");

        printf("\t\t* HERE IS THE VIEWING MENU *");

        printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=1)

            {

                return ;

            }

        do

            {

                    printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");

                    fflush(stdin);

                    gets(filename);


                    fpte = fopen ( filename, "rb" ) ;

                    if ( fpte == NULL )

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

                            printf("\nTHE WHOLE RECORD FOR %s IS:",filename);

                         while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

                         {

                            printf("\n");

                            printf("\nTIME: %s",customer.time);

                            printf("\nMEETING WITH: %s",customer.name);

                            printf("\nMEETING AT: %s",customer.place);

                            printf("\nDURATION: %s",customer.duration);

                            printf("\nNOTE: %s",customer.note);

                            printf("\n");

                         }

                         break;


                    case 2:

                            fflush(stdin);

                            printf("\nENTER TIME:[hh:mm]:");

                            gets(time);

                            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )


                            {

                                if(strcmp(customer.time,time)==0)

                                {

                                    printf("\nYOUR RECORD IS:");

                                    printf("\nTIME: %s",customer.time);

                                    printf("\nMEETING WITH: %s",customer.name);

                                    printf("\nMEETING AT: %s",customer.place);

                                    printf("\nDUARATION: %s",customer.duration);

                                    printf("\nNOTE: %s",customer.note);

                                }

                            }

                            break;


                    default: printf("\nYOU TYPED SOMETHING ELSE...\n");

                             break;

                }
                /*hasan*/

               printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

               fflush(stdin);

            scanf("%c",&choice);

        }while(choice=='Y'||choice=='y');

            fclose ( fpte ) ;

            return ;

}

int password()

{

        char pass[15]={0},check[15]={0},ch;

        FILE *fpp;

        int i=0,j;

        printf("::FOR SECURITY PURPOSE::");

        printf("::ONLY ::");

        for(j=0;j<5;j++)

        {

                        i=0;

                        printf("\n\n\tPRESS ENTER :");

                        pass[0]=getch();

                        while(pass[i]!='\r')

                        {

                            if(pass[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                pass[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                pass[i]=getch();

                            }

                        }

                        pass[i]='\0';

                        fpp=fopen("SE","r");

                        if (fpp==NULL)

                        {

                            printf("\n\tReENTER\t:\n");

                            getch();

                            return 1;

                        }

                        else

                        i=0;

                        while(1)

                        {

                            ch=fgetc(fpp);

                            if(ch==EOF)

                            {

                                check[i]='\0';

                                break;

                            }

                            check[i]=ch-5;

                            i++;

                        }

                        if(strcmp(pass,check)==0)

                        {

                            printf("\n\n\tACCESS GRANTED...\n");

                            return 0;

                        }

                        else

                        {

                            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");

                        }

        }

        printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");

        getch();

        return 1;

}



void deleterecord( )

{

                system("cls");

                FILE *fp,*fptr ;

                struct record file ;

                char filename[15],another = 'Y' ,time[10];;

                int choice,check;

                printf("\n\n\t\t*************************\n");

                printf("\t\t* WELCOME TO DELETE MENU*");

                printf("\n\t\t*************************\n\n");

                check = password();

                    if(check==0)

                    {

                        return ;

                    }


                while ( another == 'Y' )

                {

                printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");

                printf("\n\n\t#DELETE WHOLE RECORD\t\t\t[1]");

                printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");


                do

                {

                        printf("\n\t\tENTER YOU CHOICE:");

                        scanf("%d",&choice);


                    switch(choice)

                        {

                            case 1:

                            printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "wb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nTHE FILE DOES NOT EXISTS");

                                printf("\nPRESS ANY KEY TO GO BACK.");

                                getch();

                                return ;

                            }

                            fclose(fp);

                            remove(filename);

                            printf("\nDELETED SUCCESFULLY...");

                            break;


                            case 2:

                            printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "rb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nTHE FILE DOES NOT EXISTS");

                                printf("\nPRESS ANY KEY TO GO BACK.");

                                getch();

                                return ;

                            }

                            fptr=fopen("temp","wb");

                            if(fptr==NULL)

                            {

                                printf("\nSYSTEM ERROR");

                                printf("\nPRESS ANY KEY TO GO BACK");

                                getch();

                                return ;

                            }

                            printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                            fflush(stdin);

                            gets(time);

                            while(fread(&file,sizeof(file),1,fp)==1)

                            {

                                if(strcmp(file.time,time)!=0)

                                fwrite(&file,sizeof(file),1,fptr);

                            }


                            fclose(fp);

                            fclose(fptr);

                            remove(filename);

                            rename("temp",filename);

                            printf("\nDELETED SUCCESFULLY...");

                            break;


                    default:

                            printf("\n\tYOU ENTERED WRONG CHOICE");

                            break;

                    }

                }while(choice<1||choice>2);



                    printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

                    fflush(stdin);

                    scanf("%c",&another);

                }

                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();

}

