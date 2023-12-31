#include "MC.hpp"

void MC::humanMove(void){
	for(auto &a : humans){
		std::uniform_int_distribution<int> dist(-1*vobj, vobj);
		bool flag=true;			// out of calculation domain?
		double dx,dy,dz;		// displacement to each of three directions
		
		while(flag){
			flag=false;
			dx=dist(rd);
			dy=dist(rd);
			//dz=dist(rd);
			double x=a.x[0]+dx;
			double y=a.x[1]+dy;
			//double z=a.x[2]+dz;
			if(x<xmin || x>xmax) flag=true;
			if(y<ymin || y>ymax) flag=true;
			//if(z<zmin || z>zmax) flag=true;
		}
		a.x[0]+=dx;
		a.x[1]+=dy;
		//a.x[2]+=dz;
	}
}