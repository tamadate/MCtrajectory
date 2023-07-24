#include "const.hpp"

class MC {
	private:
		
  	public:
		int particleRate=10; // #/s
		std::string dir="/home/tama3rdgen/room/case15/results/";
		std::string dir_out="/home/tama3rdgen/room/case15_particle/";
		std::random_device rd;

		int itime;
	
		void init(void);
		void loop(void);
		void particleGeneration(void);
		void humanMove(void);
		void output(void);

		std::vector<point> humans;
		std::vector<particle> particles;
		
		MC(void){};
		~MC(void){};
};
