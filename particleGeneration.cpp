#include "MC.hpp"

void MC::particleGeneration(void){
	for(auto &a : humans){
		for(int i=0;i<particleRate;i++){
			// get human position
			int ix=(a.x[0]-xminShift)/cellSize;
			int iy=(a.x[1]-yminShift)/cellSize;
			int iz=(a.x[2]-zminShift)/cellSize;
			int x=ix*cellSize+xmin;
			int y=iy*cellSize+ymin;
			int z=iz*cellSize+zmin;

			// file name generation
			std::uniform_int_distribution<int> dist(0, 999);
			int id=dist(rd);
			std::ostringstream filename;
			filename<<dir<<x<<"_"<<y<<"_"<<z<<"/result/position."<<id;
			std::ifstream f(filename.str().c_str());

			// generate particle(s)
			particle p;
			std::string line;
			while (std::getline(f, line)) {
				std::vector<double> row;
				std::istringstream iss(line);
				double num;
				while (iss >> num) {
					row.push_back(num);
				}
				p.matrix.push_back(row);
			}
			p.i=0;
			particles.push_back(p);
		}
	}
}