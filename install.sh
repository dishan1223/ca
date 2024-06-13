#!/bin/bash

# instructions to install
# 1. chmod +x install.sh
# 2. ./install.sh
# install.sh - Installs the ca program

echo "Building the program..."
make

echo "Installing the program..."
sudo make install

echo "Installation complete."
