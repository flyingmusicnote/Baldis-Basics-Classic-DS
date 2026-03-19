#!/bin/bash
printf "=== BUILDING .NDS FILE ==="
printf "\n"
rm -rf build
make clean
build_output=$(make | tee /dev/tty)

printf "\n"
last_line=$(echo "$build_output" | tail -n 1)
if [ "$last_line" = "by Rafael Vuijk, Dave Murphy, Alexei Karpenko" ]; then
    printf "=== RUNNING .NDS ==="
    melonds *.nds
    exit
else
    read -p "Press any key to continue..."
fi