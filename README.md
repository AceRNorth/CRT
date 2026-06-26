# CRT

Codes for the CRT model — a C++ metapopulation simulator for mosquito dynamics with gene drive (GDSiMS).

## About

This repository contains the source code for a spatially-explicit simulation model of mosquito populations, including seasonality, dispersal, and gene drive release strategies.

### Key Features
- Metapopulation framework with multiple patches
- Gene drive inheritance and release mechanics
- Seasonal rainfall-driven dynamics
- Flexible parameter sets for different scenarios
- Mathematica notebooks for parameter generation and analysis

## Languages
- **C++** (core simulation)
- **Wolfram Language (Mathematica)** (parameter setup & analysis)

## Requirements
- C++20 compatible compiler
- CMake ≥ 3.5.0

## Quick Start (bash)
 
1. Clone the repository:
  
	git clone https://github.com/AceRNorth/CRT.git
	cd CRT

2. Create a build directory:

	mkdir build && cd build

3. Configure with Cmake:

	cmake ..

4. Build the project:

	cmake --build .

5. Run the simulator:

	./gdsimsapp          # Linux / macOS
	or
	gdsimsapp.exe        # Windows
        
## Input files and how to use them

In the InputFiles/ folder there is a set of input files for running gene drive field trial simulations in the Houet province of Burkina Faso. These have format: CC_Set_X_Y_dispZ.txt where X is 12, 24 or 12B (referring to the total number of control and release sites; 12B differs from 12 in that the simulation area is larger so the sites have greater separation), Y is an index from 0 to 100, and Z is dispersal level which ranges from 1 to 7. Also in the InputFiles folder there is a file of (Anopheles gambiae) mosquito daily mortality estimated over a 39 year period (gamb_mortality_Jan26.csv), a file of estimated daily rainfall (RainDailyAvAv.csv) and a file of release days (Rellist.csv). To run a simulation using these files, a parameter file must be generated with the filenames as input parameters. An example parameter file is Parameter13301.txt in the InputFiles folder. To run a simulation with these parameters, move the compiled gdsimsapp executable into Input files and run (in bash)

	./gdsimsapp<Parameter13301.txt>Out.txt

This will make an output_files folder with 3 files:

	CoordinateList13301run1.txt  LocalData13301run1.txt  Totals13301run1.txt
 
The first is a list of the coordinates of all the sites in the simulation, the second records count and gene drive frequencies at the control (index 4) and release (index 5) sites, and the third records the total mosquitoes of each genotype across the simulation.


