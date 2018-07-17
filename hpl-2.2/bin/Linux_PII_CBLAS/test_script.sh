#!/bin/bash

#SBATCH -q debug
#SBATCH -N 64
#SBATCH -t 00:20:00
#SBATCH -J my_job
#SBATCH -L SCRATCH
#SBATCH -C haswell


mpirun -np 4 ./xhpl $1 $2
