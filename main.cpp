#include "MC.hpp"

int main(void){
	MC *mc = new MC();
	mc->init();
	mc->loop();
		
	return 0; 
}