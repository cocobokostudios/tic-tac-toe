#!/usr/bin/env bash

echo "Install dev tools..."

# vcpkg
echo "START - vcpkg"

git clone https://github.com/Microsoft/vcpkg.git ./tools/vcpkg
./tools/vcpkg/bootstrap-vcpkg.sh

./tools/vcpkg/vcpkg --version
./tools/vcpkg/vcpkg install cmocka

echo "END - vcpkg"
