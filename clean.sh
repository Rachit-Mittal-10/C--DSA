#!/bin/bash
if [ "$(ls -A ./bin)" ]; then
  rm -r ./bin/*
else
  echo "The bin directory is already empty."
fi
