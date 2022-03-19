#include <stdio.h>

#include<time.h>

#include<stdlib.h>

#include<windows.h>

#include<string.h>

struct patient_record{

                int id;

                char name[15];

                char address[20];

                char gender;

                char disease[100];

                unsigned short age;

                char consolt_docter[15];

                int admitted_date[3];

                float dr_fee;

                float reg_fee;

                char g_name[15];

                char g_phone_no[17];

                int Isedited;

                char next_follow_up[100];

                int hospital_visited_counted;

                char prescribed_medcine[100];

}p;

void options();

int validateGen(char gen)

{

                if(gen >= 65 && gen <= 90 || gen >= 97 && gen <=122)

                {

                                if(gen > 90)

                                gen=gen-32;

                               

                                if(gen == 'O' || gen == 'F' || gen == 'M'  )

                                return 0;

                                else

                                {

                                                printf("\n\t\t Invalid gender");

                                                }             

                }

                else

                {

                                printf("\n\t\t Non-Alphabetic charactor found");

                                return 1;

                }

}

int date[3];

void Title(){

                printf("\n_________________________________________MINAKSHI CLINIC______________________________________");

                printf("\n\t\t\t\t\t Biratmod, Jhapa\n");

                printf("\t**************************************************************************");

               

}

void splashScr()

{

                Title();

                printf("\n\n\n\n\n\n\n\n\n\n\n \t\t Press Anykey to get started___");

                getch();

                system("cls");   

}

void delay(int milisec)

{

    //

   

  

    // Storing start time

    clock_t start_time = clock();

 

    // looping till required time is not achieved

    while (clock() < start_time + milisec)

        ;

}

int validatename(char name[])

{

                int i,len=strlen(name),counter;

                if(len >= 3)

                {

                                for (i=0; i<len; i++)

                                {

                                                if(name[i] >= 'A' && name[i] <= 'Z' || name[i]==32){

                                                                counter++;

                                                }

                                                else

                                                break;

                                }

                                if(len==counter)

                                {

                                                return 0;

                                }

                                else

                                {

                                                printf("\n\t\t Invalid name");

                                                return -1;

                                               

                                }

                               

                }

                printf("\n\t\t Too short Name");

                return 1;

}

 

void auth()

{

                char username[10],pwd[16];

                uname:

                system("cls");

                Title();

// SYSTEMTIME t; // Declare SYSTEMTIME struct

//

//    GetLocalTime(&t); // Fill out the struct so that it can be used

//

////     Use GetSystemTime(&t) to get UTC time

//

//    printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute:%d, Second: %d, Millisecond: %d", t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds); // Return year, month, day, hour, minute, second and millisecond in that order

 

               

                printf("\n\n\t\t Enter Your Username.. ");

                if(strcmp(gets(username),"admin")!=0)

                {

                                printf("\t\t Err: Invalid Username");

                                delay(600);

                                goto uname;

                                               

                }

                pwD:

                                system("cls");

                                Title();

                                printf("\n\n\t\t Username:%s",username);

                                printf("\n\n\t\t Enter Password.. ");

                                if(strcmp(gets(pwd),"pass")!=0)

                                {

                                                printf("\n\t\t Err: Invalid Password");

                                               

                                                delay(600);

                                                system("cls");

                                                Title();

                                                goto pwD;

                                }

               

                printf("\n\t\t You've Logged in");

               

                               

               

               

}

void updaterecord()

