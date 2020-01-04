#!/bin/bash

scriptPath="$( readlink -f "$( dirname "$0" )" )/$( basename "$0" )"
currentDirectory=$(dirname $scriptPath)
directoryName=$(basename $currentDirectory)

cd $currentDirectory/..
arduino-cli compile -v --fqbn arduino:avr:micro $directoryName
