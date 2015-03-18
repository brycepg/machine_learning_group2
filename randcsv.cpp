/*
 * randcsv.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: rick
 */

#include <time.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	srand(time(NULL));
	double number=0;
	int rows=0, cols=0, rangeMin=0, rangeMax=0;
	//double number, between, rangeMin, rangeMax;
	string fileName;
	cout << "How many rows are there?: ";
	cin >> rows;
	cout << "How many columns are there?: ";
	cin >> cols;
	cout << "What is the minimum range of the data set?: ";
	cin >> rangeMin;
	cout << "What is the maximum range of the data set?: ";
	cin >> rangeMax;
	cout << "Enter a filename to save this data under: ";
	cin >> fileName;
	fileName = fileName + '.' + "csv";


	ofstream outFile;
	outFile.open(fileName.c_str());

	for(int count1 = 0; count1 < rows; count1++)
	{
		for(int count2 = 0; count2 < cols; count2++)
		{
			number = rand() %(rangeMax-rangeMin) + rangeMin;
			if(count2 == cols-1)
			{
				outFile << number;
			}
			else
			{
				outFile << number << ", ";
			}
		}
		if(count1<rows-1)
			outFile << endl;
	}
	outFile.close();
}



