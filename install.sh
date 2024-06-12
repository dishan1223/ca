#!/bin/bash

# instructions to install
# 1. chmod +x install.sh
# 2. ./install.sh

# Compile the c++ program
g++ -o ca ca.cpp

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation Failed, Exiting."
    exit 1
fi 

# Move the executable to /usr/local/bin directory
sudo mv ca /usr/local/bin

# Check if move was successful
if [ $? -ne 0 ]; then
    echo "Move Failed. Exiting."
    exit 1
fi

# Make program file executable
sudo chmod +x /usr/local/bin/ca

# Check if chmod was successful
if [ $? -ne 0 ]; then
    echo "chmod Failed. Exiting."
    exit 1
fi

echo "Installation Successful."

