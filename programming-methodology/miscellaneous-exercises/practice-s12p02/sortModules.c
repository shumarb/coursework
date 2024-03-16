// sortModules.c
// Given an array of module codes, and an array of student
// enrolment, sort the modules in ascending order of 
// student enrolment.
#include <stdio.h>
#include <string.h>

#define MAX_MODULES 10   				// maximum number of modules
#define CODE_LENGTH 7    				// length of module code

typedef struct {
	char code[CODE_LENGTH+1];			// module code
	int enrolment;						// enrolment 
} module_t;

int scanModules(module_t []);
void printModules(module_t [], int);
void sortByEnrolment(module_t [], int);
void swapsModules(module_t [], int, int);

int main(void) {
	module_t modules[MAX_MODULES];
	int num_modules;

	num_modules = scanModules(modules);
	sortByEnrolment(modules, num_modules);
	printModules(modules, num_modules);

	return 0;
}

// Read number of modules, and for each module, the module codes and enrolment figures.
// Return number of modules.
int scanModules(module_t modules[]) 
{
	int i, size;

	printf("Enter number of modules: ");
	scanf("%d", &size);

	printf("Enter module codes and student enrolment:\n");
	for (i = 0; i < size; i++) 
	{
		scanf("%s %d", modules[i].code, &modules[i].enrolment);
	}

	return size;
}

// Print module codes and enrolment figures
void printModules(module_t modules[], int size) 
{
	int i;

	printf("Sorted by student enrolment:\n");
	for (i = 0; i < size; i++)
	{
		printf("%s\t%3d\n", modules[i].code, modules[i].enrolment);	
	}
}

// Swaps modules with each other in the modules array
void swapsModules(module_t modules[], int i, int j)
{
	char temp_code[CODE_LENGTH + 1];
	strcpy(temp_code, modules[i].code);
	int temp_enrolment = modules[i].enrolment;

	strcpy(modules[i].code, modules[j].code);
	modules[i].enrolment = modules[j].enrolment;

	strcpy(modules[j].code, temp_code);
	modules[j].enrolment = temp_enrolment;
}

// Sort by enrolment in each module
// Selection Sort is used
void sortByEnrolment(module_t modules[], int size) 
{
	int i, j;
	
	for (i = 0; i < size - 1; i++) 
	{
		for (j = i + 1; j < size; j++) 
		{
			if (modules[i].enrolment > modules[j].enrolment) 
			{
				swapsModules(modules, i, j);
			}
		}
	}
}
