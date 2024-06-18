##
## EPITECH PROJECT, 2023
## organized
## File description:
## Makefile
##

CC	=	gcc

TARGET	=	organized

UNIT_TESTS	=	unit_tests

CFLAGS	=	-Wall -Wextra -Wshadow -I./include

LDFLAGS	=	-L. -lmy -lshell

CRITERIONFLAGS	=	--coverage -lcriterion

SRC	=	src/main.c		\
		src/add.c		\
		src/del.c		\
		src/disp.c		\
		src/sort.c		\
		src/sort_id.c	\
		src/sort_name.c	\
		src/sort_type.c

SRCTEST	=	src/add.c		\
			src/del.c		\
			src/disp.c		\
			src/sort.c		\
			src/sort_id.c	\
			src/sort_name.c	\
			src/sort_type.c

FILETEST	=	tests/test_libc.c		\
				tests/test_my_printf.c	\
				tests/test_organized.c

OBJ	=	$(SRC:.c=.o)

all: $(TARGET)

$(TARGET):	$(OBJ)
	@echo -e "\e[1m\e[36mBuilding $(TARGET)...\e[0m"
	@$(MAKE) -C ./lib/my > /dev/null 2>&1
	@$(CC) -o $(TARGET) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@echo -e "\e[1m\e[32mBinary ready!\e[0m"

$(UNIT_TESTS):	fclean
	@$(MAKE) -C ./lib/my > /dev/null 2>&1
	@$(CC) -o $(UNIT_TESTS) $(SRCTEST) $(FILETEST) $(CRITERIONFLAGS) $(LDFLAGS)

tests_run:	$(UNIT_TESTS)
	@echo "$(UNIT_TESTS) ready!"
	@./$(UNIT_TESTS)
	@gcovr --exclude tests/

clean:
	@$(MAKE) clean -C ./lib/my > /dev/null 2>&1
	@rm -f $(OBJ)
	@rm -f *.gc*
	@rm -f coding-style-reports.log


fclean: clean
	@$(MAKE) fclean -C ./lib/my > /dev/null 2>&1
	@rm -f $(TARGET)
	@rm -f $(UNIT_TESTS)
	@echo -e "\e[1m\e[33mBinary deleted!\e[0m"

re: fclean all
