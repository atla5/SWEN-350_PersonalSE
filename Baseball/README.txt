
To create the baseball.db transfer all of these sql files to unix system with sqlite3 installed.

NOTE you can run the commands step by step to show your audience how the database is made.
The commands within the script are of the type:

	sqlite3 baseball.db < insert-1-player.sql

where the contents of  insert-1-player.sql

	insert into Players (name, team_id, position) values ("Ichiro Suzuki", 1, "OF") ;

----

TO SETUP THE DATABASE run the setup-baseball.sh

Confirm output of the kind:


Show contents of Players table
1|Ichiro Suzuki|1|OF
2|Derek Jeter|1|SS
3|Jacoby Ellsbury|2|OF
4|Pablo Sandoval|3|3B
5|Dustin Pedroia|2|2B
6|Matt Holiday|5|0F
7|Carlos Beltran|5|OF
8|Ike Davis|4|1B
9|Stephen Drew|2|SS
---------------------------------
---------------------------------
Insert teams
---------------------------------
Show contents of Teams table
1|Yankees|New York
2|Red Sox|Boston
3|Giants|San Francisco
4|Cardinals|St. Louis
5|Mets|New York
