#!/bin/bash

echo 'adding health.c, health.h, health_util.c to git'
git add health.c
git add health.h
git add health_util.c

echo 'committing'
git commit
