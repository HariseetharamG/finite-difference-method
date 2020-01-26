//*************************************************************************************************************************************
//**************************************Computer Assignment 1 of Computational Fluid Dynamics******************************************
//***************************************** done by GUNDUBOINA HARISEETHARAM (193010009) **********************************************
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
	//FILE *fptr;
	int i,j;
	float u[100][100];
	float v;
	float dx=0.01;
	char operator;
	int number;
	//fptr=fopen("output.dat","w+");

	//if(fptr==NULL)
	//printf("\n File does not exist\n");
	//return;
	//printf("\n\n**Four initial conditions are there to solve the ''linear advective equation'' by this code**");
	//printf("\n\n Enter '  A  ' for the Discontinuous initial solution \n\n Enter '  B  'for Initial solution having two periods \n\n Enter '  C  			' for Initial solution having four periods \n\n Enter '  D  ' for Initial solution having six periods");
		printf("\n\n Enter the initial condition you want to work :");
	//scanf("%c",&operator);
	printf("\n\nEnter the value of Courant Friedrichs Lewy (CFL) number you want to work (0.5,1,1.5) :");
	scanf("%f",&v);
	//switch(operator)

	//case 'A':
	{
{
printf("\n\n The value of Courant Friedrichs Lewy (CFL) number v=%f\n\n",v);
printf("\n\n Discontinuous initial solution\n\n");	
}
for(i=0;i<=100;i=i+1)
{
	if(i*dx<0.2)
		u[i][0]=1;
	else
		u[i][0]=0;
}

for(i=0;i<=100;i=i+1)
{
	printf("\n%f %f  %d",i*dx,  u[i][0],  j);
}
{
getchar();
}
	//printf("\n\n*** Six schemes are the to Solve the advective equation ***");
	//printf("\n\n Enter '1' for to run Forward time Forward space scheme \n\nEnter '2' for to run Forward time central space scheme \n\nEnter '3' 		for to run Forward time backward space scheme   \n\nEnter '4' for to run Lax wendroff (LW) scheme \n\nEnter '5' for to run Beam Warming (BW) 		scheme 	\n\nEnter '6' for to run Fromm (FR) scheme \n\n**Enter the scheme number you want to run** :");
	//scanf("%d",&number);
{
	//if(number==1)

printf("\n\n ******Forward time Forward space scheme******\n\n");
}


for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==100)
			u[i][j+1]=u[i][j]-v*(u[0][j]-u[i][j]);
		else
			u[i][j+1]=u[i][j]-v*(u[i+1][j]-u[i][j]);
		printf("\n%f  %f  %d",i*dx,  u[i][j+1],  j);
		
	}
	getchar();
      }
	

	
	






//if(number==2)
{
printf("\n\n ******Forward time central space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
                   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]));
		else if(i==100)
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]));
		else
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,  u[i][j+1],  j);
	}
	getchar();
 	}

//if(number==3)
{
printf("\n\n ******Forward time Backward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[100][j]));
		else
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,  u[i][j+1],  j);
	}
	getchar();
 	}

//if(number==4)
{
printf("\n\n ****** Lax wendroff (LW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j]));
		else if(i==100)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j]));
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j]));
		printf("\n%f %f %d",i*dx,  u[i][j+1],  j);
	}
	getchar();
 	}

//if(number==5)
{
printf("\n\n ****** Beam Warming (BW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]));
     		else if(i==1)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j])); 
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]));
		printf("\n%f %f %d",i*dx,  u[i][j+1],  j);
	}
	getchar();
 	}

//if(number==6)
{
printf("\n\n ****** Fromm (FR) *****\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]))));
		else if(i==1)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j]))));
		else if(i==100)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		else
                  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		printf("\n%f %f %d",i*dx,  u[i][j+1],  j);
	}
	getchar();
 	}



//break;
//case 'B':
{
printf("\n\n Intial solution having two periods\n\n");
}
for(i=0;i<=100;i=i+1)
{
	if(0<=i*dx<0.05)
		u[i][0]=0;
	else if(0.05<=i*dx<0.35)
		u[i][0]=sin(((4*22)/7)*(((i*dx)-0.05)/0.3));
	else
		u[i][0]=0;
}

