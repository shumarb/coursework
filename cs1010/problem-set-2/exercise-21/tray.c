// CS1010 Programming Methodology
// Problem Set 2 Exercise #21: tray.c
//
// Program reads in 2 dimensions, calculates total perimeter obtained
// by folding tray at a certain position three times,
// and prints out the least perimeter obtained out of the 3 foldings.
//
// SHEIKH UMAR A0149874L

#include <stdio.h>

int main(void) {

	double new_length, new_width;
	double perimeter1,perimeter2,perimeter3,perimeter4;
	double answer;

	printf("Enter size of tray: ");
	scanf("%lf %lf",&new_length,&new_width);

	if(new_length>new_width){
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}

	perimeter1 = 2.0*(new_length+new_width);
	//printf("%.2lf\n",perimeter1);

	new_width/=2.0;
	if(new_length<new_width){
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}
	perimeter2 = 2.0*(new_length+new_width);
	//printf("%.2lf\n",perimeter2);

	new_length/=2.0;
	if(new_length>new_width){
		double temp = new_length;
		new_length = new_width;
		new_width = temp;
	}
	perimeter3 = 2.0*(new_length+new_width);
	//printf("%.2lf\n",perimeter3);

	new_width/=2.0;
	if(new_length<new_width){
		double temp = new_width;
		new_width = new_length;
		new_length = temp;
	}
	perimeter4 = 2.0*(new_length+new_width);
	//printf("%.2lf\n",perimeter4);

	//Compare all perimeters, print smallest value

	if(perimeter1<perimeter2 && perimeter1<perimeter3 && perimeter1<perimeter4){
		answer = perimeter1;
	}
	else if(perimeter2<perimeter1 && perimeter2<perimeter3 && perimeter2<perimeter4){
		answer = perimeter2;
	}
	else if(perimeter3<perimeter1 && perimeter3<perimeter2 && perimeter3<perimeter4){
		answer = perimeter3;
	}
	else{
		answer = perimeter4;
	}

	printf("Minimum perimeter after folding = %.2lf\n",answer);

	return 0;
}

