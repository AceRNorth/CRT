#include <vector>
#include <cassert>
#include "Model.h"
#include "random.h"
#include "constants.h"
#include "Patch.h"
#include "Dispersal.h"
#include "GDRelease.h"
#include "Aestivation.h"

using namespace constants;

Model::Model(ModelParams *params, const std::array<std::array<std::array <double, constants::num_gen>, constants::num_gen>, constants::num_gen> &inher_frac, SineRainfallParams *season,
 double a0_mean, double a0_var, BoundaryType boundary, DispersalType disp_type, std::vector<Point> coords)
{
	num_pat = params->area->num_pat;
	side = params->area->side;
	initial_pops = params->initial;
	min_dev = params->life->min_dev;
	alpha0_mean = a0_mean;
	alpha0_variance = a0_var;
	dev_duration_probs.fill(0);
	inher_fraction = inher_frac;

	day_sim = 0;
	sites.clear();

	if (!coords.empty()) {
		assert(coords.size() == num_pat);
		for (int i=0; i < num_pat; ++i) {
			Patch* pp = new Patch(this, params->life, alpha0(), coords[i]);
			sites.push_back(pp);
		}
	}
	else {
		for (int i=0; i < num_pat; ++i) {
			Patch* pp = new Patch(this, params->life, alpha0(), side);
			sites.push_back(pp);
		}
	}

	Aestivation* new_aestivation = new Aestivation(params->aes, sites.size());
	aestivation = new_aestivation;

	Dispersal* new_disp;
	if (disp_type == DistanceKernel) {
		new_disp = new DistanceKernelDispersal(params->disp, boundary, side);
	}
	else if (disp_type == Radial) {
		new_disp = new RadialDispersal(params->disp, boundary, side);
	}
	else {
		new_disp = new DistanceKernelDispersal(params->disp, boundary, side);
	}
	dispersal = new_disp;

	GDRelease* new_gd_release = new GDRelease(params->rel);
	gd_release = new_gd_release;

	Seasonality* new_seasonality = new SineRainfall(season);
	seasonality = new_seasonality;
}

Model::Model(ModelParams *params, const std::array<std::array<std::array <double, constants::num_gen>, constants::num_gen>, constants::num_gen> &inher_frac, InputRainfallParams *season,
 double a0_mean, double a0_var, BoundaryType boundary, DispersalType disp_type, std::vector<Point> coords)
{
	num_pat = params->area->num_pat;
	side = params->area->side;
	initial_pops = params->initial;
	min_dev = params->life->min_dev;
	alpha0_mean = a0_mean;
	alpha0_variance = a0_var;
	dev_duration_probs.fill(0);
	inher_fraction = inher_frac;

	day_sim = 0;
	sites.clear();

	if (!coords.empty()) {
		assert(coords.size() == num_pat);
		for (int i=0; i < num_pat; ++i) {
			Patch* pp = new Patch(this, params->life, alpha0(), coords[i]);
			sites.push_back(pp);
		}
	}
	else {
		for (int i=0; i < num_pat; ++i) {
			Patch* pp = new Patch(this, params->life, alpha0(), side);
			sites.push_back(pp);
		}
	}

	Aestivation* new_aestivation = new Aestivation(params->aes, sites.size());
	aestivation = new_aestivation;

	Dispersal* new_disp;
	if (disp_type == DistanceKernel) {
		new_disp = new DistanceKernelDispersal(params->disp, boundary, side);
	}
	else if (disp_type == Radial) {
		new_disp = new RadialDispersal(params->disp, boundary, side);
	}
	else {
		new_disp = new DistanceKernelDispersal(params->disp, boundary, side);
	}
	dispersal = new_disp;

	GDRelease* new_gd_release = new GDRelease(params->rel);
	gd_release = new_gd_release;

	Seasonality* new_seasonality = new InputRainfall(season);
	seasonality = new_seasonality;
}

Model::~Model() 
{
	for (auto pat : sites) {
		delete pat;
	}
	delete aestivation;
	delete dispersal;
	delete gd_release;
	delete seasonality;
}

// Returns a random value for the baseline contribution to the carrying capacity.
double Model::alpha0() 
{
   return random_lognormal(alpha0_mean, alpha0_variance);
}

// Sets up the model architecture 
void Model::initiate()
{
	populate_sites();
	set_dev_duration_probs(min_dev, constants::max_dev);
	dispersal->set_connecs(sites); 
}

