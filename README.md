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

The InputFiles/ folder contains prepared input data for running gene drive field trial simulations based on the Houet province, Burkina Faso.
File Naming Convention

Simulation input files follow this format:
CC_Set_X_Y_dispZ.txt

    X = Number of sites: 12, 24, or 12B
    (12B uses a larger simulation area with greater separation between sites)
    Y = Randomisation index (0 to 100)
        Y=0: No gene drive mosquitoes released (control/comparator run)
        Y=1..100: Random assignment of sites to control or release groups
    Z = Dispersal level (1 to 7)

Additional Data Files

Also located in InputFiles/:

    gamb_mortality_Jan26.csv — Daily mortality rates for Anopheles gambiae (39-year period)
    RainDailyAvAv.csv — Estimated daily rainfall
    Rellist.csv — Release days schedule

How to Run a Simulation

    Generate or choose a parameter file
    An example is provided: Parameter13301.txt in the InputFiles/ folder.

    Run the simulation
    Copy the compiled executable gdsimsapp into the InputFiles/ folder, then run:

    ./gdsimsapp < Parameter13301.txt > Out.txt

    (On Windows: gdsimsapp.exe < Parameter13301.txt > Out.txt)

Output

The simulation will create an output_files/ folder containing three result files (for run 1):

    CoordinateList13301run1.txt — Coordinates of all simulation sites
    LocalData13301run1.txt — Mosquito counts and gene drive frequencies at control (index 4) and release (index 5) sites
    Totals13301run1.txt — Total mosquitoes of each genotype across the entire simulation



