#!/bin/bash


# instructions to uninstall
# 1. chmod +x uninstall.sh
# 2. ./uninstall.sh
# uninstall.sh - Uninstalls the ca program

echo "Uninstalling the program..."
sudo make uninstall

echo "Cleaning up..."
make clean

echo "Uninstallation complete."
