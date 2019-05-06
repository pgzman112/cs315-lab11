To the best of my knowledge this program works perfectly. I am including 3 test text files ( the ones used in the lab instructions ), which my program sovles perfectly which
the exception of test2.txt when not using a hash function, I have not waited to see how long it would take to solve it, but when using a hash table it takes about 24 
seconds with a size of 10007, then down to .002 with a size of 50,021. 

I was unclear from the instructions how i was supposed to have my program prompt user for 1, 2, or 3 and then "Otherwise" ask for a new board position, so i added a 4th option
which basically restarts the program from the begining. I dont like that 3 is quit and 4 is restart it seems like a bad design but i did not want to blatantly not follow
instructions.

Also added a cin failstate when asking for user input with numbers, and also check to make sure that the file you ask to open is a real file, if not it prompts again.

