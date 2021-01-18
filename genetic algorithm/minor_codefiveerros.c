/*INCLUDING THE HEADER FILES */

#include<stdio.h>
#include<conio.h>

/*Defining the cities distance for the problem in a matrix in 10*10 array*/

int tsp [10][10]={ {999,10,3,2,5,6,7,2,5,4},
{20,999,3,5,10,2,8,1,15,6},
{10,5,999,7,8,3,11,12,3,2},
{3,4,5,999,6,4,10,6,1,8},
{1,2,3,4,999,5,10,20,11,2},
{8,5,3,10,2,999,6,9,20,1},
{3,8,5,2,20,21,999,3,5,6},
{5,2,1,25,15,10,6,999,8,1},
{10,11,6,8,3,4,2,15,999,1},
{5,10,6,4,15,1,3,5,2,999}
};

/*STEP 1:
Defining the parents randomly for the first generation i.e. INITIAL POPULATION
and then reaching to a better offspring
two parents result in one offspring at once and then the cycle continues for the new offspring after 
it continues its generation

STEP 2: DETERMINING THE FITNESS FUNCTION 
The new fitness value is assigned to
the minimum cost. Initial populacion is randomly chosen and taken as the parent. For the next generation,
the cyclic crossover is applied over the parent.

STEP 3: 
SELECTION OF PARENTS

	STEP 3.i : PERFORMING CYCLIC CROSSOVER:

	STEP 3.ii : CALCULATION OF FITNESS OR THE MINIMUM COST POSSIBLE OF NEW POPULATION 
			if fitter gene path is found update it in the mincost variable

	STEP 3.iii : DISPLAYING THE MINIMUM COST AND THE MINIMUM COST PATH RETRIEVED BY THE PROGRAM

	STEP 3.iv : APPEND THE NEW GENERATIONS TO THE GENE POOL*/


int pa[1000][10]= {{0,1,2,3,4,5,6,7,8,9},
{9,8,6,3,2,1,0,4,5,7},
{2,3,5,0,1,4,9,8,6,7},
{4,8,9,0,1,3,2,5,6,7}
} ;
int i,j,k,l,m,loc,flag,col,it,x=3,y=3;
int count,row=0,res[1][10],row1,col1,z;
int numoff=4;

/* the use of variables with their purpose is mentioned below:
i for iterating through arrays
j for iterating through arrays
k for iterating through arrays in functions
l for iterating through arrays in functions
m for iterating through parents
loc to check thru empty slots
flag to check if condition is met
col is column
it tracks number of iterations
count keeps track of the 
row denotes row of the matrix
res stores the best offspring
row1 row of offspring
col1 column of offspring
z for iterating thru min cost loops
numoff counts no. of generations
*/

/*creating an array for storing the offsprings that would be generated*/
int offspring[1000][10];

/*
Fitness function is nothing but the minimum cost(mincost). 
Initially the fitness function is set for the maximum value(9999)and 
for each travel, the cost is calculated and compared with the fitness function.
lesser the fitness score , lesser is the path cost which is the ultimate goal
*/

int mincost=9999,mc;

/*mc is the variable used for storing temporary values of minimum cost for constant comparison */

main()
{
/*gen stores the number of generation*/
	int gen;
	printf ("Number of Generation:");
	scanf("%d",&gen);
	offcal1(pa);
	offcal2(pa);
	
/* setting the inital population in the functions as the first generation parents*/
	
	printf(" \n\t\t First Generation\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<10;j++)
			printf("%d",offspring[i][j]);
			printf("\n");
	}
	
/* parents for the next generations to be followed*/
	
	for(y=1;y<=gen-1;y++)
	{
		getch();
		//clrscr();
		for(i=0;i<count;i++)
			for(j=0;j<10;j++)
				pa[i][j]=offspring[i][j];
		numoff=count;
		offcal1(pa);
		offcal2(pa);
		
/*STEP 3.iv : APPEND THE NEW GENERATIONS TO THE GENE POOL*/
		
		printf("\n\t\t %d Generation\n",y+1);
		for(i=0;i<count;i++)
		{
		for(j=0;j<10;j++)
		printf("%d",offspring[i][j]);
		printf("\n");

}
/* STEP 3.iii : DISPLAYING THE MINIMUM COST AND THE MINIMUM COST PATH RETRIEVED BY THE PROGRAM*/
		/*used to display output until user presses any other key*/
		getch();
		
		}
	printf("\n\nMinimum Cost Path\n");
	for(z=0;z<10;z++)
		printf("%d",res[0][z]);
		printf("\n Minimum Cost %d \n" ,mincost);
		}
/* finding the offspring using cyclic crossover 
taking input the parents of current generation*/

