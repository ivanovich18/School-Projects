/* 
*  Project Title: BSCpE 1-G Daily Classroom Attendance and Schedule
*
*  Created by: Ivan G. Suralta and Aldrin A. Felices
*
*  Course and Section: BSCpE 1-G
*/ 

// preprocessor directives
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void main_menu();       // user-defined function to show main dashboard
void time_in();         // user-defined function prototype where the user can input name and id number (time-in)
void schedule_code();   // user-defined function to show class schedule
void time_clock();      // user-defined function to show time clock
void admin_page();      // user-defined function to show admin page where the saved file can be accessed
void exit_page();       // user-defined function to show exit page when the user wants to end the program
void attendance_list(); // user-defined function to print the saved file into the admin page

int main()
{ 	
	int id_num;        // global variables to store id number and name
	char name[30];

    FILE *save;

	system("color 02");
	
	main_menu(); // directs into the main page
	
	return 0;
}

void main_menu()
{
	int ans_1, ans_sched;
	
	do // loops if the user selected option is not 1, 2, 3 or 4
	{
		system("cls");
		
		printf("-------------------------------------------------------------------------------------------  "); time_clock();
	    printf("\n                     BSCpE 1-G Daily Classroom Attendance and Schedule\n");
	    printf("\n                                      [1] Student  \n");
	    printf("\n                                      [2] Schedule \n");
	    printf("\n                                      [3] Administrator \n");
	    printf("\n                                      [4] Exit \n\n");
	    printf("-------------------------------------------------------------------------------------------  ");
		printf("Enter: ");
	    scanf("%d", &ans_1);
	    
	} while (ans_1 != 1 && ans_1 != 2 && ans_1 != 3 && ans_1 != 4);
	
	
    if (ans_1 == 1)
    {   
	    time_in(); // proceeds into the time in page
	}
	    	
    if (ans_1 == 2)
    {
    	schedule_code(); // proceeds to schedule page
	}
	if (ans_1 == 3)
	{
		admin_page(); // proceeds to admin page where the user can access saved file
	}
	if (ans_1 == 4)
	{
		exit_page(); // shows the exit page and exits the program
	}
}

void time_in()
{
	int ans_2, ans_3, ctr = 0, id_num;
	char name[30];
    
    FILE *save;
    save = fopen("attendancesheet.txt", "w"); // create if no file exists, overwrites if one already exists
    
    do
    {
    	ctr = ctr + 1;
    	
    	system("cls");
    	
    	printf("-------------------------------------------------------------------------------------------  "); time_clock();
		printf("\n");
	    printf("   ||||||||||  ||||||||||  ||||       ||||  ||||||||||          ||||||||||   ||||     || \n");
		printf("       ||          ||      || ||     || ||  ||                      ||       || ||    || \n");
		printf("       ||          ||      ||  ||   ||  ||  ||||||||||    ||||      ||       ||  ||   || \n");
		printf("       ||          ||      ||   || ||   ||  ||                      ||       ||   ||  || \n");
		printf("       ||          ||      ||    |||    ||  ||                      ||       ||    || || \n");
		printf("       ||      ||||||||||  ||     |     ||  ||||||||||          ||||||||||   ||     |||| \n");
	    printf("\n-------------------------------------------------------------------------------------------  Enter ID number: ");
	   	scanf("%d", &id_num);
	    
	    printf("\n                                                                                             Enter first name: ");
	    scanf("%s", name);
		
		fprintf(save, "%s\n", name);   // stores string into the text file
		fprintf(save, "%d\n", id_num); // stores integer into the text file
		
		printf("[Time-in count]: %d", ctr);
	        
		printf("\n                                  Timed-in successfully!\n");
		printf("\n                                      Welcome, %s.\n\n", name); 
		printf("-------------------------------------------------------------------------------------------  ");
		
		Beep(523, 1500);
		
		printf("\n\n                                Do you want to add another?\n");
		printf("\n                                         [1] Yes\n");
		printf("\n                                         [2] No\n\n");
		
		printf("-------------------------------------------------------------------------------------------  ");
		printf("Enter: ");
		scanf("%d", &ans_2);
		
	} while (ans_2 == 1);
	
	attendance_list(); // stores the string and integer into the file	        

    fclose(save);          
	
    do // loops if the user selected option is not 1 or 2
	{
		system("cls");
		printf("-------------------------------------------------------------------------------------------  "); time_clock();
		printf("\n                              Do you want to check schedule?\n\n");
		printf("\n                                         [1] Yes\n");
		printf("\n                                         [2] No\n\n");
		printf("-------------------------------------------------------------------------------------------  ");
		printf("Enter: ");
		scanf("%d", &ans_3);	
		
	} while (ans_3 != 1 && ans_3 != 2);
	
	if(ans_3 == 1)
	{
		schedule_code(); // proceeds to schedule page
	}
	if(ans_3 == 2)
	{
		main_menu(); // goes back to main page
	}
}

