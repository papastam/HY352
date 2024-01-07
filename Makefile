SHELL := /bin/bash

GPP=g++

SRCD=src
INCD=inc
BIND=bin

POKOUT=pokemon
POKOUT_BIS=pokemon_bis

CFLAGS = -I$(INCD) --std=c++17 -ggdb -Werror #TODO: remove -ggdb in release 

PERROR = $(shell stat --format=%s .compile_errors.txt)

.PHONY: dirs clean build

run: build
	@printf "\e[1mrunning:\e[0m \e[1;33m%s\e[0m\n" $(BIND)/$(POKOUT)
	@$(BIND)/$(POKOUT).out

bis: buildbis
	@printf "\e[1mrunning:\e[0m \e[1;33m%s\e[0m\n" $(BIND)/$(POKOUT_BIS)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(BIND)/$(POKOUT_BIS).out

db: build
	@printf "\e[1mrunning:\e[0m \e[1;33m%s\e[0m\n" $(BIND)/$(POKOUT)
	@gdb $(BIND)/$(POKOUT).out

bisdb: buildbis
	@printf "\e[1mrunning:\e[0m \e[1;33m%s\e[0m\n" $(BIND)/$(POKOUT_BIS)
	@gdb $(BIND)/$(POKOUT_BIS).out

build: clean dirs $(BIND)/$(POKOUT) 
buildbis: clean dirs $(BIND)/$(POKOUT_BIS)

dirs:
	@mkdir -p bin/

###########################################################################################

$(BIND)/$(POKOUT): 
	@printf "\e[1mbuilding:\e[0m \e[1;33m%s\e[0m [\e[4m%s\e[0m / \e[4m%s\e[0m] \e[1m---" $@ $(word 1, $^) $(word 2, $^)
	@$(GPP) $(CFLAGS) $(SRCD)/$(POKOUT).cpp -o $@.out 2>> .compile_errors.txt;\
	if [ $$? -eq 0 ]; then\
		printf "\e[92m SUCCESS\e[0m\n";\
	else\
		printf "\e[1;31m FAILURE\e[0;3m\n\n";\
		cat .compile_errors.txt;\
		printf "\n\e[0m";\
		truncate --size=0 .compile_errors.txt;\
	fi

$(BIND)/$(POKOUT_BIS): 
	@printf "\e[1mbuilding:\e[0m \e[1;33m%s\e[0m [\e[4m%s\e[0m / \e[4m%s\e[0m] \e[1m---" $@ $(word 1, $^) $(word 2, $^)
	@$(GPP) $(CFLAGS) $(SRCD)/$(POKOUT_BIS).cpp -o $@.out 2>> .compile_errors.txt;\
	if [ $$? -eq 0 ]; then\
		printf "\e[92m SUCCESS\e[0m\n";\
	else\
		printf "\e[1;31m FAILURE\e[0;3m\n\n";\
		cat .compile_errors.txt;\
		printf "\n\e[0m";\
		truncate --size=0 .compile_errors.txt;\
	fi

	
##################################################################################

clean:
	-rm -r $(BIND)
	-rm -f .compile_errors.txt 