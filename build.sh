#!/bin/bash

# 路径、密码等定义
PASSWORD=orangepi
CURRENT_DIR=$(cd $(dirname $0); pwd)
OUTPUT_FILE_DIR=$CURRENT_DIR/output_file
SCP_TARGET_DIR=orangepi@192.168.0.104:/home/orangepi/workspace
SCP_SOURCE_DIR=$OUTPUT_FILE_DIR

clear & clear

# 编译驱动
cd $CURRENT_DIR
make

# 编译APP
cd $CURRENT_DIR/app
make ARCH=arm64

# 搬运生成的需要用的文件
rm $SCP_SOURCE_DIR/*
cp $CURRENT_DIR/*.ko $SCP_SOURCE_DIR
cp $CURRENT_DIR/run.sh $SCP_SOURCE_DIR
cp $CURRENT_DIR/app/build/lysi_app $SCP_SOURCE_DIR

# scp文件传输
sshpass -p ${PASSWORD} scp ${SCP_SOURCE_DIR}/* ${SCP_TARGET_DIR}

# 清除生成的文件
cd $CURRENT_DIR
make clean
cd $CURRENT_DIR/app
make clean
