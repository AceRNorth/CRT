#ifndef GENERALMETAPOP_SETS_H
#define GENERALMETAPOP_SETS_H
#include "InputParams.h"

/** Parameter set 1 - default.
 * @details Includes gene drive and dispersal but no aestivation or seasonality.
 */
InputParams set1 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 1
};

/** Parameter set 2 - 1 population.
 * @details Includes gene drive and dispersal but no aestivation or seasonality.
 */
InputParams set2 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 1,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 2
};

/** Parameter set 3 - no dispersal.
 * @details No dispersal via @ref disp_rate = 0. Includes gene drive but no aestivation or seasonality.
 */
InputParams set3 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.0,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 3
};

/** Parameter set 4 - full mixing.
 * @details Full dispersal mixing via @ref disp_rate = 1. Includes gene drive too but no aestivation or seasonality.
 */
InputParams set4 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 1.0,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 4
};

/** Parameter set 5 - 1 day.
 * @details Includes gene drive and dispersal but no aestivation or seasonality.
 */
InputParams set5 = {
   .num_runs = 2, 
    .max_t = 1,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 1,
    .rec_sites_freq = 1,
    .set_label = 5
};

/** Parameter set 6 - high fitness cost.
 * @details Includes gene drive and dispersal but no aestivation or seasonality.
 */
InputParams set6 = {
   .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.7, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 6
};

/** Parameter set 7 - low aestivation.
 * @details Includes gene drive and dispersal too but no seasonality.
 */
InputParams set7 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.01,
    .mu_aes = 0.95, 
    .t_hide1 = 280,
    .t_hide2 = 310, 
    .t_wake1 = 100, 
    .t_wake2 = 130,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 7
};

/** Parameter set 8 - high aestivation.
 * @details Includes gene drive and dispersal too but no seasonality.
 */
InputParams set8 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.5,
    .mu_aes = 0.8, 
    .t_hide1 = 280,
    .t_hide2 = 310, 
    .t_wake1 = 100, 
    .t_wake2 = 130,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 8
};

/** Parameter set 9 - no gene drive.
 * @details No gene drive via @ref num_driver_M = @ref num_driver_sites = 0. Includes dispersal but no aestivation or seasonality.
 */
InputParams set9 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 0, 
    .num_driver_sites = 0,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 9
};

/** Parameter set 10 - high gene drive.
 * @details High gene drive via high @ref num_driver_sites, @ref num_driver_sites = @ref num_pat. Includes dispersal too but no aestivation or seasonality.
 */
InputParams set10 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 50,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 10
};

/** Parameter set 11 - 1 population, full dispersal.
 * @details Full dispersal via @ref disp_rate = 1. Includes gene drive too but no aestivation or seasonality.
 */
InputParams set11 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 1,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 1,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 11
};

/** Parameter set 12 - low seasonality, default rainfall.
 * @details Default rainfall contribution to seasonality modelled as a sinusoid wave - see @ref SineRainfall. Low seasonality determined by low @ref amp parameter. Includes gene drive and dispersal too but no aestivation.
 */
InputParams set12 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 1.0,
    .alpha0_variance = 0.0,
    .alpha1 = 100000.0,
    .amp = 0.1,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 12
};

/** Parameter set 13 - high seasonality, default rainfall.
 * @details Default rainfall contribution to seasonality modelled as a sinusoid wave - see @ref SineRainfall. High seasonality determined by high @ref amp parameter. Includes gene drive and dispersal too but no aestivation.
 */
InputParams set13 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 1.0,
    .alpha0_variance = 0.0,
    .alpha1 = 100000.0,
    .amp = 1.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 13
};

/** Parameter set 14 - low seasonality, pre-defined rainfall.
 * @details Pre-defined rainfall contribution to seasonality modelled from rainfall data file - see @ref InputRainfall. Low seasonality determined by a low @ref alpha0_mean : @ref alpha1 ratio. Includes gene drive and dispersal too but no aestivation.
 */
InputParams set14 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 10000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 100000.0,
    .amp = 0.0,
    .resp = 1.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 14
};

/** Parameter set 15 - high seasonality, pre-defined rainfall.
 * @details Pre-defined rainfall contribution to seasonality modelled from rainfall data file - see @ref InputRainfall. Low seasonality determined by a high @ref alpha0_mean : @ref alpha1 ratio. Includes gene drive and dispersal too but no aestivation.
 */
InputParams set15 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 10.0,
    .alpha0_variance = 0.0,
    .alpha1 = 100000.0,
    .amp = 0.0,
    .resp = 1.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 15
};

/** Parameter set 16 - alpha0 variance.
 * Includes a non-zero @ref alpha0_variance to vary alpha0, the carrying capacity baseline, across patches. Includes gene drive and dispersal but no aestivation or seasonality.
 * @see Model::alpha0()
*/
InputParams set16 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 1000.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 16
};

/** Parameter set 17 - multiple release times.
 *  @details Includes gene drive and dispersal but no aestivation or seasonality.
 *  @warning Same as set 1, made to be used with a multiple gene drive release times file. 
 */
InputParams set17 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 1.0/15.0,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 10000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 100000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 17
};

/** Parameter set 18 - high juvenile survival probability.
 * @details High juvenile survival probability via high @ref comp_power. Includes gene drive and dispersal but no aestivation or seasonality.
 */
InputParams set18 = {
    .num_runs = 2, 
    .max_t = 1000,
    .num_pat = 50,
    .mu_j = 0.05, 
    .mu_a = 0.125,
    .beta = 100.0,
    .theta = 9.0,
    .comp_power = 0.2,
    .min_dev = 10,
    .gamma = 0.025,
    .xi = 0.2, 
    .e = 0.95,
    .driver_start = 200,
    .num_driver_M = 1000, 
    .num_driver_sites = 5,
    .disp_rate = 0.01,
    .max_disp = 0.2, 
    .psi = 0.0,
    .mu_aes = 0.0, 
    .t_hide1 = 0,
    .t_hide2 = 0, 
    .t_wake1 = 0, 
    .t_wake2 = 0,
    .alpha0_mean = 1000000.0,
    .alpha0_variance = 0.0,
    .alpha1 = 0.0,
    .amp = 0.0,
    .resp = 0.0,
    .rec_start = 0,
    .rec_end = 1000,
    .rec_interval_global = 1,
    .rec_interval_local = 200,
    .rec_sites_freq = 1,
    .set_label = 18
};

#endif //GENERALMETAPOP_SETS_H