// S10179233_S10177516_rp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Initialise data
string name[4] = { "iPhone_7", "Galaxy_S7", "Xperia_Z", "Redmi_3S" };
string spacedname[4] = { "iPhone 7", "Galaxy S7", "Xperia Z", "Redmi 3S" };
int qty[4] = { 10, 10, 10, 10 };
double price[4] = { 1088, 999, 899, 299 };
double amount[4];

// Displays column headings
void displayHeadings()
{
	cout << "Name" << "\t\t"
		<< "Qty" << "\t"
		<< "Price" << "\t"
		<< "Amount" << "\n";
}

// Writes data to product1.txt
void writeToFile1()
{
	ofstream product1;
	product1.open("product1.txt");

	for (int i = 0; i < 4; i++)
	{
		product1 << name[i] << "\t"
			 << qty[i] << "\t"
			 << setprecision(2) << fixed << price[i] << "\n";
	}

	product1.close();
}

// Read data from product1.txt, calculates amount & displays output
void readFromFile1()
{
	ifstream product1;
	product1.open("product1.txt");

	// Check if the file was opened successfully
	if (!product1)
	{
		cout << "An error occurred while opening product1.txt. Please try again.";
		return;
	}

	// Display column headings
	displayHeadings();

	// Initialise variables to act as buffer holders for values in product1.txt
	string n;
	int q;
	double p;

	// Parse product1.txt
	for (int i = 0; i < 4; i++)
	{
		// Extract name, qty, & price
		product1 >> n >> q >> p;

		// Calculate amount & insert to amount array
		amount[i] = q * p;

		// Display data
		cout << n << "\t"
		     << q << "\t"
		     << p << "\t"
		     << amount[i] << "\n";
	}
}

// Read data from product1.txt, calculates amount and write data to transaction1.txt
void readWriteFile1() {
	string name, qty, price;
	ifstream productfile("product1.txt");
	ofstream transaction("transaction1.txt");
	if (productfile.is_open())
	{
		// Display column headings
		displayHeadings();

		int i = 0;
		if (transaction) {
			while (productfile)
			{
				productfile >> name >> qty >> price;
				transaction << name + '\t' << qty + '\t' << price + '\t' << (stof(qty) * stof(price)) << '\n';

			}
			transaction.close();
		}
		productfile.close();
	}
}

void writeToFile2() {
	ofstream product2;
	product2.open("product2.txt");

	for (int i = 0; i < 4; i++)
	{
		product2 << spacedname[i] << ";"
			<< qty[i] << ";"
			<< setprecision(2) << fixed << price[i] << "\n";
	}

	product2.close();
}

void readWriteFile2() {
	string data[4] = {};
	string line;
	ifstream productfile2("product2.txt");
	if (productfile2.is_open()) {
		while (getline(productfile2, line, ';')) {
			cout << line << "\n";
		}
	}
	cout << data[0];
	system("PAUSE");
}

int main()
{
	writeToFile2();
	readWriteFile2();
}

