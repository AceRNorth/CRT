#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib> // for exit function
#include <random>  
#include <cmath> 
#include <numeric>  
#include <algorithm> 
#include <cstdio>
#include <chrono>

const int max_dev = 20; // juvenile development time (egg to adult) expressed as days left till eclosion (eclosion on day 0)
const int num_gen = 6; // number of different genotypes in the mosquito population

//void check_counts(int day, char ref); 

// Random number generator functions

double random_real();
int random_discrete(int a, int b);
long long int random_poisson(double lambda);
long long int random_binomial(long long int n, double p);
std::vector<long long int> random_multinomial(long long int n, const std::vector<double>& probs);
std::vector<long long int> random_multinomial(long long int n, const std::array<long long int, num_gen>& probs);
std::vector<long long int> random_multinomial(long long int n, const std::array<double, max_dev+1>& probs);

// Contains the total population numbers over all space (all patches) for different mosquito types
struct Totals {
	std::array<long long int, num_gen> J; // array of total number of juvenile mosquitoes with each genotype (over all space)
	std::array<long long int, num_gen> M; // array of total number of male mosquitoes with each genotype (over all space)
	std::array<long long int, num_gen> V; // array of total number of unmated female (virgin) mosquitoes with each genotype (over all space)
	std::array<long long int, num_gen> F; // array of total number of mated female mosquitoes with each genotype (over all space)
	long long int tot_J; // total number of juvenile mosquitoes of all genotypes (over all space)
	long long int tot_M; // total number of male mosquitoes of all genotypes (over all space)
	long long int tot_V; // total number of unmated female (virgin) mosquitoes of all genotypes (over all space)
	long long int tot_F; // total number of mated female mosquitoes of all genotypes (over all space)
};	

// Contains the model parameters
struct Pars {
	// mosquito life-process parameters
	double mu_j; // juvenile density independent mortality rate per day
	double mu_a; // adult mortality rate per day 
	double beta; // parameter that controls mating rate
	double theta; // average egg laying rate of wildtype females (eggs per day)
	double alpha0; // baseline contribution to carrying capacity
	std::array<double, max_dev+1> dev_duration_probs; // array of probabilities of juvenile development duration for a new juvenile
	// (index indicates the number of days to develop or, equivalently, the age class the new juvenile starts at)
	int min_dev; // minimum development time for a juvenile (in days)
	double mean_dev; // mean juvenile development time (in days)

	// simulation area parameters
	double side; // size of the square simulation area (side x side) (km)
	int num_pat; // number of population sites chosen for the simulation

	// dispersal parameters
	double disp_rate; // adult dispersal rate
	double max_disp; // maximum distance at which two sites are connected (km)

	// aestivation parameters
	double psi; // aestivation rate
	double mu_aes; // aestivation mortality
	int t_hide1; // start day of aestivation-entering period (day number of the year), not included
	int t_hide2; // end day of aestivation-entering period (day number of the year)
	int t_wake1; // start day of aestivation-waking period (day number of the year), not included
	int t_wake2; // end day of aestivation-waking period (day number of the year)

	// gene drive parameters
	double gamma; // rate of r2 allele formation from W/D meiosis
	double xi; // somatic Cas9 expression fitness cost
	double e; // homing rate in females

	std::array<std::array<std::array <double, num_gen>, num_gen>, num_gen> f; // f_ijk is the fraction of genotype k offspring from mother with genotype i mated to father with genotype j

	// data-recording parameters
	int set_label; // 'set of runs' index label for output files
	int run_label; // 'run' index label in given set of runs for output files
};

// New classes

// Model progression parameters
struct ProgressionParams {
	const int num_runs; // number of simulation replicates to run
	const int max_t; // maximum simulated time (in days)
};

// Model area parameters
struct AreaParams {
	const int num_pat; // number of population sites chosen for the simulation
	const double side; // size of the square simulation area (side x side) (km)
};

// Model life-process parameters
struct LifeParams {
	const double mu_j; // juvenile density independent mortality rate per day
	const double mu_a; // adult mortality rate per day
	const double beta; // parameter that controls mating rate
	const double theta; // average egg laying rate of wildtype females (eggs per day)
	const double alpha0; // baseline contribution to carrying capacity
	const double mean_dev; // mean juvenile development time (in days)
	const int min_dev; // minimum development time for a juvenile (in days)
};

// Gene drive inheritance parameters
struct InheritanceParams {
	const double gamma; // rate of r2 allele formation from W/D meiosis
	const double xi; // somatic Cas9 expression fitness cost
	const double e; // homing rate in females
};

