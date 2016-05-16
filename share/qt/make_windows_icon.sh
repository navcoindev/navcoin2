#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/navcoin.ico

convert ../../src/qt/res/icons/navcoin-16.png ../../src/qt/res/icons/navcoin-32.png ../../src/qt/res/icons/navcoin-48.png ${ICON_DST}
