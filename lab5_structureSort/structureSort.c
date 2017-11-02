#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define LEN 256
#define ARRAY_SIZE(a) (sizeof a / sizeof a[0])

typedef struct CarStruct{
	char* model;
	int year;
	int mileage;
}Car_t;

Car_t carList []= {
		{"Ford Focus", 2008, 47478},
		{"KIA Sportage", 2008, 29290},
		{"Toyota Prius", 2010, 8967},
		{"Mercedes E160", 2004, 29080},
		{"Toyota Corolla", 2009, 80047},
		{"Mitsubisi Lancer", 2014, 57557}
};

void displayCars();
int sortByMileage(const void* item1, const void* item2);
int sortByYear(const void* item1, const void* item2);
int sortByModel(const void* item1, const void* item2);

int main (){
	printf("Unsorted list:\n\r");
	displayCars();
	qsort (carList, ARRAY_SIZE(carList), sizeof carList[0], sortByMileage);
	printf("Sorted by mileage:\n\r");
	displayCars();

	qsort (carList, ARRAY_SIZE(carList), sizeof carList[0], sortByYear);
	printf("Sorted by year:\n\r");
	displayCars();

	qsort (carList, ARRAY_SIZE(carList), sizeof carList[0], sortByModel);
	printf("Sorted by model:\n\r");
	displayCars();
	return 0;
}

void displayCars(){
	for (int i = 0; i < ARRAY_SIZE(carList); i++){
		printf("Model: %s\tManufacturing year: %d\tMileage: %d\n\r",
				carList[i].model,
				carList[i].year,
				carList[i].mileage);
	}
	printf("\n\r");
}

int sortByMileage(const void* item1, const void* item2){
	return ((Car_t*)item1)->mileage - ((Car_t*)item2)->mileage;
}

int sortByYear(const void* item1, const void* item2){
	return ((Car_t*)item1)->year - ((Car_t*)item2)->year;
}

int sortByModel(const void* item1, const void* item2){
	return strcmp(((Car_t*)item1)->model, ((Car_t*)item2)->model);
}
