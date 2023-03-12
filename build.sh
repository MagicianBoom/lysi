#!/bin/bash

PASSWORD=orangepi
CURRENT_DIR=$(cd $(dirname $0); pwd)
OUTPUT_FILE_DIR=$CURRENT_DIR/output_file
SCP_TARGET_DIR=orangepi@192.168.0.104:/home/orangepi/workspace
SCP_SOURCE_DIR=$OUTPUT_FILE_DIR

make

cp $CURRENT_DIR/*.ko $SCP_SOURCE_DIR

sshpass -p ${PASSWORD} scp ${SCP_SOURCE_DIR}/* ${SCP_TARGET_DIR}

make clean
