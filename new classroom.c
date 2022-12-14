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
			printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[j].Name,stud[j].RollNo,stud[j].Course);		//Print student details
			break;
		}
		else{
			printf("Name not found...\n");		//Input name not found
		}
		
	}
	return 0;
	
}

int ByRoll(int r){			//Function for searching student by Roll Number
		int j;
	
	
	for(j=0;j<num;j++){
		if (r==stud[j].RollNo){		//comparing roll number from parameter with the roll number in each position in the array
			printf ("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[j].Name,stud[j].RollNo,stud[j].Course);		//Print student details
			break;
		}
		else{
				printf("Roll Number not found...\n");		//Input Roll number not found
		}
		
	}
	return 0;
}

int ByCourse(char *c){		//Function for searching student by Course

	int j;int k=0;
	
	
	for(j=0;j<num;j++){
		if (strcmp(c,stud[j].Course)==0){		//comparing course from parameter with the course in each position in the array
			printf("Student Name: %s | Roll Number: %d | Course: %s | \n",stud[j].Name,stud[j].RollNo,stud[j].Course);
			k++;
		}
	}
	if(k==0){
		printf("No Students found...\n");
		}
		return 0;
	
}



int main(){
	
	int i,f=0,rn;
	char x[50],c[50],saveFile;
	FILE *fl;
	
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
   	
   	
   	
	//Menu For iterative searching of students using different attributes (name, course , roll number)
	
	do{
		printf("\nType the numbers associated to the function to perform: \n1:Search By Roll Number \n2:Search By Name \n3:Search By Course\n0:Exit\n");
		scanf("Enter number: %d",&f);
	switch (f){
		case 1:
			printf("Enter the Roll Number to search: ");		//Input Roll Number to search
   			scanf("%d",&rn);
   			ByRoll(rn);			//Output function
   			
   			printf("\nDo you want to save into file? Y/N : ");		//saving the result into txt file
   			scanf("%c",&saveFile);
   			if((saveFile=='Y')||(saveFile=='y')){
   				fl=fopen("/home/acer/digvijay/output.txt","w");		//creating writable file in user directory
   				if(fl==NULL){
   					printf("Error in creating file\n");
   					exit(1);
				   }
				   fprintf(fl,ByRoll(rn));
				   fclose(fl);
			   }
	   break;
	   
	   
	   case 2:
	   		printf("Enter the name to search: ");		//Input name to search
   			scanf("%s",&x);
   			ByName(x);		//output function
   			
   			printf("\nDo you want to save into file? Y/N : ");		//saving the result into txt file
   			scanf("%c",&saveFile);
   			if((saveFile=='Y')||(saveFile=='y')){
   				fl=fopen("/home/acer/digvijay/output.txt","w");		//creating writable file in user directory
   				if(fl==NULL){
   					printf("Error in creating file\n");
   					exit(1);
				   }
				   fprintf(fl,ByName(x));
				   fclose(fl);
   				
			   }
	   break;
	   
	   
	   case 3:
	   	printf("Enter the Course name to search: ");		//Input name to search
   		scanf("%s",&c);
   		ByCourse(c);		//output function
   		
   		printf("\nDo you want to save into file? Y/N : ");		//saving the result into txt file
   			scanf("%c",&saveFile);
   			if((saveFile=='Y')||(saveFile=='y')){
   				fl=fopen("/home/acer/digvijay/output.txt","w");		//creating writable file in user directory
   				if(fl==NULL){
   					printf("Error in creating file\n");
   					exit(1);
				   }
				   fprintf(fl,ByCourse(c));
				   fclose(fl);
			   }
   		break;
	   
	    default:
	   			printf("\nThank you!\n");
	   	break;
		}
	
	}while(f!=0);
   		 		
return 0;	
}
	
	

