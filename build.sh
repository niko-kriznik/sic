#!/bin/bash
set -uo pipefail

BUILD_DIR="build"
NO_BUILD=0
NO_COMPLETE_CLEAN=0
NO_GENERATE=0
NO_NINJA_CLEAN=0

###
### CLI argument parsing
###
USAGE_MESSAGE="Usage: $(basename $0) [-b | --no-build] [-c | --no-complete-clean] [-g | --no-generate] [-n --no-ninja-clean] [-h | --help]"

PARSE_ARGS=$(getopt -o bcgnh --long no-build,no-complete-clean,no-generate,no-ninja-clean,help -- "$@")
if [[ $? -ne 0 ]]; then
    echo ${USAGE_MESSAGE} 1>&2
    exit 1
fi

eval set -- "$PARSE_ARGS"
while [ : ]; do
    case "$1" in
    -b | --no-build)
        NO_BUILD=1
        shift
        ;;
    -c | --no-complete-clean)
        NO_COMPLETE_CLEAN=1
        shift
        ;;
    -g | --no-generate)
        NO_GENERATE=1
        shift
        ;;
    -n | --no-ninja-clean)
        NO_NINJA_CLEAN=1
        shift
        ;;
    -h | --help)
        echo ${USAGE_MESSAGE}
        shift
        exit 0
        ;;
    --)
        shift
        break
        ;;
    esac
done

###
### Build logic
###
set -e

# Determine the location of this script and canonicalize SRC path
SRC=$(dirname "$0")
cd "$SRC"
SRC=$(pwd -P)

if [[ -f ${SRC}/.env ]]; then
    # https://stackoverflow.com/a/20909045
    export $(grep -v '^#' ${SRC}/.env | xargs -d '\n') > /dev/null
fi

if [[ ${NO_COMPLETE_CLEAN} -ne 1 ]] && [[ ${NO_COMPLETE_CLEAN} -ne 1 ]]; then
    rm -r ${SRC}/${BUILD_DIR}
fi

if [[ ${NO_GENERATE} -ne 1 ]]; then
    cmake -G "Ninja" -B ${SRC}/${BUILD_DIR}
fi

if [[ ${NO_NINJA_CLEAN} -ne 1 ]]; then
    ninja clean -C ${SRC}/${BUILD_DIR}
fi

if [[ ${NO_BUILD} -ne 1 ]]; then
    cmake --build ${SRC}/${BUILD_DIR} -j
fi