// Gene drive release model parameters
struct ReleaseParams {
	const int driver_start; // time to start releasing drive alleles into the mosquito population
	const int num_driver_M; // number of drive heterozygous (WD) male mosquitoes per release
	const int num_driver_sites; // number of gene drive release sites per year
};

// Dispersal model parameters
struct DispersalParams {
	const double disp_rate; // adult dispersal rate
	const double max_disp; // maximum distance at which two sites are connected (km)
};

// Aestivation model parameters
struct AestivationParams {
	const double psi; // aestivation rate
	const double mu_aes; // aestivation mortality
	const int t_hide1; // start day of aestivation-entering period (day number of the year), not included
	const int t_hide2; // end day of aestivation-entering period (day number of the year)
	const int t_wake1; // start day of aestivation-waking period (day number of the year), not included
	const int t_wake2; // end day of aestivation-waking period (day number of the year)
};

// Initial population values for the model
struct InitialPopsParams {
	const int initial_WJ = 10000; // array of number of initial juvenile mosquitoes with wild homozygous (WW) genotype for each age group
	const int initial_WM = 50000; // number of initial adult male mosquitoes with wild homozygous (WW) genotype
	const int initial_WV = 10000; // number of initial adult unmated female (virgin) mosquitoes with wild homozygous (WW) genotype
	const int initial_WF = 40000; // number of initial adult mated female mosquitoes with wild homozygous (WW) genotype
};

// Data-recording parameters
struct RecordParams {
	// recording window and intervals
	const int rec_start; // start time for the data recording window (in days) (non-inclusive)
	const int rec_end; // end time for the data recording window (in days) (inclusive)
	const int rec_interval_global; // time interval for global data recording/output
	const int rec_interval_local; // time interval at which to collect/record local data (in days)
	const int rec_sites_freq; // fraction of sites to collect local data for (1 is all sites, 10 is 1 in 10 etc)

	// output filename labels
	const int set_label; // 'set of runs' index label for output files
	const int run_label; // 'run' index label in given set of runs for output files
};


// Sets up and controls the flow of the simulation.
class SimController {
public:
	SimController(ProgressionParams &prog, AreaParams &area, LifeParams &life, InheritanceParams &inher,
 		ReleaseParams &rel, DispersalParams &disp, AestivationParams &aes, InitialPopsParams &initial, RecordParams &rec); 
	void run_sim();

private:
	int num_runs; // number of simulation replicates to run
	int max_t; // maximum simulated time (in days)
	
	AreaParams *area_params; // model area parameters
	LifeParams *life_params; // model life-process parameters
	InheritanceParams *inher_params; // gene drive inheritance parameters
	ReleaseParams *rel_params; // gene drive release model parameters
	DispersalParams *disp_params; // dispersal model parameters
	AestivationParams *aes_params; // aestivation model parameters
	InitialPopsParams *initial_params; // initial population values
	RecordParams *rec_params; // data-recording parameters

	// f_ijk is the fraction of genotype k offspring from mother with genotype i mated to father with genotype j
	std::array<std::array<std::array <double, num_gen>, num_gen>, num_gen> f;

	void set_inheritance(); 
	void initiate_sim();
	void run_reps(int n);
};

// Runs the model.
class Model {
public:
	Model(AreaParams &area, InitialPopsParams &initial, LifeParams &life);
	void initiate();
	void run_step(int day, const std::array<std::array<std::array <double, num_gen>, num_gen>, num_gen> &f, double disp_rate, int t_hide1, int t_hide2, int t_wake1, int t_wake2, double psi, double mu_aes);

	// Dispersal functions
	double distance(double side, std::array<double, 2> point1, std::array<double, 2> point2);
	void set_connec(double side, double max_disp);
	void adults_disperse(double disp_rate);

	// Aestivation functions
	void hide(double psi, double mu_aes);
	void wake(int day, int t_wake2);

	// Gene drive functions
	void release_gene_drive(int num_driver_M, int num_driver_sites, int num_pat);
	std::vector<int> select_driver_sites(int num_driver_sites);
	void put_driver_sites(const std::vector<int>& patches, int num_driver_M);

private:
	// simulation area parameters
	int num_pat; // number of population sites chosen for the simulation
	double side; // size of the square simulation area (side x side) (km)

	// initial population values for Patch
	int initial_WJ = 10000; // array of number of initial juvenile mosquitoes with wild homozygous (WW) genotype for each age group
	int initial_WM = 50000; // number of initial adult male mosquitoes with wild homozygous (WW) genotype
	int initial_WV = 10000; // number of initial adult unmated female (virgin) mosquitoes with wild homozygous (WW) genotype
	int initial_WF = 40000; // number of initial adult mated female mosquitoes with wild homozygous (WW) genotype

