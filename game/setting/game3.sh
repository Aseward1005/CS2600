#!/usr/bin/bash

#o o c i x
#o o o x x
#s o o x x
#x x x x x

#7 8 9 10 x
#4 5 6 x x
#1 2 3 x x
#x x x x x

#when you make the room, save its path immediately
room1=$(pwd)
touch desc.txt
echo "start" > description.txt
mkdir east #room2
room2="$room1/east"
echo $room2
mkdir north #room4
room4="$room4/north"


cd $room2
touch description.txt
echo "its a blue room #2" > description.txt
ln -s $room1 west
mkdir north #room5
room5="$room5/north"
mkdir east #room3
room3="$room3/west"

cd $room3
touch description.txt
echo "its a yellow room #3" > description.txt
ln -s $room2 east
mkdir north #room6
room6="$room6/north"

cd $room4
touch description.txt
echo "its a gray room #4" > description.txt
ln -s $room1 south
mkdir east #room5
room5="$room5/east"
mkdir north #room7
room7="$room7/north"

cd $room5
touch description.txt
echo "its a red room #5" > description.txt
ln -s $room4 west
ln -s $room2 south
mkdir east #room6
room6="$room5/east"
mkdir north #room8
room8="$room8/north"

cd $room6
touch desc.txt
echo "its a green room #6" > description.txt
ln -s $room5 west
ln -s $room3 south
mkdir north #room9
room9="$room9/north"

cd $room7
touch description.txt
echo "its a circle room? #7" > descripiton.txt
ln -s $room4 south
mkdir east #room8
room8="$room7/east"

cd $room8
touch description.txt
echo "its a purple room #8" > desc.txt
ln -s $room7 west
ln -s $room9 east
ln -s $room5 south

cd $room9
touch description.txt
echo "connector room" > description.txt
ln -s $room8 west
ln -s $room6 south
mkdir east #room10
room10="$room10/east"

cd $room10
touch description.txt
echo "You found an Item" > description.txt
ln -s $room9 east

#move to connector at the end
cd $room9