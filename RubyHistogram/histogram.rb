#@author:Aidan Sawyer [aks5238]
#language: ruby
#activity:ruby histogram

    
$stdin.each{ |line| 
    #get line from standard input. chomp off any terminating characters (\n)
    line = STDIN.gets.chomp()

    #remove all non-alphabetic or non-space characters
    line = line.gsub(/ /,"")

    #remove any leading spaces
    line = line.sub(/ +/,"")


    puts(line)
}