void schedule_code()
{
    int ans_4, ans_sched;
    
    do // loops if the user selection option is not 1, 2, 3, 4, 5, 6 or 7
    {
        system("cls");
        printf("-------------------------------------------------------------------------------------------  "); time_clock();
        printf("\n");
        printf("   |||||||||  |||||||||  ||     ||  |||||||||  |||||||    ||     ||  ||         ||||||||| \n");
        printf("   ||         ||         ||     ||  ||         ||    ||   ||     ||  ||         ||        \n");
        printf("   |||||||||  ||         |||||||||  |||||||||  ||     ||  ||     ||  ||         ||||||||| \n");
        printf("          ||  ||         ||     ||  ||         ||     ||  ||     ||  ||         ||        \n");
        printf("          ||  ||         ||     ||  ||         ||    ||   ||     ||  ||         ||        \n");
        printf("   |||||||||  |||||||||  ||     ||  |||||||||  |||||||    |||||||||  |||||||||  |||||||||\n\n");
        printf("-------------------------------------------------------------------------------------------  ");
        printf("\n\n                                BSCpE 1-G First Semester\n");
        printf("\n                                      [1] Monday   \n");
        printf("\n                                      [2] Tuesday  \n");
        printf("\n                                      [3] Wednesday\n");
        printf("\n                                      [4] Thursday \n");
        printf("\n                                      [5] Friday   \n");
        printf("\n                                      [6] Saturday \n");
        printf("\n                                      [7] Sunday \n\n");
        printf("-------------------------------------------------------------------------------------------  ");
        printf("Enter: ");
        scanf("%d", &ans_sched);
    
    } while (ans_sched != 1 && ans_sched != 2 && ans_sched != 3 && ans_sched != 4 && ans_sched != 5 && ans_sched != 6 && ans_sched != 7);
    
    if(ans_sched == 1)
    {
        printf("\n                                       Monday\n\n");
        printf("Subject                       Description                             Time\n\n");
        printf("GEC-MMW                       Mathematics in Modern World             7:00 am - 8:00 am\n");
        printf("EMATH 111                     Calculus 1                              8:00 am - 9:00 am\n");
        printf("CPE-PC 112                    Programming Logic and Design            9:00 am - 12:00 pm\n");
        printf("ECHEM                         Chemistry for Engineers (LEC)           2:30 pm - 4:00 pm\n");
    }
    if(ans_sched == 2)
    {
        printf("\n                                       Tuesday\n\n");
        printf("Subject                       Description                             Time\n\n");
        printf("EMATH 111                     Calculus 1                              8:00 am - 9:00 am\n");
        printf("ECHEM                         Chemistry for Engineers (LEC)           2:30 pm - 4:00 pm\n");
    }
    if(ans_sched == 3)
    {
        printf("\n                                       Wednesday\n\n");
        printf("Subject                       Description                             Time\n\n");
        printf("EMATH 111                     Calculus 1                              8:00 am - 9:00 am\n");
        printf("GEC-MMW                       Mathematics in Modern World             7:00 am - 8:00 am\n");
        printf("CPE-PC 112                    Programming Logic and Design            9:00 am - 12:00 pm\n");
        printf("PE 1                          Physical Education 1                    2:00 pm - 4:00 pm\n");
    }
    if(ans_sched == 4)
    {
        printf("\n                                        Thursday\n\n");
        printf("Subject                       Description                             Time\n\n");
        printf("GEC-MMW                       Mathematics in Modern World             7:00 am - 8:00 am\n");
        printf("EMATH 111                     Calculus 1                              8:00 am - 9:00 am\n");
        printf("ECHEML                        Chemistry for Engineers (LAB)           1:00 pm - 4:00 pm\n");
    }
    if(ans_sched == 5)
    {
        printf("\n                                        Friday\n\n");
        printf("Subject                       Description                             Time\n\n");
        printf("CPE-PC 111                    Computer Engineering as Discipline      7:00 am - 8:00 am\n");
        printf("EMATH 111                     Calculus 1                              8:00 am - 9:00 am\n");
        printf("GEC-RPH                       Readings in Philippine History          9:00 am - 12:00 pm\n");
        printf("BES-CAD                       Computer-Aided Drafting                 1:00 pm - 4:00 pm\n");
    }
    if(ans_sched == 6)
    {
        printf("\n                                       Saturday\n\n");
        printf("\n                                      No Class...\n");
    }
    if(ans_sched == 7)
    {
        printf("\n                                       Sunday\n\n");
        printf("Subject                       Description                             Time\n");
        printf("NSTP 1                        National Service Training Program       8:00 am - 12:00 pm\n");
    }
   
    do // loops if the user selected option is not 1 or 2
    {
    	printf("\n\n                           Do you want to check other days?\n");
        printf("\n                                       [1] Yes\n");
        printf("\n                                       [2] No\n\n");
        printf("-------------------------------------------------------------------------------------------  ");
        printf("Enter: ");
        scanf("%d", &ans_4);

	} while (ans_4 != 1 && ans_4 != 2);
    
	        if(ans_4 == 1)
	        {
	        	schedule_code(ans_sched); // proceeds into schedule page
			}
			if(ans_4 == 2)
			{
				main_menu(); // proceeds into main page
			}
}

