proFile: recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o mainA3.o helperA3.o
	gcc -Wall -std=c99 recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o mainA3.o helperA3.o -o bin/proFile
recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/recruitEmployee.c
printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/printAll.c
printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/printOne.c
lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/lookOnId.c
lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/lookOnFullName.c
countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/countEmployees.c
sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/sortEmployeesId.c
fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/fireOne.c
fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/fireAll.c
mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/mainA3.c
helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -g -c src/helperA3.c
clean:
	rm *.o bin/proFile
