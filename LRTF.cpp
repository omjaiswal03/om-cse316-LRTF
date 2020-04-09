#include <stdio.h>
struct student
{
    int StudentId;
    int TurnAroundTime;
    int FoodTakenTime;
    int WaitingTime; 

};

void accept(struct student list[], int p);
void display(struct student list[], int q);
void scheduling(struct student list[], int r);
void waitingTime(struct student list[], int s);
void turnAroundTime(struct student list[], int t);

int main()
{
    struct student data[20];
    int e;
    char f='e';
    do
	{
    printf("Enter the Number of Students wants to eat in mess: ");
    scanf("%d", &e);
    accept(data, e);
    scheduling(data, e);
    waitingTime(data,e);
    turnAroundTime(data,e);
    display(data, e);
    printf("Want to continue Please press 'yes':");
    scanf("%s",&f);
    }
	while(f=='yes');
    return 0;
} 

void accept(struct student list[80], int s)
{
    int i;
    for (i=0;i<s;i++)
    {
        printf("\n Enter data of Student %d",i+1);
        
        printf("\nEnter Student id :");
        scanf("%d", &list[i].StudentId);

        printf("Enter time taken for food (minutes):");
        scanf("%d",&list[i].FoodTakenTime);
    } 
}

void display(struct student list[80], int s)
{
    int TotalWatingTime=0,TotalTurnAroundTime=0;
    int i,AvgWaitingTime=0,AvgTurnAroundTime=0;

    printf("\n\n Output is:\n");
    printf("\n\t\t\t|---------------------------------------------------------------|");
    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|---------------------------------------------------------------|");    
    for (i=0;i<s;i++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[i].StudentId, list[i].FoodTakenTime,list[i].WaitingTime,list[i].TurnAroundTime);
        printf("\a\n\t\t\t|---------------------------------------------------------------|");
		TotalWatingTime= TotalWatingTime+list[i].WaitingTime;
		TotalTurnAroundTime= TotalTurnAroundTime+list[i].TurnAroundTime;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is:= %d",TotalWatingTime);
	printf("\n\t\t\tTotal Turn around Time is:= %d\n\n",TotalTurnAroundTime);
	printf("\n\n\t\t\tAverage Waiting Time is:= %d",TotalWatingTime/s);
	printf("\n\t\t\tAverage Turn around Time is:= %d\n\n",TotalTurnAroundTime/s);
}

void scheduling(struct student list[80],int s)
{
    intj,i;
    struct student temp;
    
    for (i=0;i<s-1;i++)
    {
        for (j=0;j<(s-1-i);j++)
        {
            if (list[j].FoodTakenTime<list[j+1].FoodTakenTime)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            } 
            else if(list[j].FoodTakenTime==list[j+1].FoodTakenTime)
            {
            	if(list[j].StudentId>list[j+1].StudentId)
            	{
            	temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
                }
			}
        }
    }
}


void waitingTime(struct student list[80], int n)
{
	int j,total;
    list[0].WaitingTime=0;
    for(j=1;j<n;j++)
    {
        list[j].WaitingTime=list[j-1].WaitingTime+list[j-1].FoodTakenTime;
    }
}


void turnAroundTime(struct student list[80], int n)
{
	int p,total;
    
    for(p=0;p<n;p++)
    {
        list[p].TurnAroundTime=list[p].WaitingTime+list[p].FoodTakenTime;
    }
} 

