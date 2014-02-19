#@author:Aidan Sawyer [aks5238]
#language: ruby
#activity:ruby histogram

#for each line in standard input
$stdin.each{ |line| 

    #chomp off any terminating characters (\n)
    lsWords = line.chomp().split(/ +/)

    #for each individual 'word' in line
    lsWords.each{ |word|

        #remove all non-alphabetic or non-space characters
        word = word.gsub(/\p{^Alpha}/,"")

        #remove any leading spaces
        word = word.sub(/ +/,"")

        #print word
        puts(word)
    }
}
