#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LEN 256
#define ARRAY_SIZE(a) (sizeof a / sizeof a[0])
//====================

typedef struct CarStruct{
	char model[LEN];
	int year;
	int mileage;
}Car_t;

/*Car_t carList []= {
		{"Ford Focus", 2008, 47478},
		{"KIA Sportage", 2008, 29290},
		{"Toyota Prius", 2010, 8967},
		{"Mercedes E160", 2004, 29080},
		{"Toyota Corolla", 2009, 80047},
		{"Mitsubisi Lancer", 2014, 57557}
};*/

void displayCars(Car_t* list, int count);
int sortByMileage(const void* item1, const void* item2);
int sortByYear(const void* item1, const void* item2);
int sortByModel(const void* item1, const void* item2);

//====================
int main (){
	Car_t *carList;
	FILE *carFile;
	int carCount = 0;
	carFile = fopen("CarList.txt","r");

	if(carFile == NULL)
	{
	   printf("Error, no car list file");
	   exit(1);
	}

	carList = (Car_t*)malloc(sizeof(Car_t));
	do {
		if (fscanf(carFile, "%253s%d%d", carList[carCount].model, &carList[carCount].year, &carList[carCount].mileage) != 3){
			break;
		}
		carCount ++;
		carList = (Car_t*)realloc(carList,(carCount + 1) * sizeof(Car_t) );
	} while (carList != NULL);
	fclose(carFile);
	//==========
	printf("Unsorted list:\n\r");
	displayCars(carList, carCount);
	qsort (carList, carCount, sizeof(Car_t), sortByMileage);
	printf("Sorted by mileage:\n\r");
	displayCars(carList, carCount);

	qsort (carList, carCount, sizeof(Car_t), sortByYear);
	printf("Sorted by year:\n\r");
	displayCars(carList, carCount);

	qsort (carList, carCount, sizeof(Car_t), sortByModel);
	printf("Sorted by model:\n\r");
	displayCars(carList, carCount);
	free(carList);
	return 0;
}
//====================
void displayCars(Car_t* list, int count){
	for (int i = 0; i < count; i++){
		printf("Model: %s\tManufacturing year: %d\tMileage: %d\n\r",
				list[i].model,
				list[i].year,
				list[i].mileage);
	}
	printf("\n\r");
}
//====================
int sortByMileage(const void* item1, const void* item2){
	return ((Car_t*)item1)->mileage - ((Car_t*)item2)->mileage;
}

int sortByYear(const void* item1, const void* item2){
	return ((Car_t*)item1)->year - ((Car_t*)item2)->year;
}

int sortByModel(const void* item1, const void* item2){
	return strcmp(((Car_t*)item1)->model, ((Car_t*)item2)->model);
}