// Populates all sites with a (wild) mosquito population of different types (age and sex)
void Model::populate_sites() 
{
	for (auto pat : sites) {
		pat->populate(initial_pops->initial_WJ, initial_pops->initial_WM, initial_pops->initial_WV, initial_pops->initial_WF);
	}
}

// Sets probabilities of juvenile eclosion for different age groups
void Model::set_dev_duration_probs(int min_time, int max_time) 
{
	for (int a=0; a < max_time + 1; ++a) {
        if (a >= min_time) {
            dev_duration_probs[a] = 1.0 / (max_time - min_time);
        }
        else {
            dev_duration_probs[a] = 0;
        }
    }
}

// Handles which model event to run depending on the day of the simulation.
void Model::run(int day)
{
	day_sim = day; // used later for seasonality
	if (gd_release->is_release_time(day)) {
		gd_release->release_gene_drive(sites);
	} 
	if (day > 0) {
		run_step(day);
	}
}

// Runs the daily mosquito life-processes for all sites, including dispersal and aestivation.
void Model::run_step(int day) 
{
	juv_get_older();
	adults_die();
	virgins_mate();
	dispersal->adults_disperse(sites);
	lay_eggs();
	juv_eclose();
	if (aestivation->is_hide_time(day)) aestivation->hide(sites);
	if (aestivation->is_wake_time(day)) aestivation->wake(day, sites);
}

// Returns the total number of juveniles across all ages and genotypes and across the simulation area
long long int Model::calculate_tot_J()
{
	long long int tot_J = 0;
	for (auto pat : sites) {
		tot_J += pat->calculate_tot_J();
	}
	return tot_J;
}

// Returns the total number of males across all genotypes and across the simulation area
long long int Model::calculate_tot_M()
{
	long long int tot_M = 0;
	for (auto pat : sites) {
		tot_M += pat->calculate_tot_M();
	}
	return tot_M;
}

// Returns the total number of unmated females (virgins) across all genotypes and across the simulation area
long long int Model::calculate_tot_V()
{
	long long int tot_V = 0;
	for (auto pat : sites) {
		tot_V += pat->calculate_tot_V();
	}
	return tot_V;
}

// Returns the total number of mated females across all female and carrying-male genotypes and across the simulation area
long long int Model::calculate_tot_F()
{
	long long int tot_F = 0;
	for (auto pat : sites) {
		tot_F += pat->calculate_tot_F();
	}
	return tot_F;
}

// Returns the total number of males of each genotype across the simulation area
std::array<long long int, constants::num_gen> Model::calculate_tot_M_gen() 
{
	std::array<long long int, constants::num_gen> tot_M_gen;
	tot_M_gen.fill(0);
	for (auto pat : sites) {
		std::array<long long int, constants::num_gen> m_pat = pat->get_M();
		for (int i = 0; i < constants::num_gen; ++i) {
			tot_M_gen[i] += m_pat[i];
		}
	}
	return tot_M_gen;
}

std::vector<Patch*> Model::get_sites() const
{
	return sites;
}

int Model::get_day() const
{
	return day_sim;
}

double Model::get_alpha(double alpha0)
{
	double alpha = seasonality->alpha(day_sim, alpha0);
	return alpha;
}

// Ages the juvenile population in different age groups by a day across the simulation area
void Model::juv_get_older() 
{
	for (auto pat : sites) {
		pat->juv_get_older();
	}
}

// Selects the number of adults that die in the given day and updates population numbers across the simulation area
void Model::adults_die()
{
	for (auto pat : sites) {
		pat->adults_die();
	}
}

// Selects the number of virgins that mate in the given day with a male of genotype j, and tranforms them into mated females carrying
// male genotype j. Mating is carried out in each site across the simulation area.
void Model::virgins_mate() 
{
	for (auto pat : sites) {
		pat->virgins_mate();
	}
}

// Calculates the number of eggs laid on the given day and updates the number of juveniles, depending on egg survival rates.
// Egg-laying is carried out in all sites across the simulation area.
void Model::lay_eggs()
{
	for (auto pat : sites) {
		pat->lay_eggs(inher_fraction, dev_duration_probs);
	}
}

// Turns juveniles into adults, depending on eclosion survival rate, across all sites in the simulation area.
void Model::juv_eclose()
{
	for (auto pat : sites) {
		pat->juv_eclose();
	}
}