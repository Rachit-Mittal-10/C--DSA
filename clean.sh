#!/bin/bash
if [ -d "./bin" ]; then
  if [ "$(ls -A ./bin)" ]; then
    rm -r ./bin/*
  else
    echo "The bin directory is already empty."
  fi
else
  echo "The bin directory does not exist."
fi