/* STEP 2: DETERMINING THE FITNESS FUNCTION 
The new fitness value is assigned to
the minimum cost. Initial populacion is randomly chosen and taken as the parent. For the next generation,
the cyclic crossover is applied over the parent.*/

/* STEP 3: SELECTION OF PARENTS*/
/* STEP 3.i : PERFORMING CYCLIC CROSSOVER:
Using this technique to create offspring in such a way that each bit with its position comes from one of the parents.


offcal1 basically takes the first set of parents:

for example, 

p1=	1 2 3 4 5 6 7 8
p2=	8 5 2 1 3 6 4 7

Now it is up to us how we choose the first bit for the offspring to be either from the first or from the second parent. 

In our example, the first bit of the offspring has to be 1 or 8. Let us choose it be 1: 

Now every bit in the offspring should be taken from one of its parents with the same position

 it means that further we do not have any choice, so the next bit to be considered must be bit 8
 
o1=	1 . . . . . . .

 as the bit from the second parent is just below the selected bit 1. In first parent this bit is at 8th position; thus
 
	1 . . . . . . 8

This turnout implies bit 7, which is the bit of second parent just below the selected bit at 7th position in first parent.		
	
	1 . . . . . 7 8
	
Next, this forced us to put 4 at 4th position as	
	
	1 . . 4 . . 7 8
	
After this, 1 comes which is already in the list;	
	
thus we have completed a cycle and filling the remaining blank positions with the bits(5,2,3,6) of those positions which are in second parent:
	
o1= 	1 5 2 4 3 6 7 8

Thus
Similarly the second offspring can be found out on same pattern

now the use of offcal2 comes into play when we reverse the parents to get another offspring

o2= 	8 2 3 1 5 6 4 7

Hence the work done by both functions is same with only difference in variables taken to run the loops to interchange the parents
*/
offcal1(pa)
int pa[1000][10];
{
	
	count=0;
	for(i=0;i<1000;i++)
	for(j=0;j<10;j++)
    	offspring[i][j]=-1;
	for(k=0;k<numoff;k++)
	{
	for (l=k+1;l<numoff;l++)
	{
		offspring[row][0]=pa[k][0];
		loc=pa[l][0];
		flag=1;
		while(flag != 0)
		{
		for(j=0;j<10;j++)
			
/*looking for the empty positions and placing the city number sequence by crossover as explained above */
			
{
if(pa[k][j] ==loc)
{
if (offspring[row][j]==-1)
{
offspring [row][j] =loc;
loc=pa[l][j];}
else
flag=0;
}
}
}
/* end while*/


/*here we are comparing the parents and creating an offspring as exlplained in the above example*/	
		
for(m=0;m<10;m++)
{
if(offspring[row][m] == -1)
offspring[row][m]=pa[l][m];
}
for(z=0;z<10;z++)
{
if(z<9)
{
row1=offspring[row][z];
col1=offspring[row][z+1];
mc=mc+tsp[row1][col1];
}

/*else case here signifies the situation what we faced with 1 in the above example when we 
already had assigned the position somewhere else*/
	
else
{
row1=offspring[row][z];
col1=offspring[row][0];

/*adding all the distances for the cost*/

mc=mc+tsp[row1][col1];
}
}
/* STEP 3.ii : CALCULATION OF FITNESS OR THE MINIMUM COST POSSIBLE OF NEW POPULATION 
if fitter gene path is found update it in the mincost variable*/

if(mc < mincost)
{
for(z=0;z<10;z++)
res[0][z]=offspring[row][z];
mincost=mc;
}
count++;
row++;
}/* end l*/
}}

offcal2(pa)
int pa[1000][10];
{
for(k=0;k<numoff;k++)
{
for(l=k+1;l<numoff;l++)
{
offspring[row][0]=pa[l][0];
loc=pa[k][0];
flag=1;

while(flag != 0)
{
for(j=0;j<10;j++)
{
if(pa[l][j] == loc)
{
if (offspring[row][j]==-1)
{
offspring[row][j]=loc;
loc=pa[k][j];
}
else
flag=0;
}
}
}
/* end while*/

for(m=0;m<10;m++)
{
if(offspring[row][m] == -1)
offspring[row][m]=pa[k][m];
}

for(z=0;z<10;z++)
{
if(z<9)
{
row1=offspring[row][z];
col1=offspring[row][z+1];
mc=mc+tsp[row1][col1];
}

else
{
row1=offspring[row][z];
col1=offspring[row][0];
mc=mc+tsp[row1][col1];
}}

/* STEP 3.ii : CALCULATION OF FITNESS OR THE MINIMUM COST POSSIBLE OF NEW POPULATION */

row++;
if(mc<mincost)
{
	for(z=0;z<10;z++)
		res[0][z]=offspring[row][z];
mincost=mc;
}
count++;
}/* end l*/
}
}
