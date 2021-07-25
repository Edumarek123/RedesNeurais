#!/bin/bash

clear

g++ -o model model.cpp ../libs/rede_neural_lib.cpp ../libs/matriz_lib.cpp

./model
