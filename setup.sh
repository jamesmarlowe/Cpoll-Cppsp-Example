#!/bin/bash

export CPLUS_INCLUDE_PATH=/usr/include/zmq:$CPLUS_INCLUDE_PATH

make clean
make
cd $CPPSP_HOME
./run_application $TROOT/www -l 0.0.0.0:8080 -g g++-4.8 -m /forcedynamic.cppsm &
