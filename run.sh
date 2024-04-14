#!/bin/bash
set -euo pipefail

BUILD_DIR="build"

# Determine the location of this script and canonicalize SRC path
SRC=$(dirname "$0")
cd "$SRC"
SRC=$(pwd -P)

${SRC}/${BUILD_DIR}/sic
