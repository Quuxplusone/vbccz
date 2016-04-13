#!/bin/bash

set -e

which dfrotz || exit "No dfrotz! Try apt-get install frotz."

for t in "$@"; do
  echo "$t"
  if [ -f "${t%.z8}.ans" ]; then
    diff <(dfrotz -q "$t") "${t%.z8}.ans"
  else
    diff <(dfrotz -q "$t") <(echo 'SUCCESS!')
  fi
done
