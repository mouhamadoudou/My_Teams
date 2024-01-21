##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	myteams_server

CC	=	gcc

DIR	=	src/

DIR_TEST	=	tests/

DIR_INC = include/

SRC	=	main.c	\
		Init_server_and_dir/init_server.c	\
		Init_server_and_dir/init_resp_cmd.c	\
		Init_server_and_dir/init_directory.c	\
		Command/cmd.c 	\
		Command/cmd1.c 	\
		Map_and_other_file/map.c	\
		Map_and_other_file/parse.c	\
		Map_and_other_file/str_to_word_array.c	\
		Map_and_other_file/error_manage.c	\
		Manage_client_connexion/manage_client.c	\
		Manage_client_connexion/manage_connexion.c	\
		Command/init_cmd.c	\
		save/open_folder.c 	\
		save/save.c 	\
		save/get_file_infos.c	\
		init_manage_data.c \
		Dump_Client_data/dump_client.c	\
		Dump_Client_data/load_new_client_in_db.c	\
		Dump_Team_data/dump_new_team.c	\
		Dump_Team_data/dump_team.c 	\
		Load_Client_data/load_client.c	\
		Load_Client_data/get_client_data.c	\
		Load_Team_data/load_team.c	\
		Load_Team_data/set_channel_msg.c	\
		Load_Team_data/set_member.c	\
		Load_Team_data/set_thread.c	\
		when_client_connected.c \

SRC_PATHS	=	$(addprefix $(DIR), $(SRC))

SRC_TEST	=	$(DIR_TEST)unit_tests.c

OBJ	=	$(SRC_PATHS:.c=.o)

INCLUDE	=	-I$(DIR_INC) -I ./libs/myteams -I ../shared_files

CPPFLAGS	+=	-std=gnu17 -Wall -Wextra $(INCLUDE) -I/usr/include/uuid/ -luuid -L ../libs/myteams/ -lmyteams -g3

LDFLAGS_TEST = --coverage -lcriterion

LDFLAGS	=

NAME_TEST	=	unit_tests

.PHONY:	re fclean clean all debug

all:	$(NAME)
		cp $(NAME) ../

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)
	$(RM) *.gc*

re:	fclean all

debug:	CFLAGS += -g3

debug:	all

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

tests_run:
	$(CC) -o $(NAME_TEST) $(SRC_PATHS) $(SRC_TEST) $(CPPFLAGS) $(LDFLAGS_TEST)
	$(RM) *.gc*
	./$(NAME_TEST)
	$(RM) *.gc*
