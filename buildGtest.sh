#! /bin/bash

VER='1.7.0'
BUILD_DIR='googletest-release-1.7.0_build'
GTEST_DIR='googletest-release-1.7.0'

CURRENTPATH=$(pwd)
wget -nv "https://github.com/google/googletest/archive/release-${VER}.tar.gz" -O "release-1.7.0.tar.gz"
tar --transform "s/*/${GTEST_DIR}/"  -zxf "release-1.7.0.tar.gz"
rm "release-1.7.0.tar.gz"
mkdir "${BUILD_DIR}" 
cd "${BUILD_DIR}"
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_CXX_FLAGS_DEBUG=-g -std=c++11 ${CURRENTPATH}/${GTEST_DIR}
make
cd "${CURRENTPATH}"

