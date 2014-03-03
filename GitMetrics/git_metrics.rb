require 'date'

# Script that obtains various git metrics from a basic git log file

# Given an array of git log lines, count the number of commits in the log
def num_commits(lines)
  numCommits = 0
  lines.each{ |line| numCommits += 1 if line.start_with?("commit ") }
  return numCommits
end

# Given an array of git log lines, count the number of different authors
#   (Don't double-count!)
def num_developers(lines)

  #initialize counter at zero and an empty list
  numDevs = 0
  emails = []

  lines.each{ |line|
    if line.start_with?("Author: ")
      
      #email is always the last string in the line
      email = line.split(" ")[3]

      #increment numDevs only if its a novel developer email
      if not emails.include?(email)
        numDevs += 1
        emails << email
      end
    end
  }

  #emails.each{|e| puts(e) }

  return numDevs

end

# Given an array of Git log lines, compute the number of days this was in development
# Note: you cannot assume any order of commits (e.g. you cannot assume that the newest commit is first).
def days_of_development(lines)

  numDays = 0
  dates = []

  lines.each{ |line| 
    if line.start_with?("Date: ")

      #line formatted such that all date info starts at char 8 
      date = DateTime.parse(line[8..-1])
      
      if not dates.include?(date)
        numDays+=1
        dates << date
      end
    end
  }

  if dates.size == 0
    return 0
  elsif dates.size == 1
    return 1
  else 
    newest = dates[0]
    oldest = dates[1]
    dates.each{ |date|
      
      if date > newest
        newest = date
      end

      if date < oldest
        oldest = date
      end

    }
    return newest-oldest
  end
  return numDays 

end

# This is ruby idiom that allows us to use both unit testing and command line processing
# Does not get run when we use unit testing, e.g. ruby phonetic_test.rb
# These commands will invoke this code with our test data: 
#    ruby git_metrics.rb < ruby-progressbar-short.txt
#    ruby git_metrics.rb < ruby-progressbar-full.txt
if __FILE__ == $PROGRAM_NAME
  lines = []
  $stdin.each { |line| lines << line }
  puts "Nunber of commits: #{num_commits lines}"
  puts "Number of developers: #{num_developers lines}"
  puts "Number of days in development: #{days_of_development lines}"
end

