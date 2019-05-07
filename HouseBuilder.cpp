#include "pch.h"
#include <iostream>
#include<string>

enum HouseType
{
	STANDART,
	VILLAGE,
	POOR,
	RICH
};

class House
{
public:
	virtual std::string Roof(HouseType type) = 0;
	virtual std::string Floor(HouseType type) = 0;
	virtual std::string Basement(HouseType type) = 0;
	virtual std::string GrassStatues(int countGrass, int countStatues) = 0;
	virtual void getResult(std::string all) = 0;
};

class NewBuilder : public House
{
public:
	std::string Roof(HouseType type) override
	{
		std::string roof = "";
		if (type == POOR)
		{
			roof = "\t  /\\  \t\n\t /  \\ \t\n\t/____\\\t\n";
		}
		else
		{
			if (type == RICH)
			{
				roof = "\t   $  \t\n\t /  \\ \t\n\t/____\\\t\n";
			}
		}
		return roof;
	}

	std::string Floor(HouseType type) override
	{
		std::string floor = "";
		if (type == POOR)
		{
			floor = "\t|____|\t\n";

		}
		else
		{
			if (type == RICH) //2 floors in rich house
			{
				floor = "\t|  o |\t\n\t|__o_|\t\n";
			}
		}
		return floor;
	}
	std::string Basement(HouseType type) override
	{
		std::string bas = "";
		if (type == POOR)
		{
			bas = "\t  |_|  \n";
		}
		else
		{
			if (type == RICH)
			{
				bas = "\t  |&|  \n";
			}
		}
		return bas;
	}
	std::string GrassStatues(int countGrass, int countStatues) override
	{
		std::string devide = "------";
		std::string grass = "/";
		std::string statues = "O";
		std::string field = "";
		if (countGrass == 0 && countStatues == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				field += devide;
			}
			field += "\n";
			return field;

		}
		if (countGrass > 0 || countStatues > 0)
		{
			field += devide;
			for (int i = 0; i < countGrass; i++)
			{
				field += grass;
			}
			for (int i = 0; i < countStatues; i++)
			{
				field += statues;
			}
			field += devide;
			field += "\n";
			return field;
		}
	}

	void getResult(std::string all)
	{
		std::cout << all;
	}
};

class Foreman
{
public:
	NewBuilder b;

	void build(HouseType type)
	{
		std::string letsBuild = "";
		std::string house;
		int s, g;
		switch (type)
		{
		case STANDART: //Standart house goes without grass and statues
			std::cout << "Choose type of house: POOR OR RICH? ";
			std::cin >> house;
			std::cout << "It's your standart house: " << std::endl;
			if (house == "POOR" || house == "poor")
			{
				letsBuild = b.Roof(POOR) + b.Floor(POOR) + b.GrassStatues(0,0) + b.Basement(POOR);
			}
			else
			{
				if (house == "RICH" || house == "rich")
				{
					letsBuild = b.Roof(RICH) + b.Floor(RICH) + b.GrassStatues(0,0) + b.Basement(RICH);
				}
				else
				{
					std::cout << "Name error";
				}
			}
			b.getResult(letsBuild);
			break;

		case VILLAGE: //Village house
			std::cout << "Choose type of house: POOR OR RICH? ";
			std::cin >> house;
			std::cout << "How many grass and statues do you want?" << std::endl;
			std::cin >> g;
			std::cin >> s;

			std::cout << "It's your village house: " << std::endl;
			if(house == "POOR" || house == "poor")
			{
				letsBuild = b.Roof(POOR) + b.Floor(POOR) + b.GrassStatues(g, s) + b.Basement(POOR);
			}
			else
			{
				if (house == "RICH" || house == "rich")
				{
					letsBuild = b.Roof(RICH) + b.Floor(RICH) + b.GrassStatues(g, s) + b.Basement(RICH);
				}
				else
				{
					std::cout << "Name error";
				}
			}
			b.getResult(letsBuild);
			break;

		case POOR: //Poor house
			std::cout << "It's poor house" << std::endl;
			std::cout << "How many grass and statues do you want to add?";
			std::cin >> g;
			std::cin >> s;
			std::cout << "It's your standart house: " << std::endl;
			letsBuild = b.Roof(POOR) + b.Floor(POOR) + b.GrassStatues(g, s) + b.Basement(POOR);
			b.getResult(letsBuild);
			break;

		case RICH: //Rich house
			std::cout << "It's rich house" << std::endl;
			std::cout << "How many grass and statues do you want to add?";
			std::cin >> g;
			std::cin >> s;
			std::cout << "It's your standart house: " << std::endl;
			letsBuild = b.Roof(RICH) + b.Floor(RICH) + b.GrassStatues(g, s) + b.Basement(RICH);
			b.getResult(letsBuild);
			break;

		default:
			break;
		}
	}

};

int main()
{
	Foreman f;
	std::string choice;
	std::cout << "Choose type which you want:\nSTANDART\nVILLAGE\nPOOR\nRICH\n";
	std::cin >> choice;
	if (choice == "STANDART" || choice=="standart")
	{
		f.build(STANDART);
	}
	else
	{
		if (choice == "VILLAGE" || choice == "village")
		{
			f.build(VILLAGE);
		}
		else
		{
			if (choice == "POOR" || choice == "poor")
			{
				f.build(POOR);
			}
			else
			{
				if (choice == "RICH" || choice == "rich")
				{
					f.build(RICH);
				}
				else
				{
					std::cout << "Name error.";
				}
			}
		}
	}
	
	//f.build(VILLAGE);
}
