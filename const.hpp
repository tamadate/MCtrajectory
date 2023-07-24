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



const int cellSize=30;	// cm
const double xmin=400;
const double ymin=50;
const double zmin=100;
const double xminShift=xmin-0.5*30;
const double yminShift=ymin-0.5*30;
const double zminShift=zmin-0.5*30;
const double xmax=910;
const double ymax=830;
const double zmax=190;
const double xmaxShift=xmax+0.5*30;
const double ymaxShift=ymax+0.5*30;
const double zmaxShift=zmax+0.5*30;

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
