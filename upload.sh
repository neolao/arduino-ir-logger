#!/bin/bash

scriptPath="$( readlink -f "$( dirname "$0" )" )/$( basename "$0" )"
currentDirectory=$(dirname $scriptPath)
directoryName=$(basename $currentDirectory)

cd $currentDirectory/..
arduino-cli upload -p $1 --fqbn arduino:avr:micro -t -v $directoryName
