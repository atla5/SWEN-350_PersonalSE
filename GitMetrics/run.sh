#!/bin/bash

git log | ruby git_metrics.rb
ruby git_metrics.rb < ruby-progressbar-full.txt
