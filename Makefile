CC=gcc -c
SharedLibFlags=-fPIC -g
ProgsFlags=-Wall -Wl,-rpath,./ -o
UTILLS_LIB=libutills.h libutills.c
PRINT_DB_LIB=print_blocks.h print_blocks.c
PRINT_BLOCK_LIB=print_block.h print_block.c
DBTOCSV_LIB=dbToCsv.h dbToCsv.c
LibFiles=libutills.o
PROGS=printblock dbtocsv printblocks reloader
all: $(PROGS)

reloader: reload_db.o UtilityLibrary.so
	gcc -o reloader reload_db.o 

reload_db.o: reload_db.h reload_db.c
	$(CC) reload_db.h reload_db.c
	
printblocks: print_blocks.o UtilityLibrary.so
	gcc -std=c99 $(ProgsFlags) printblocks print_blocks.o UtilityLibrary.so

print_blocks.o: print_blocks.h print_blocks.c
	$(CC) print_blocks.h print_blocks.c

dbtocsv: dbToCsv.o UtilityLibrary.so
	gcc -std=c99 $(ProgsFlags) dbtocsv dbToCsv.o UtilityLibrary.so

dbToCsv.o: dbToCsv.h dbToCsv.c
	$(CC) dbToCsv.h dbToCsv.c

printblock: print_block.o UtilityLibrary.so
	gcc -std=c99 $(ProgsFlags) printblock print_block.o UtilityLibrary.so

print_block.o: print_block.c print_block.h
	$(CC) print_block.c print_block.h

UtilityLibrary.so: libutills.o
	gcc -shared -o UtilityLibrary.so libutills.o

libutills.o: $(UTILLS_LIB)
	$(CC) $(SharedLibFlags) $(UTILLS_LIB)

clean:
	rm *.o *.gch *.so $(PROGS) *.csv
