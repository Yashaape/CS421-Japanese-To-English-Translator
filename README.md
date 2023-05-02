# CS421-Japanese-To-English-Translator
Part1: Scanner   
Part2: Parser  
    - use g++ parser.cpp scanner.cpp -o parser or g++ -std=c++11 parser.cpp scanner.cpp -o parser   
    - ./parser  to run the file in terminal  
      
Part3: Translator  
    - use g++ translator.cpp parser.cpp scanner.cpp -o translator  
    or  
    - use g++ -std=c++11 translator.cpp parser.cpp scanner.cpp -o translator  
    - ./translator to run output file in terminal  
      
        
Note: Ex. to test individually:  
- uncomment Main() in scanner.cpp for ex.)  
- uncomment any neccessary variables
- compile the .cpp program 
- run the output file  
- After Testing be sure to comment out Main and the Variables and Recompile before testing Parser or Translator  
- Same steps for testing parser, you'll just need to compile both parser.cpp and scanner.cpp to run it.  
- Comment out Main and any other variables again. Then Recompile.   
- Test Translator
