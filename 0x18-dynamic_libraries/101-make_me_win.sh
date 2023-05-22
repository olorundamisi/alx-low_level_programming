#!/bin/bash
wget -P /tmp https://github.com/olorundamisi/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD=/tmp/libinjection.so
