NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_strjoin.c pipex.c ft_split.c files.c ft_strnstr.c ft_strcmp.c

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
# ./pipex infile "cat" "awk NR==1" "wc -c" outfile
# ./pipex pipex.c "sleep 10" "ls" da
# ./pipex nice "t" "wc" n

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
