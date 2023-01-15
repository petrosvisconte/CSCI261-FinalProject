## Author: Pierre Visconti
## Class: CSCI261 - Colorado School of Mines

I am simply posting my work as a record for myself and as an academic resource for others. Do not blindly copy and attempt to submit as your own. 




Title:
	Pierre Visconti
	CSCI 261 - F
	Trading Bot

Problem Description:
	For my final project I wrote a program that reads in a CSV file containing stock data.  
	The format of the data in the file must be in the following order: date, open price, highest price, 
	lowest price, closing price, adjusted close price, and volume. Each line must contain stock data 
	for the day. With the next line containing the data for the following day. The user must upload a CSV 
	file containing this data, and make sure it is in the same directory as their main function. 
	Based on this data the program then calculates various indicators like RSI, SMA, EMA, and MACD.
	This data is then written to another CVS file, which is viewable in excel and can be used in decisions
	of when to open or close trades. 

Program Documentation: 
	A CSV file called: "spydata.csv" will be included with the project code. The user should verify that
	the file is in the same directory as their main. Once they run the program, they will be initially prompted
	for the name of the file, this is where the user should enter "spydata.csv". If the user wishes to use
	a different file then they must make sure that it follows the exact format described in the problem
	description and be atleast 30 lines long. If I had more time I would have liked to add two more classes
	to my program. One class would be called Analysis, and the other Trade. The Analysis class would interpret
	the technical data that has been calculated by the program and then decide whether or not it should open
	or close a trade at that time based on the data. The Trade class would then write the information of the trade
	to a CSV file, and keep track of profit/loss. 

Tests:
	If the user tries to enter the name of a file that isn't located in the directory, then the program will 
	output an error message saying "File failed to open", and will return -1. If the user enters a valid file
	name then the porgram will run as intended. Although if the format of the file isn't the same as described 
	in the program description, then the program will not work as intended, the file must be in the exact same
	format, and must be of type CSV. Otherwise, if the file name is valid, and the format is valid, then the
	program will work as intended. If the writable file where the indicator data gets written to, fails to open,
	then the program will outout an error message saying "File failed to open", and will return -2. If both files
	open successful and are of proper formatting, then the program will work as intended. My .CSV readable file
	with the stock data was called "spydata.csv". If I entered spydata.csv when prompted to enter the name of my file
	the program would successfully read and interpret the data, and then write the calculated indicators to a 
	seperate csv file. 

Reflections:
	I learned that sometimes you may have to sacrifice parts of your program that you had originally intended
	to include due to lack of time. Even though I had gotten an early start on the project I still wasn't able 
	to include the actual bot trading portion of the program like I had intended to do. The main issue was that
	the calculations for the indicators took a while to program since I had to research online which indicators 
	I should calculate, what time frames they should be calcuated for in order to get the best trading results,
	and then how to calculate the indicators themselves.  
