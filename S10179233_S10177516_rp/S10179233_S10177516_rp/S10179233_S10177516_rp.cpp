// S10179233_S10177516_rp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

void readWriteFile1() {
	std::string name, qty, price;
	std::ifstream productfile("product1.txt");
	std::ofstream transaction("transaction1.txt");
	if (productfile.is_open())
	{
		std::cout << "Name\t" << "Qty\t" << "Price\t" << "Amount\n";
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
	readWriteFile1();
    return 0;
}

