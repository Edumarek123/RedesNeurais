#!/bin/bash

clear

g++ -o mnist main.cpp ../libs/rede_neural_lib.cpp ../libs/matriz_lib.cpp

./mnist

# chmod run.sh
