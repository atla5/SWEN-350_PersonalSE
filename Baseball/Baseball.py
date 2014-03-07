import sqlite3

def connect(db = "baseball.testing.db"):
    """
    Returns an active database connection to the specified SQLite3 DB
    """
    return sqlite3.connect(db)


def add_player(db, name, teamId, position):
    """
    Using the supplied database connection, adds a new player to the database
    and returns the record ID. If the returned ID is None, then an error
    occurred.
    """

    cursor = db.cursor()

    # Validate that the team actually exists in the database
    cursor.execute( "SELECT * FROM Teams WHERE id = ?", [teamId] )
    if cursor.fetchone() == None:
        return None

    # Insert the new player
    query = "INSERT INTO Players (name, team_id, position) values (?, ?, ?)"
    cursor.execute( query, [name, teamId, position] )
    playerId = cursor.lastrowid

    cursor.close()

    return playerId


def add_team(db, name, city):
    """
    Using the supplied database connection, adds a new team to the database and
    returns the team ID. If the returned ID is None, then an error occurred.
    """
    pass


def retrieve_player(db, name):
    """
    Using the supplied database connection, returns a list of records for all
    players with the specified name
    """
    pass


def retrieve_teams(db, name):
    """
    Using the supplied database connection, returns a list of records for all
    teams with the specified name
    """
    pass


def retrieve_all_players_with_position(db, position):
    """
    Using the supplied database connection, returns a list of all players who
    play in the specified position
    """
    pass


def retrieve_all_teams_with_city(db, city):
    """
    Using the supplied database connection, returns a list of all players who
    play in the specified city
    """
    pass


def remove_player(db, playerId):
    """
    Removes a player with the specified ID from the database
    """
    pass


def remove_team(db, teamId):
    """
    Removes a team and all players on the team with the specified ID from the
    database.
    """
    pass

def main():
    """
    May use for temporary testing
    """

if __name__ == '__main__':
    main()



