#!/bin/bash
echo "Name the commit:"
read commit
git add .
echo Committing
git commit -m "$commit"
echo Pushing
git push -u origin master
echo Done