{

                system("cls");

                Title();

               

                int id,flag;

               

                FILE *Fread, *Ftemp;

                printf("\n\t-------------------UPDATE RECORDS----------------");

                printf("\n\t\tEnter ID to Update");

                scanf("%d",&id);

                fflush(stdin);

                Fread=fopen("rec.dat","r");

                Ftemp=fopen("rec_temp.dat","a");

 

while(fread(&p, sizeof(p),1,Fread))

                {

                                if(id== p.id)

                                {

               

 

               

               

               

                printf("\n\t\t ID == %u",p.id);

               

 

               

                name:

                                printf("\n\n\n\t\t Enter Patient's Name: ");

                                fflush(stdin);

                                strupr(gets(p.name));

                                if(validatename(p.name)!=0)

                                goto name;

               

                gen:

                                printf("\n\t\t Enter Gender: ");

                                scanf("%c",&p.gender);

                                fflush(stdin);

                                if(validateGen(p.gender)!=0)

                                {

                                                goto gen;

                                }

                                               

                address:

                                printf("\n\t\t Enter Patient's Address: ");

                                fflush(stdin);

                                gets(p.address);

                                fflush(stdin);

                                if(strlen(p.address )< 1)

                                {

                                                printf("\n\t\t Invalid input");

                                                goto address;

                                }

                               

                age:

                                printf("\n\t\t Enter Patient's Age: ");

                                fflush(stdin);

                                scanf("%u",&p.age);

                                fflush(stdin);

                                if(p.age < 1 && p.age> 100)

                                {

                                                printf("\n\t\t Invalid age:");

                                                goto age;

                                               

                                }

                disease:

                                fflush(stdin);

                                printf("\n\t\t Admittted for | Complications | Problems: ");

                                gets(p.disease);

                                if(strlen(p.disease)<1)

                                {

                                                printf("\n\t\t invalid input");

                                                goto disease;

                                }

               

               

                g_name:

                                printf("\n\t\t Enter Patient's Guardian's | Parent's Name: ");

                                fflush(stdin);

                                strupr(gets(p.g_name));

                                if(validatename(p.g_name) != 0)

                                goto g_name;

                g_contact:

                                printf("\n\t\t Enter Patient's Guardian's | Parent's Number: ");

                                fflush(stdin);

                                gets(p.g_phone_no);

                                if(validateNum(p.g_phone_no)!=0)

                                goto g_contact;

                                printf("\n\n\n\t Basic Details are ready, Now medical and fees\n");

                               

                doct_:

                                printf("\n\t\tEnter the name of consulting doctor: Dr. ");

                                fflush(stdin);

                                strupr(gets(p.consolt_docter));

                                if(validatename(p.consolt_docter)!=0)

                                goto doct_;

                doct_fee:

                                printf("\n\t\tEnter Fee of Dr.%s  ",p.consolt_docter);

                                scanf("%f",&p.dr_fee);

                               

                                fflush(stdin);

                                if(p.dr_fee < 1.0)

                                {

                                                printf("\n\t\t Fees cannot be less than 1");

                                                goto doct_fee;

                                }

               

                                printf("\n\t\t Enter Next Follow-Up date[2021/02/01] format ");

                                fflush(stdin);

                                gets(p.next_follow_up);

                                printf("\n\t\t Prescribed medicine (,) separates name.. ");

                                fflush(stdin);

                                gets(p.prescribed_medcine);

                                p.reg_fee=500.00;

                                getch();

                                p.Isedited=1;

                                printf("\n\t\t");

                                printstar();

                                fwrite(&p, sizeof(p),1,Ftemp);

                                               

                                }

                                fwrite(&p, sizeof(p),1,Ftemp);

                               

                }

               

               

               

                fclose(Fread);

                fclose(Ftemp);

               

                remove("rec.dat");

                rename("rec_temp.dat","rec.dat");

               

               

               

               

               

               

}

 

void getdate()

{

                SYSTEMTIME t; // Declare SYSTEMTIME struct

 

   GetLocalTime(&t); // Fill out the struct so that it can be used

//

////     Use GetSystemTime(&t) to get UTC time

//

    // Return year, month, day, hour, minute, second and millisecond in that order

                date[0]==t.wYear;

                date[1]==t.wMonth;

                date[2]==t.wDay;

}

void exiit()

{

                system("cls");

                Title();

                printf("\n\n\n\t\t Program is terminating in 2 seconds");

                delay(1800);

                system("cls");

                Title();

                printf("\n\n\n\t\t Successfully terminated program");

                exit(0);

}

 

void searchrecord()

{

                system("cls");

                Title();

                int _temp_id,flag=0;

                FILE *Fread;

                Fread=fopen("rec.dat","r");

                system("cls");

                Title();

                printf("\n\t YOURE ABOUT TO SEARCH RECORD");

                printf("\n\t\t Enter ID to search");

                scanf("%u",&_temp_id);

                while(fread(&p, sizeof(p),1,Fread))

                {

                                if(_temp_id == p.id)

                                {

                                               

                                printf("\n\t_______________________________________________________________\n");

                                printf("\n\t\tPatient Name:           %s",p.name);

                                printf("\n\t\tPatient Gender:                       %c ",p.gender);

                                printf("\n\t\tPatient Age:               %u",p.age);

                                printf("\n\t\tPatient Address:      %s",p.address);

                                printf("\n\t\tPatienr Problems:   %s",p.disease);

                                printf("\n\t\tParent|Guardian Name:     %s",p.g_name);

                                printf("\n\t\tContact No of Guardian:   %s",p.g_phone_no);

                                printf("\n\t\tRegistration Fee:         %f",p.reg_fee);

                                printf("\n\t\tConsulting DOctor's Name: %s",p.consolt_docter);

                                printf("\n\t\t%s Fee                         %f",p.consolt_docter,p.dr_fee);

                                printf("\n\t\tNext follow-up                          %s",p.next_follow_up);

                                printf("\n\t\tTotal Follow up count             %u\n\t\t.. ",p.hospital_visited_counted);          

                                printf("\n\t_______________________________________________________________\n");

                                flag++;

                                break;

                                }

                               

                }

                fclose(Fread);

               

                if(flag ==1)

                {

                                printf("\n\t\t Record found and displayed..");

                               

                }

                printf("\n\t\t Record not found   ");

                system("pause");

                options();

}

