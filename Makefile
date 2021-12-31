NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_strjoin.c pipex.c ft_split.c

AR = ar -rc

RM = rm -f

objets = $(FILES:.c=.o)

$(NAME):$(objets)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES) -g

all:$(NAME)

clean :
	@$(RM) $(objets)

fclean : clean
	@$(RM) $(NAME)

re : fclean all


#  github bigin

ADD = git add .

read :=	@echo "Add Commit Plz !!" && read -p "-> " enter \
		&& git commit -m $${enter}

PU = git push origin master

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)
