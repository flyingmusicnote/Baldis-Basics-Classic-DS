#!/bin/sh

# OBJ2DL PATH
NITRO_ENGINE=/opt/blocksds/external/nitro-engine
TOOLS=$NITRO_ENGINE/tools
OBJ2DL=$TOOLS/obj2dl/obj2dl.py

# INPUT
# This gets the "".obj from /raw_data and sends a "".bin into /data
NAME=mario
WID=128
HEI=64
SCA=0.4

python3 $OBJ2DL \
    --input raw_data/$NAME.obj \
    --output data/$NAME.bin \
    --texture $WID $HEI \
    --scale $SCA