int printstar()

{

               

                printf("\n\t\t***********************************\n\n");

               

}

void deleterecords()

{

                system("cls");

                Title();

                int id,flag=0;

                FILE *Fread, *Fwrite, *Ftemp;

                system("cls");

                Title();

               

                printf("\n\t------------- DELETE RECORD-------------");

                printf("\n\t\t Enter ID to Delete records");

                scanf("%1u",&id);

                Fread=fopen("rec.dat","r");

                Ftemp =fopen("rec_t.dat","w");

               

                while(fread(&p,sizeof(p),1,Fread))

                {

                                if(id != p.id)

                                {

                                                fwrite(&p, sizeof(p),1,Ftemp);

                                }

                                else

                                flag++;

                }

               

                fclose(Fread);

                fclose(Ftemp);

               

                remove("rec.dat");

                rename("rec_t.dat","rec.dat");

                if(flag ==1)

                {

                                printf("\n\t\t Record deleted");

                                options();

                               

                }

                printf("\n\t\t Record not found");

                options();

}

 

int validateID()

{

                FILE *fp;

                fp=fopen("rec.dat","r");

                int i,id=0;

                while(fread(&p, sizeof(p),1,fp))

                {

                                if(id < p.id)

                                {

                                id=          p.id;

                                }

                }

                fclose(fp);

                return id+1;

}

int validateNum(char number [])

{

int           iscountrycode=0,i,counter=0;

                if(number[0] == '+')

                {

                                if(strlen(number) >= 13 &&strlen(number) <= 18 )

                                {

                                                for(i=0; i<strlen(number); i++)

                                                {

                                                                if((number[i] >= '0' && number [i] <= '9') || number[i] == '-' || number[i] == '+'  )

                                                                {

                                                                                counter++;

                                                                }

                                                                else

                                                                break;

                                                               

                                                }

                                               

                                                if(counter == strlen(number))

                                                {

                                                                return 0;

                                                }

                                                else

                                                {

                                                                printf("\n\t\tInvalid Character Found for Number");

                                                                return -1;

                                                }

                                }

                                printf("\n\t\t Too short Number ");

                                return 1;

                }

                printf("\n\t\t Country Code not found");

}

 

void addrecords()

{

                getdate();

                FILE *fp;

                fp=fopen("rec.dat","a");

               

//            getdate();

               

                system("cls");

                Title();

                printf("\n\n\t\t\t_________________YOU'RE ADDING RECORDS___________________");

                printf("\n\n\n\n\n\n\t   Basic Details about Patient:");

                printf("\n_________________________________________________________________");

               

                p.id = validateID();

                printf("\n\t\t ID == %u",p.id);

               

 

               

                name:

                                printf("\n\n\n\t\t Enter Patient's Name: ");

                                fflush(stdin);

                                strupr(gets(p.name));

                                if(validatename(p.name)!=0)

                                goto name;

               

                gen:

                                printf("\n\t\t Enter Gender: ");

                                scanf("%c",&p.gender);

                                fflush(stdin);

                                if(validateGen(p.gender)!=0)

                                {

                                                goto gen;

                                }

                                               

                address:

                                printf("\n\t\t Enter Patient's Address: ");

                                fflush(stdin);

                                gets(p.address);

                                fflush(stdin);

                                if(strlen(p.address )< 1)

                                {

                                                printf("\n\t\t Invalid input");

                                                goto address;

                                }

                               

                age:

                                printf("\n\t\t Enter Patient's Age: ");

                                fflush(stdin);

                                scanf("%u",&p.age);

                                fflush(stdin);

                                if(p.age < 1 && p.age> 100)

                                {

                                                printf("\n\t\t Invalid age:");

                                                goto age;

                                               

                                }

                disease:

                                fflush(stdin);

                                printf("\n\t\t Admittted for | Complications | Problems: ");

                                gets(p.disease);

                                if(strlen(p.disease)<1)

                                {

                                                printf("\n\t\t invalid input");

                                                goto disease;

                                }

               

               

                g_name:

                                printf("\n\t\t Enter Patient's Guardian's | Parent's Name: ");

                                fflush(stdin);

                                strupr(gets(p.g_name));

                                if(validatename(p.g_name) != 0)

                                goto g_name;

                g_contact:

                                printf("\n\t\t Enter Patient's Guardian's | Parent's Number: ");

                                fflush(stdin);

                                gets(p.g_phone_no);

                                if(validateNum(p.g_phone_no)!=0)

                                goto g_contact;

                                printf("\n\n\n\t Basic Details are ready, Now medical and fees\n");

                                printf("\n\t\t Registration fee 500 is added\n");

                doct_:

                                printf("\n\t\tEnter the name of consulting doctor: Dr. ");

                                fflush(stdin);

                                strupr(gets(p.consolt_docter));

                                if(validatename(p.consolt_docter)!=0)

                                goto doct_;

                doct_fee:

                                printf("\n\t\tEnter Fee of Dr.%s  ",p.consolt_docter);

                                scanf("%f",&p.dr_fee);

                               

                                fflush(stdin);

                                if(p.dr_fee < 1.0)

                                {

                                                printf("\n\t\t Fees cannot be less than 1");

                                                goto doct_fee;

                                }

               

                                printf("\n\t\t Enter Next Follow-Up date[2021/02/01] format ");

                                fflush(stdin);

                                gets(p.next_follow_up);

                                printf("\n\t\t Prescribed medicine (,) separates name.. ");

                                fflush(stdin);

                                gets(p.prescribed_medcine);

                                p.Isedited=0;

                                printf("\n\t\t");

                                printstar();

                               

                                printf("\n\t\t\t RECORD ADDED");

                                delay(600);

                                fwrite(&p, sizeof(p),1,fp);

                                fclose(fp);

                               

                               

                               

                               

                               

               

               

                options();

               

}

