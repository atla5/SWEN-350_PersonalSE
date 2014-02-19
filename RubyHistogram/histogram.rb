#@author:Aidan Sawyer [aks5238]
#language: ruby
#activity:ruby histogram

#create new hash 'bag' to store words
bag = Hash.new(0)

#set cutoff occurence minimum for printout
minCountCutoff = 2
unless ARGV[0].nil?
    minCountCutoff = ARGV[0]
end

#create new hash 'bag' to store words
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

#select those in hash with value >= cutoff
lsSelect = bag.select{|k,v| v>=minCountCutoff}

#sort bag by value (primarily) and then key (secondarily)
lsSelect = lsSelect.sort{|k,v| 
    
    #use comparison 
    comp = k.last <=> v.last

    if comp==0
        k.first <=> v.first
    else
        comp*-1
    end

}

#find max key word-length and value in abbreviated list
maxLen = 0;
maxVal = 0;

lsSelect.each{ |k,v|

    #if current entry's key is longer than others so far, update it
    if k.length() > maxLen
        maxLen = k.length()
    end

    #if current entry's value is greater than others so far, update it
    if v > maxVal
        maxVal = v
    end
}


#print the bag contents after end of input
lsSelect.each do |k,v|   
    #printf("%-#{maxLen}.#{maxLen}s\n","#{k}: #{"*"*v}") 
    spaces = " "*(maxLen-k.length())
    stars = "*"*v
    puts("#{k}#{spaces}: #{stars}")
end 
