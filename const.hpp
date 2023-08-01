#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <filesystem>



const int cellSize=30;				// cm
const int halfCell=cellSize*0.5;	// cm
const double xmin=400;	// wide range is x = 400 to 910
const double xmax=910;
const double ymin=50;	// wide range is y = 50 to 830
const double ymax=830;
const double zmin=100;	// wide range is z = 100 to 190
const double zmax=190;

const double xminShift=xmin-halfCell;
const double yminShift=ymin-halfCell;
const double zminShift=zmin-halfCell;

const double xmaxShift=xmax+halfCell;
const double ymaxShift=ymax+halfCell;
const double zmaxShift=zmax+halfCell;

struct point {
	double x[3];
};

struct particle {
	std::vector<std::vector<double>> matrix;
	int imax;
	int i;
};

struct source {
	point x;	// position
};
