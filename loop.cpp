#include "MC.hpp"

void MC::loop(void){
	for(itime=0;itime<36000;itime++){
		if(moveOBJ) humanMove();
		if(itime%injectionRate==0) particleGeneration();
		output();
	}
}