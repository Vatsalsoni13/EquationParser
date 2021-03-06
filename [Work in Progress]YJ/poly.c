#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "./typedef.c"
#include"./polydiv.c"
float tempSum;


#ifndef POLY
#define POLY

float rootErr =0.00001; //Error in roots //!Smaller value than this does not work or goes in infinite loop in some cases
										//! probabaly due to accuracy of floats 

Result root()
{
	float t;
	Result ret;
	t=(crrPoly[1]/crrPoly[0])*(crrPoly[1]/crrPoly[0])-2*(crrPoly[2]/crrPoly[0]);				//Upper Limit of Root
	if (t<0)
	{	
		ret.status = NO_REAL_ROOTS;
		sprintf(ret.error_info,"No Real roots Remainig for this polynomial");
		
		return ret;
	}
	else
	{
		t=sqrt(t);
	}
	ret.status =SUCCESS;
	ret.data = t;
	return ret;
}
float absolute(float x) //default c abs from math only operates on ints
{
	if ( x < 0)
		return -x;
	else
		return x;
}
void getSum(int iteration,int degree)
{
	int i;
	tempSum=0;
	for (i=0;i<=degree-iteration-1;i++)
	{
		tempSum=root1*tempSum+polyQtnt[i];
	}
}
void evalPoly(int degree)
{
	int i,j;
	float tempRoot;
	Result temp;

	if(crrPoly[degree]==0){
		pushRoot(0);
		while(crrPoly[degree]==0){
			degree--;
		}
	}
	
	for (i = 0; i < degree; i++)
	{
		

		if (degree-i>1)	// For all cases except Last when the eqn will be linear
		{	
			temp = root();
			if(temp.status == NO_REAL_ROOTS){
				return;
			}
			root1=temp.data;
			do
			{
				Remainder=polyDiv(degree-i);
				getSum(i,degree-i);
				tempRoot=root1;
				root1=tempRoot-Remainder/tempSum;
			}
			while (absolute(Remainder)>=rootErr);				//Iterating the value of Root till Remainder is less than 0.001
			for (j=0; j < degree-i; j++)			//Storing Quotient Array in our next Divisor Array
			{
				crrPoly[j]=polyQtnt[j];
			}
			pushRoot(root1);
		}
		else							//When the equation is reduced to Linear Form
		{
			root1 = -crrPoly[1]/crrPoly[0];
			pushRoot(root1);
		}
	}
}
#endif
/* void main()
{
	int degree;
	degree=getPoly();
	evalPoly(degree);	
	displayRoot();		//This will display the root
} */