#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define a 50				 //declaring max array size
int num;					 //var for user defined max size of class



struct student{				//defining the structure
	char Name[50];
	int RollNo;
	char Course[50];
	};

struct student stud[a];		//Declaring array of struct Student



int ByName(char *x){		//Function for searching student by Name

	int j;
	
	for(j=0;j<num;j++){
		if (strcmp(x,stud[j].Name)==0){		//comparing name from parameter with the name in each position in the array
			return j;							//returning the position at which name was found
			break;
		}
		else{
			return (num+1);				//return value greater than number of students when item not found
		}
		
	}
	
}

int ByRoll(int r){			//Function for searching student by Roll Number
		int j;
	
	
	for(j=0;j<num;j++){
		if (r==stud[j].RollNo){		//comparing roll number from parameter with the roll number in each position in the array
			return j;							//returning the position at which Roll number was found
			break;
		}
		else{
			return (num+1);		//return value greater than number of students when item not found
		}
		
	}
}

int ByCourse(char *c){		//Function for searching student by Course

	int j;
	
	
	for(j=0;j<num;j++){
		if (strcmp(c,stud[j].Course)==0){		//comparing course from parameter with the course in each position in the array
			return j;							//returning the position at which course was found
			break;
		}
		else{
			return (num+1);				//return value greater than number of students when item not found
		}
		
	}
	
}



int main(){
	
	int i,func=0,rn;
	char x[50],c[50];		
	
	
	printf("Enter the number of students in the class: ");
	scanf("%d",&num);
	

	
	printf("\nNumber of students in class: %d \n",num);
	
	
	for (i=0;i<num;i++){
		
		printf("\nEnter the Roll Number of student %d: \n",i+1);		//Input Student Roll Number
   		scanf(" %d", &stud[i].RollNo);
   		
   		printf("Enter the Name of student %d: \n",i+1);				//Input Student Name
   		scanf(" %s", &stud[i].Name);
   		
   		printf("Enter the Course of student %d: \n",i+1);			//Input Student Course
   		scanf(" %s", &stud[i].Course);
   	}
   	
   	
   	
	
	
	do{
		printf("\nType the numbers associated to the function to perform: \n1:Search By Roll Number \n2:Search By Name \n3:Search By Course\n0:Exit\n");
		scanf("Enter number: %d",&func);
	switch (func){
		case 1:
			printf("Enter the Roll Number to search: ");		//Input Roll Number to search
   			scanf("%d",&rn);
   	
   			if (ByRoll(rn)>num){
   			printf("Roll Number not found...\n");		//Input Roll number not found
	  		}
	   		else{
	   		printf("Roll number found!\n");
	   		printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByRoll(rn)].Name,stud[ByRoll(rn)].RollNo,stud[ByRoll(rn)].Course);		//Print student details
	  		 }
	   break;
	   
	   
	   case 2:
	   		printf("Enter the name to search: ");		//Input name to search
   			scanf("%s",&x);
   	
   			if (ByName(x)>num){
   			printf("Name not found...\n");		//Input name not found
	  		 }
	   		else{
	  		printf("Name found!\n");
	   		printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByName(x)].Name,stud[ByName(x)].RollNo,stud[ByName(x)].Course);		//Print student details
	   		}
	   break;
	   
	   
	   case 3:
	   	printf("Enter the Course name to search: ");		//Input name to search
   		scanf("%s",&c);
   	
   			if (ByCourse(c)>num){
   					printf("Name not found...\n");		//Input name not found
	  			 }
	   		else{
	   			printf("Name found!\n");
	   			printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByCourse(c)].Name,stud[ByCourse(c)].RollNo,stud[ByCourse(c)].Course);		//Print student details
	   			}
	   break;
	   
	    default:
	   			printf("\nThank you!\n");
	   	break;
	   	
	   	
	   	
			
	}
	
}while(func!=0);
   	
	   
	   
/*	   	
 	char x[50];	
   	printf("Enter the name to search: ");		//Input name to search
   	scanf("%s",&x);
   	
   	if (ByName(x)>num){
   		printf("Name not found...\n");		//Input name not found
	   }
	   else{
	   	printf("Name found!\n");
	   	printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByName(x)].Name,stud[ByName(x)].RollNo,stud[ByName(x)].Course);		//Print student details
	   }
*/	
	   
	   
	   
	   
	   
/*	int rn;
	printf("Enter the Roll Number to search: ");		//Input Roll Number to search
   	scanf("%d",&rn);
   	
   	if (ByRoll(rn)>num){
   		printf("Roll Number not found...\n");		//Input Roll number not found
	   }
	   else{
	   	printf("Roll number found!\n");
	   	printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByRoll(rn)].Name,stud[ByRoll(rn)].RollNo,stud[ByRoll(rn)].Course);		//Print student details
	   }
*/	   
	   
	   
/*	char c[50];	
   	printf("Enter the Course name to search: ");		//Input name to search
   	scanf("%s",&c);
   	
   	if (ByCourse(c)>num){
   		printf("Name not found...\n");		//Input name not found
	   }
	   else{
	   	printf("Name found!\n");
	   	printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[ByCourse(c)].Name,stud[ByCourse(c)].RollNo,stud[ByCourse(c)].Course);		//Print student details
	   }
  */ 	
   	
   		
   	return 0;	
}
	
	

