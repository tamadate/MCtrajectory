#include "const.hpp"

class MC {
	private:
		
  	public:
		int particleRate=1; // particles per injection
		int injectionRate=10;	// injection per flame
		std::string dir="/home/tama3rdgen/room/case15/result/";
		//std::string dir_out="/home/tama3rdgen/room/case15_particle/";
		std::string dir_out="/home/tama3rdgen/room/100fps_360s/";
		std::random_device rd;

		int itime;

		
		void init(void);
		void loop(void);
		void particleGeneration(void);
		int Nparticle=10000;
		void output(void);

		bool moveOBJ=false;		// if object is moving ?
		double vobj=5;	// object (human) displacement per unit time [cm/s]
		void humanMove(void);

		std::vector<point> humans;
		std::vector<particle> particles;
		
		MC(void){};
		~MC(void){};
};