	// life-process parameters for Patch
	double mu_j; // juvenile density independent mortality rate per day
	double mu_a; // adult mortality rate per day
	double beta; // parameter that controls mating rate
	double theta; // average egg laying rate of wildtype females (eggs per day)
	double alpha0; // baseline contribution to carrying capacity
	double mean_dev; // mean juvenile development time (in days)
	int min_dev; // minimum development time for a juvenile (in days)
	std::array<double, max_dev+1> dev_duration_probs; // array of probabilities of juvenile development duration for a new juvenile
	// (index indicates the number of days to develop or, equivalently, the age class the new juvenile starts at)

	// initiation methods
	void populate_sites();
	void set_dev_duration_probs(int min_time, int max_time);

	// life-processes - interface with Patch
	void juv_get_older();
	void adults_die();
	void virgins_mate();
	void lay_eggs(const std::array<std::array<std::array <double, num_gen>, num_gen>, num_gen> &f);
	void juv_eclose();
	void update_comp();
	void update_mate();

};

// Contains the information of a local mosquito population
class Patch {
public:
	Patch(double side);
	void populate(int initial_WJ, int initial_WM, int initial_WV, int initial_WF);

	// life-processes for the local site
	void juv_get_older(int max_dev);
	void adults_die(double mu_a);
	void virgins_mate();
	void lay_eggs(const std::array<std::array<std::array <double, num_gen>, num_gen>, num_gen> &f, 
		double theta, const std::array<double, max_dev+1> &dev_duration_probs);
	void juv_eclose();
	void update_comp(double mu_j, double alpha0, double mean_dev);
	void update_mate(double beta);

	std::array<double, 2> coords; // (x, y) coordinates of the site 
	std::array<std::array<long long int, max_dev+1>, num_gen> J; // 2D array of the number of juvenile mosquitoes with each genotype and in each age group in the local site. Age ordered from oldest (0 days left to eclosion) to youngest (TL - 1 days left)
	long long int tot_J; // total number of juvenile mosquitoes in the local site
	std::array<long long int, num_gen> M; // array of the number of male mosquitoes with each genotype in the local site
	long long int tot_M; // total number of male mosquitoes in the local site
	std::array<long long int, num_gen> V; // array of total number of unmated female (virgin) mosquitoes with each genotype in the local site
	std::array<std::array<long long int, num_gen>, num_gen> F; // 2D array of the number of mated female mosquitoes F_{ij} with female genotype i and carrying mated male genotype j	
	std::array<std::array<long long int, num_gen>, num_gen> aes_F;	// 2D array of the number of mated female mosquitoes F_{ij} with female genotype i and carrying mated male genotype j that have gone into aestivation
	std::array<std::array<long long int, num_gen>, num_gen> move_F; // 2D array of the number of mated female mosquitoes F_{ij} with female genotype i and carrying mated male genotype j that will be dispersing from the local site 	
	std::array<long long int, num_gen> move_M; // array of the number of male mosquitoes with each genotype that will be dispersing from the local site
	long double comp; // survival probability per juvenile per day (both density-dependent and independent factors)
	long double mate_rate; // probability of an unmated (virgin) female mating on a given day

	// for determining connectivities between patches
	std::vector<int> connec_indices; // vector of patch indices of those patches that are connected to the selected patch
	std::vector<double> connec_weights; // vector of patch connection weights of those patches that are connected to the selected patch. Correspond to the respective element in connecIND
};

// Records model data.
class Record {
public:
	Record(RecordParams &rec_params, int run);
	void record_local(int day);
	void record_global(int day);
	void record_coords();
	void output_totals(int day);

private:
	// recording window and intervals
	int rec_start; // start time for the data recording window (in days) (non-inclusive)
	int rec_end; // end time for the data recording window (in days) (inclusive)
	int rec_interval_global; // time interval for global data recording/output
	int rec_interval_local; // time interval at which to collect/record local data (in days)
	int rec_sites_freq; // fraction of sites to collect local data for (1 is all sites, 10 is 1 in 10 etc)

	// output filename labels
	int set_label; // 'set of runs' index label for output files
	int run_label; // 'run' index label in given set of runs for output files

	std::ostringstream os1, os2, os3; // filenames
	std::ofstream local_data, global_data, coord_list; // file objects
};

// Gives the reason for invalid input.
class Exception {
public:
    Exception();
    virtual void message() = 0;
};

class OutOfBoundsException: public Exception {
public:
    OutOfBoundsException(const std::string& param);
    void message();

private:
    std::string par; // parameter that caused the exception
};

class InvalidIntervalException: public Exception {
public:
    InvalidIntervalException(const std::string& param1, const std::string& param2);
    void message();

private:
    std::string inter1; // start of the interval
    std::string inter2; // end of the interval
	
};