void admin_page()
{
	int ans_5, ans_6, i, id_num;     
	int username, password;
    char name[30];
    
    	system("cls");
		    
    	printf("-------------------------------------------------------------------------------------------  "); time_clock();
    	printf("\n\n");
		printf("                ||||     ||||||||    ||||       ||||  ||||||||||  ||||     ||            \n");
		printf("              ||    ||   ||     ||   || ||     || ||      ||      || ||    ||            \n");
		printf("             ||      ||  ||      ||  ||  ||   ||  ||      ||      ||  ||   ||            \n");
		printf("             ||||||||||  ||      ||  ||   || ||   ||      ||      ||   ||  ||            \n");
		printf("             ||      ||  ||     ||   ||    |||    ||      ||      ||    || ||            \n");
		printf("             ||      ||  |||||||     ||     |     ||  ||||||||||  ||     ||||          \n\n");
		printf("-------------------------------------------------------------------------------------------  Enter username: ");

		scanf("%d", &username);
		printf("\n");
		printf("                                                                                             Enter password: ");
		scanf("%d", &password);

    if (username == 12345 && password == 12345) // if user inputs correct username and password, it proceeds
    {
    	FILE *save;
    	save = fopen("attendancesheet.txt", "r"); // searches user saved file, returns null if not found
    	
    	printf("\n                                    Login Successful!\n\n                                ");
    	if(save == NULL)
    	{
    		printf("\n                                     Attendance List\n                               ");
    		printf("\n");
    		printf("                                 "); time_clock();
    		printf("\n                                    No record found...  \n                           ");
			
			Beep(523, 1500);
		}
		else // reads user saved file if found, and then prints
		{
    	
			printf("\n                                     Attendance List\n                               ");
			printf("\n");
			printf("                                 "); time_clock();
			
			attendance_list(); // reads the string and integer into the file
			
			Beep(523, 1500);
		}
		
 		do // loops if the user selected option is not 1 or 2
 		{
 			printf("-------------------------------------------------------------------------------------------  ");
    		printf("\n\n                                  Return to main menu?\n");
			printf("\n                                        [1] Yes\n");
	    	printf("\n                                        [2] No\n\n");
	    	printf("-------------------------------------------------------------------------------------------  ");
	    	printf("Enter: ");
	    	scanf("%d", &ans_5);
		} while (ans_5 != 1 && ans_5 != 2);
    	
	    
	    if(ans_5 == 1)
	    {
	    	main_menu(); // prooceds into main page
		}
	    if(ans_5 == 2)
	    {	
	    	exit_page(); // proceeds into exit page and exits the program
		}
	}
	else // if user inputs wrong username and password, it is asked to try again or not
	{
		do // loops if the user selected option is not 1 or 2
		{	
            printf("\n[HINT] username: 12345, password: 12345");
			printf("\n\n                            Incorrect username or password!\n");
			printf("\n                                       Try again?\n");
			printf("\n                                        [1] Yes\n");
	        printf("\n                                        [2] No\n\n");
	        printf("-------------------------------------------------------------------------------------------  ");
	        printf("Enter: ");
	        scanf("%d", &ans_6);
	        
	        if(ans_6 == 1)
	        {
	        	admin_page(); // backs into admin login page
			}
			if (ans_6 == 2)
			{
				main_menu(); // proceeds into main page
			}
		} while (ans_6 != 1 && ans_6 != 2);
	}
}

void time_clock()
{
    time_t t;
    time(&t);

    printf("%s", ctime(&t));
}
void exit_page()
{			
		system("cls");
		
		printf("-------------------------------------------------------------------------------------------  "); time_clock();
    	printf("\n\n");
		printf("     |||||||||   ||||||||    ||||||||||  ||||||||    ||||||||||  ||||||||||  ||||||||||       \n");
		printf("     ||          ||      ||  ||          ||     ||       ||          ||      ||               \n");
		printf("     ||          ||||||||    ||||||||||  ||      ||      ||          ||      ||||||||||       \n");
		printf("     ||          || |||      ||          ||      ||      ||          ||              ||       \n");
		printf("     ||          ||   |||    ||          ||     ||       ||          ||              ||       \n");
		printf("     |||||||||   ||     |||  ||||||||||  ||||||||    ||||||||||      ||      ||||||||||     \n\n");
		printf("-------------------------------------------------------------------------------------------"     );
		printf("\n\n           This is made with collaboration by Ivan Suralta and Aldrin Felices             \n");
		printf("\n                                      Thank you!\n\n"                                          );
		printf("-------------------------------------------------------------------------------------------"     );
		
		Beep(523, 1500);
}

void attendance_list()
{
	char name[20];
	FILE *save;
    save = fopen("attendancesheet.txt", "r");
	
	while(fscanf(save, "%s\n", name) != EOF) // loops and prints the saved file
    {
    	printf("                                          \n%s\n\n", name);
    }

    fclose(save);
}