void viewrecords()

{

                system("cls");

                Title();

                printf("\n\n\n\t\t\t YOU'RE VIEWING RECORD\n");

                printf("\n\t\t***********************************");

                FILE *FileRead;

                FileRead = fopen("rec.dat","r");

                while(fread(&p ,sizeof(p),1,FileRead))

                {

                                printf("\n\t_______________________________________________________________\n");

                                printf("\n\t\tPatient Name:           %s",p.name);

                                printf("\n\t\tPatient Gender:                       %c ",p.gender);

                                printf("\n\t\tPatient Age:               %u",p.age);

                                printf("\n\t\tPatient Address:      %s",p.address);

                                printf("\n\t\tPatienr Problems:   %s",p.disease);

                                printf("\n\t\tParent|Guardian Name:     %s",p.g_name);

                                printf("\n\t\tContact No of Guardian:   %s",p.g_phone_no);

                                printf("\n\t\tRegistration Fee:         %f",p.reg_fee);

                                printf("\n\t\tConsulting DOctor's Name: %s",p.consolt_docter);

                                printf("\n\t\t%s Fee                         %f",p.consolt_docter,p.dr_fee);

                                printf("\n\t\tNext follow-up                          %s",p.next_follow_up);

                                printf("\n\t\tTotal Follow up count             %u\n\t\t.. ",p.hospital_visited_counted);

                                getch();

                }

                printf("\n\t_______________________________________________________________\n");

                printf("\n\t\t END OF RECORDS");

                system("pause");

               

                fclose(FileRead);

                options();

}

 

 

 

void  options(){

                system("cls");

                Title();

                char ch;

                top:

                printf("\n\n\t\t [1], ADD RECORD");

                printf("\n____________________________________________");

                printf("\n\n\t\t [2], VIEW  RECORD");

                printf("\n____________________________________________");

                printf("\n\n\t\t [3], UPDATE RECORD");

                printf("\n____________________________________________");

                printf("\n\n\t\t [4], SEARCH RECORD");

                printf("\n____________________________________________");

                printf("\n\n\t\t [5], DELETE RECORD");

                printf("\n____________________________________________");

                printf("\n\n\t\t [6], EXIT");

                printf("\n____________________________________________");

               

                printf("\n\n\t Enter Your Selection: ");

                fflush(stdin);

                ch=getchar();

                fflush(stdin);

                switch(ch)

                {

                                case '1' : {

                                                addrecords();

                                                break;

                                }

                               

                                case '2' : {

                                                viewrecords();

                                                break;

                                }

                               

                                case '3' : {

                                                updaterecord();

                                                options();

                                                break;

                                }

                                case '4' : {

                                                searchrecord();

                                                break;

                                }

                                case '5' : {

                                                deleterecords();

                                                break;

                                }

                                case '6' : {

                                                exiit();

                                                break;

                                }

                               

                                default : {

                                                system("cls");

                                                Title();

                                                break;

                                }

                }

                options();

                               

               

               

                return;

}

 

int main(){

 

                splashScr();

                auth();

                options();

                return 0;

 

exiit();

                return 0;

}

