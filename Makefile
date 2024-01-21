##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##


all:    server client

server:
		make -C server/

client:
		make -C client/
clean:
		make clean -C server/
		make clean -C client/

fclean: clean
		rm -rf myteams_server
		rm -rf myteams_cli

re:     	fclean all

.PHONY: all     clean   fclean  re server client


tests_run:
	$(CC) -o $(NAME_TEST) $(SRC_PATHS) $(SRC_TEST) $(CPPFLAGS) $(LDFLAGS_TEST)
	$(RM) *.gc*
	./$(NAME_TEST)
	$(RM) *.gc*
