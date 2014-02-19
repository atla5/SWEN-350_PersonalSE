#@author:Aidan Sawyer [aks5238]
#language: ruby
#activity:ruby histogram


bag = Hash.new(0)

#for each line in standard input
$stdin.each{ |line| 

    #chomp off any terminating characters (\n)
    line = line.chomp()

    #remove all non-alphabetic or non-space characters
    line = line.gsub(/\p{^Alpha}/,"")

    #remove any leading spaces
    line = line.sub(/ +/,"")

    #split line into a list of words
    lsWords = line.split(/ +/)

    #for each individual 'word' in line
    lsWords.each{ |word|

        #add word to bag and increment count
        bag[word] += 1
    }

}

#print the bag contents  after end of input
bag.each{ |k,v| puts("#{k}: #{v}") }