for(i=0;i<=100;i=i+1)
{
	printf("\n%f  %f  %d",i*dx,u[i][0],j);
}
getchar();
{
printf("\n\n ******Forward time Forward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==100)
			u[i][j+1]=u[i][j]-v*(u[0][j]-u[i][j]);
		else
			u[i][j+1]=u[i][j]-v*(u[i+1][j]-u[i][j]);
		printf("\n%f  %f  %d",i*dx,u[i][j+1],j);
		
	}
	getchar();
      }
{
printf("\n\n ******Forward time central space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
                   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]));
		else if(i==100)
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]));
		else
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ******Forward time Backward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[100][j]));
		else
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Lax wendroff (LW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j]));
		else if(i==100)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j]));
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Beam Warming (BW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]));
     		else if(i==1)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j])); 
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Fromm (FR) ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]))));
		else if(i==1)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j]))));
		else if(i==100)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		else
                  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
//break;
//case 'C':
{
printf("\n\n Initial solution having four periods\n\n");
}
for(i=0;i<=100;i=i+1)
{
	if(0<=i*dx<0.05)
		u[i][0]=0;
	else if(0.05<=i*dx<0.35)
		u[i][0]=sin(((8*22)/7)*(((i*dx)-0.05)/0.3));
	else
		u[i][0]=0;
}

for(i=0;i<=100;i=i+1)
{
	printf("\n%f  %f  %d",i*dx,u[i][0],j);
}
getchar();
{
printf("\n\n ******Forward time Forward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==100)
			u[i][j+1]=u[i][j]-v*(u[0][j]-u[i][j]);
		else
			u[i][j+1]=u[i][j]-v*(u[i+1][j]-u[i][j]);
		printf("\n%f  %f  %d",i*dx,u[i][j+1],j);
		
	}
	getchar();
      }
{
printf("\n\n ******Forward time central space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
                   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]));
		else if(i==100)
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]));
		else
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ******Forward time Backward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[100][j]));
		else
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Lax wendroff (LW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j]));
		else if(i==100)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j]));
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Beam Warming (BW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]));
     		else if(i==1)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j])); 
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Fromm (FR) ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]))));
		else if(i==1)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j]))));
		else if(i==100)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		else
                  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
//break;
//case 'D':
{
printf("\n\n Initial solution having six periods\n\n");
}
for(i=0;i<=100;i=i+1)
{
	if(0<=i*dx<0.05)
		u[i][0]=0;
	else if(0.05<=i*dx<0.35)
		u[i][0]=sin(((12*22)/7)*(((i*dx)-0.05)/0.3));
	else
		u[i][0]=0;
}

for(i=0;i<=100;i=i+1)
{
	printf("\n%f  %f  %d",i*dx,u[i][0],j);
}
getchar();
{
printf("\n\n ******Forward time Forward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==100)
			u[i][j+1]=u[i][j]-v*(u[0][j]-u[i][j]);
		else
			u[i][j+1]=u[i][j]-v*(u[i+1][j]-u[i][j]);
		printf("\n%f  %f  %d",i*dx,u[i][j+1],j);
		
	}
	getchar();
      }
{
printf("\n\n ******Forward time central space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
                   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]));
		else if(i==100)
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]));
		else
		   u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ******Forward time Backward space scheme******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[100][j]));
		else
		   u[i][j+1]=u[i][j]-(v*(u[i][j]-u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Lax wendroff (LW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j]));
		else if(i==100)
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j]));
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Beam Warming (BW) scheme ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]));
     		else if(i==1)
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j])); 
		else
		  u[i][j+1]=u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
	}
	getchar();
 	}
{
printf("\n\n ****** Fromm (FR) ******\n\n");
}
for(j=0;j<=100;j=j+1)
{
	for(i=0;i<=100;i=i+1)	
	{
		if(i==0)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[100][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[100][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[100][j])+u[99][j]))+((0.5*v*v)*(u[i][j]-(2*u[100][j])+u[99][j]))));
		else if(i==1)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[100][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[100][j]))));
		else if(i==100)
		  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[0][j]-u[i-1][j]))+((0.5*(v*v))*(u[0][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		else
                  u[i][j+1]=0.5*((u[i][j]-((0.5*v)*(u[i+1][j]-u[i-1][j]))+((0.5*(v*v))*(u[i+1][j]-(2*(u[i][j]))+u[i-1][j])))+(u[i][j]-((0.5*v)*((3*u[i][j])-(4*u[i-1][j])+u[i-2][j]))+((0.5*v*v)*(u[i][j]-(2*u[i-1][j])+u[i-2][j]))));
		printf("\n%f %f %d",i*dx,u[i][j+1],j);
 		
	}
	getchar();
 	}
//break;
//default : printf("\n\n you entered the wrong alphabet");		 
{
getchar();
}
}
}





		
		


