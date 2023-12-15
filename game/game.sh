#!/usr/bin/bash

# x x x c
# x o o o
# o o x x
# s o o i

# x x x 10
# x 7 8 9
# 5 6 x x
# 1 2 3 4

#when you make the room, save its path immediately
room1=$(pwd)
touch desc.txt
echo "start" > desc.txt
mkdir north #room5
room5="$room1/north"
mkdir east #room2
room2="$room1/east"
echo $room2


cd $room2
touch desc.txt
echo "its a room 2" > desc.txt
ln -s $room1 west
mkdir north #room6
room6="$room2/north"
mkdir east #room3
room3="$room2/east"

cd $room3
touch desc.txt
echo "its a room 3" > desc.txt
ln -s $room2 west
mkdir east #room 4
room4="$room3/east"

cd $room4
touch desc.txt
echo "found an item" > desc.txt
ln -s $room3 west

cd $room5
touch desc.txt
echo "its a room 5" > desc.txt
ln -s $room1 south
ln -s $room6 east

cd $room6
touch desc.txt
echo "its a room 6" > desc.txt
ln -s $room5 west
ln -s $room2 south
mkdir north #room 7
room7="$room6/north"

cd $room7
touch desc.txt
echo "its a room 7" > desc.txt
ln -s $room6 south
mkdir east #room 8
room8="$room7/east"

cd $room8
touch desc.txt
echo "its a room 8" > desc.txt
ln -s $room7 west
mkdir east #room 9
room9="$room8/east"

cd $room9
touch desc.txt
echo "its a room 9" > desc.txt
ln -s $room8 west
mkdir north #room10
room10="$room9/north"

cd $room10
touch desc.txt
echo "connector" > desc.txt
ln -s $room9 south
