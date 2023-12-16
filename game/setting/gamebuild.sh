#!/usr/bin/bash

base=$(pwd)

$base/game.sh
con=$(pwd)
cd north
ln -s south $con

$base/game2.sh
con=$(pwd)
cd north
ln -s south $con

$base/game3.sh
