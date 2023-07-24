#include "MC.hpp"

void MC::loop(void){
	for(itime=0;itime<3600;itime++){
		humanMove();
		particleGeneration();
		output();
	}
}