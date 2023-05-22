#!/bin/bash
wget -O /tmp/libmask.so https://github.com/olorundamisi/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libmask.so
export LD_PRELOAD=/tmp/libmask.so
