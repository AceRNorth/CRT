#!/bin/bash
#SBATCH --array=1200-1247
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --time=12:00:00
#SBATCH --job-name=pri1_%a
#SBATCH --partition=short
#SBATCH --cluster=htc

# Use the SLURM_ARRAY_TASK_ID environment variable
ID=$SLURM_ARRAY_TASK_ID
../intel < PP$ID.csv > Res$ID.txt

