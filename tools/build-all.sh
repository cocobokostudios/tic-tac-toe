#!/usr/bin/env bash

cmake --clean-first -S ./ -B ./build/
pushd ./build/
make
popd