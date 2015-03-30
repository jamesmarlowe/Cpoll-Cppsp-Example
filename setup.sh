#!/bin/bash

export CPLUS_INCLUDE_PATH=/usr/include/zmq:$CPLUS_INCLUDE_PATH

make clean
make
cd /home/ubuntu/Cpoll-Cppsp-Example/cppsp_0.2.3/
# build logging util
#g++ -std=c++11 -g -c -Wall -fPIC log.cpp -o log.o
g++ -std=c++11 -fpic -c log.cpp
#ar rvs log.a log.o
g++ -shared -o liblog.so log.o
#/usr/lib/ld -llog -lhiredis
sudo cp liblog.so /usr/lib/x86_64-linux-gnu
# run the thing
./run_application /home/ubuntu/Cpoll-Cppsp-Example/www -l 0.0.0.0:80 -g g++-4.8 -m /forcedynamic.cppsm -c -I/home/ubuntu/Cpoll-Cppsp-Example/util -c -llog -c -L/home/ubuntu/Cpoll-Cppsp-Example/util/ &
