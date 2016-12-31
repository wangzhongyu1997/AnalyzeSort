gg=g++ -std=c++11 
objects=main.o  
analyze.exe:$(objects)
	$(gg) -o analyze.exe  $(objects) 
main.o:main.cpp  
	$(gg)  -c main.cpp 
.PHONY : clean 

clean:
	del  $(objects)