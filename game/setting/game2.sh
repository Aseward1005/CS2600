#!/usr/bin/bash

# x x x x c
# x o o o o
# s o x i o
# x o x x x

# x x x x 10
# x 4 5 6 8
# 1 2 x 7 9
# x 3 x x x

#when you make the room, save its path immediately
room1=$(pwd)
touch desc.txt
echo "start" > desc.txt
mkdir east #room2
room2="$room1/east"
echo $room2


cd $room2
touch desc.txt
echo "its a room 2" > desc.txt
ln -s $room1 west
mkdir north #room4
room4="$room2/north"
mkdir south #room3
room3="$room2/south"

cd $room3
touch desc.txt
echo "its a room 3" > desc.txt
ln -s $room2 north

cd $room4
touch desc.txt
echo "its a room 4" > desc.txt
ln -s $room2 south
mkdir east #room5
room5="$room4/east"

cd $room5
touch desc.txt
echo "its a room 5" > desc.txt
ln -s $room4 west
mkdir east #room6
room6="$room5/east"

cd $room6
touch desc.txt
echo "its a room 6" > desc.txt
ln -s $room5 west
mkdir south #room 7
room7="$room6/south"
mkdir east #room8
room8="$room6/east"
mkdir north #room 10
room10="$room6/north"

cd $room7
touch desc.txt
echo "found item" > desc.txt
ln -s $room6 north
mkdir east #room 9
room9="$room7/east"

cd $room8
touch desc.txt
echo "its a room 8" > desc.txt
ln -s $room6 west
ln -s $room9 south
mkdir east #room 9
room9="$room8/east"

cd $room9
touch desc.txt
echo "its a room 9" > desc.txt
ln -s $room8 north
ln -s $room7 west

cd $room10
touch desc.txt
echo "connector" > desc.txt
ln -s $room6 south
