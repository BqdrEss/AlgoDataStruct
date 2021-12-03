default: COMPILATION_INST1 # you write all the names of your compilation instructions

COMPILATION_INST1: a3.2.cpp #write down the file name(s) you will use for compilaton
	g++ -o run -Wall  a3.2.cpp  # These are compilation instructions