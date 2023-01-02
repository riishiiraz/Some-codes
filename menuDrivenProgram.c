// @author : rishitosh anand
// @github : @riishiiraz

#include <stdio.h>

// for [area of Rectangle , Square , Circle , Triangle ]

const float PI = 3.142857142857143;

int main()
{
	printf("Enter\n");
	printf("1] to Calculate area of Rectangle \n");
	printf("2] to Calculate area of Square \n");
	printf("3] to Calculate area of Circle \n");
	printf("4] to Calculate area of Triangle \n");
	
	printf("5] to Exit. \n");


	int choice, length, breadth,side ,radius, height, base;

	printf ("Choice [1-5] : ");
	scanf ("%d",&choice);

	if (choice==1) {/*Rectangle*/
	
		printf("Enter Length for Rectangle : ");
		scanf("%d",&length);

		printf("Enter Breadth for Rectangle : ");
		scanf("%d",&breadth);

		printf("Area of Rectangle = %d Sq. Units. \n",(length*breadth));

	}

	else if (choice==2){/*Square*/
		printf("Enter Side for Square : ");
		scanf("%d",&side);

		printf("Area of Square = %d Sq. Units. \n",(side*side));
	}

	else if (choice==3){/*Circle*/
		printf("Enter Radius for Circle : ");
		scanf("%d",&radius);

		printf("Area of Circle = %.2f Sq. Units. \n",(PI*(radius*radius)));

	}

	else if (choice==4){/*Triangle*/
		printf("Enter Base for Triangle : ");
		scanf("%d",&base);

		printf("Enter Height for Triangle : ");
		scanf("%d",&height);


		printf("Area of Circle = %.2f Sq. Units. \n",(0.5*base*height));
	}

	else if (choice==5) /*Exit*/
	{
		printf("\nExited !");
		return 0;
	}

}
