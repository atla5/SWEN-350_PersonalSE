#!/bin/bash

echo ''
rm -rf baseball.db

echo '---------------------------------'
echo '---------------------------------'
echo "Creating tables: Teams"
sqlite3 baseball.db < create-Teams-table.sql

echo '---------------------------------'
echo "Creating table: Players "
sqlite3 baseball.db < create-Players-table.sql

echo '---------------------------------'
echo "Insert one player into Players"
sqlite3 baseball.db < insert-1-player.sql

echo '---------------------------------'
echo "Show contents of Players table"
sqlite3 baseball.db < show-Players.sql

echo '---------------------------------'
echo "Insert rest of the players"
sqlite3 baseball.db < insert-Players.sql

echo '---------------------------------'
echo "Show contents of Players table"
sqlite3 baseball.db < show-Players.sql

echo '---------------------------------'
echo '---------------------------------'
echo "Insert teams"
sqlite3 baseball.db < insert-Teams.sql

echo '---------------------------------'
echo "Show contents of Teams table"
sqlite3 baseball.db < show-Teams.sql


echo '---------------------------------'

