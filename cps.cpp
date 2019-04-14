// cps.cpp
// Project 2 for CS372
// Alex L, Simeon N, Nami K
// Created: 20 Mar 2019
// Modified: 31 Mar 2019
//
// Description of this project can be found at:
// https://github.com/namikim97/cs372_project2_cps
// CPS Main


#include "page.h"
#include "shapes.h"
#include "compound.h"

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ofstream;
#include <memory>
using std::make_shared;




int main()
{
	Circle circle(50);
	Rectangle rect(40, 60);
	Triangle tri(30);

	std::vector<std::shared_ptr<Shape>> layerVec;
	layerVec.push_back(std::make_shared<Circle>(circle));
	layerVec.push_back(std::make_shared<Rectangle>(rect));
	layerVec.push_back(std::make_shared<Triangle>(tri));
	Layered lay(std::move(layerVec));

	std::string layerString = lay.getPostScriptCode();

	std::ofstream output;
	output.open("test.ps", std::ofstream::out | std::ofstream::app);
	output << "%!\n";
	output << "144 144 translate\n";
	output << layerString;
	output << "\n";
	output << "showpage\n";

	output.close();


	return 0;
}
