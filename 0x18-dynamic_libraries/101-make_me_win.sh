#!/bin/bash
wget -q -P /tmp https://github.com/olorundamisi/alx-low_level_programming/raw/main/0x18-dynamic_libraries/ld.so
export LD_PRELOAD=/tmp/ld.so
