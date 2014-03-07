select Players.name from Players, Teams where Players.team_id = Teams.id AND Players.position = "OF" AND Teams.city = "New York";

