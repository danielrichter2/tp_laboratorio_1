/*
 * arrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: richter
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

typedef struct
{
	int statusFlight;
	char descriptionSF[15];
	int typePassenger;
	char descriptionTP[15];
} StatusFlightAndTypePassenger;

/// @brief To indicate that all position in the array are empty, this function put the flag (isEmpty)
/// in TRUE in all position of the array
/// @param list Passenger* Pointer to array of passenger
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
///
int initPassengers(Passenger* list, int len);

/// @brief To indicate the values of the different types of passengers and flight statuses that exist
///
/// @param statusType
/// @param len
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int initStatusFlightAndTypePassenger(StatusFlightAndTypePassenger* statusType, int len);

/// @brief Find a Empty slot
///
/// @param list passenger*
/// @param len int
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int findFreeSlot(Passenger* list, int len);

/// @briefadd in a existing list of passengers the values received as parameters in the first empty position
///
/// @param list passenger*
/// @param len int
/// @param id int
/// @param name char
/// @param lastName char
/// @param price float
/// @param typePassenger int
/// @param flycode char
/// @param statusFlight int
/// @returnint Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);

/// @brief find a Passenger by Id and returns the index position in array.
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]

int findPassengerById(Passenger* list, int len,int id);

/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param list Passenger*
/// @param len int
/// @param id int
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok

int removePassenger(Passenger* list, int len, int id);

/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int sortPassengersByLastName(Passenger* list, int len, int order);

/// @brief print the content of passengers array
///
/// @param list Passenger*
/// @param length int
/// @return int

int printPassenger(Passenger* list, StatusFlightAndTypePassenger* status, int length, int lenStatusType);

/// @brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
///
/// @param list Passenger*
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int sortPassengersByCode(Passenger* list, int len, int order);

/// @brief Modify the field indicated by option in the slot of array of passengers indicated by index
///
/// @param list Passenger*
/// @param len int
/// @param index index where was charged the passenger and will be modify
/// @param option int [1] name [2] lastName [3] price [4] TypePassenger [5] flyCode
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok

int modifyPassenger(Passenger* list, int len, int index, int option);

/// @brief Calculate the total value of all flights and calculate the average of them
///
/// @param list Passenger*
/// @param len int
/// @param total Price returns through the pointer the total price of the flights
/// @param average Returns through the pointer the average price of the flights
/// @return int Return (-1) if Error [Invalid length or NULL pointer or the list are empty] - (0) if Ok

int averagePassenger(Passenger* list, int len, float* totalPrice, float* average);

/// @brief count how many passengers pay above the average price
///
/// @param list Passenger*
/// @param len int
/// @param average average price of flights
/// @return int (-1) if error [Invalid length or NULL pointer or the list are empty] or the number of passengers above the average

int aboveAveragePassenger(Passenger* list, int len, float average);

#endif /* ARRAYPASSENGER_H_ */
