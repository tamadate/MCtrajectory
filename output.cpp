#include "MC.hpp"

void MC::output(void){
	// Append "0" to the base directory path
	std::filesystem::path dir_path = dir_out + std::to_string(itime) + "/lagrangian/could1";

    // Check if the directory exists and create it if it doesn't
    if (!std::filesystem::exists(dir_path)) {
        std::filesystem::create_directories(dir_path);
    }
	// Set the file path
    std::filesystem::path file = dir_path / "positions";
    // Open the file
    std::ofstream f(file);

	int Np=particles.size();

	// Write the header to the file
    f << "/*--------------------------------*- C++ -*----------------------------------*\\" << std::endl;
    f << "| =========                 |                                                 |" << std::endl;
    f << "| \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |" << std::endl;
    f << "|  \\    /   O peration     | Version:  2206                                  |" << std::endl;
    f << "|   \\  /    A nd           | Website:  www.openfoam.com                      |" << std::endl;
    f << "|    \\/     M anipulation  |                                                 |" << std::endl;
    f << "\\*---------------------------------------------------------------------------*/" << std::endl;
    f << "FoamFile" << std::endl;
    f << "{" << std::endl;
    f << "\tversion     2.0;" << std::endl;
    f << "\tformat      ascii;" << std::endl;
    f << "\tclass       Cloud<basicKinematicCollidingParcel>;" << std::endl;
    f << "\tobject      positions;" << std::endl;
    f << "}" << std::endl;
    f << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //" << std::endl;
    f << Np << std::endl;
    f << "(" << std::endl;
	
    int ip = 1;
    for (auto it = particles.begin(); it != particles.end();) { /* no increment here */
        double x = it->matrix[it->i][0];
        double y = it->matrix[it->i][1];
        double z = it->matrix[it->i][2];
        f << "(" << x << " " << y << " " << z << ") " << ip << std::endl;
        if (it->i + 1 == it->matrix.size()) {
            it = particles.erase(it);  // erase returns the iterator to the next element
        } else {
            ++it->i;
            ++it;
        }
        ++ip;
    }
	f << ")" << std::endl;
}