// S10179233_S10177516_rp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Initialise data
string name[4] = { "iPhone_7", "Galaxy_S7", "Xperia_Z", "Redmi_3S" };
int qty[4] = { 10, 10, 10, 10 };
double price[4] = { 1088, 999, 899, 299 };

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

void readWriteFile1() {
	string name, qty, price;
	ifstream productfile("product1.txt");
	ofstream transaction("transaction1.txt");
	if (productfile.is_open())
	{
		cout << "Name\t" << "Qty\t" << "Price\t" << "Amount\n";
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


int main()
{
	writeToFile1();
	readWriteFile1();
}

