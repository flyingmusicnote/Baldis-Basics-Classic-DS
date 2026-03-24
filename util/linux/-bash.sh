#!/bin/bash
printf "=== BUILDING .NDS FILE ==="
printf "\n"
if make -j32; then
    echo "=== RUNNING .NDS ==="
    melonds *.nds
else
    read -p "Press any key to continue..."
fi