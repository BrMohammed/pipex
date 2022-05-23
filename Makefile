NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_strjoin.c pipex.c ft_split.c files.c ft_strnstr.c ft_strcmp.c path_finder.c count.c

RM = rm -f

$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES)
	
all : $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(NAME)

re : fclean all


#  github bigin
# ./pipex infile "cat" "awk NR==1" "wc -c" outfile
# ./pipex pipex.c "sleep 10" "ls" da
# ./pipex pipex.c "sleep 2" "cat" "ls" "jfjfjf" da

path:
	echo $$PWD

ADD = git add .

read :=	@echo "Add Commit' Plz !! \n Title -> " && read -d s  enterT\
		&& git commit -m $${enterT}

PU = git push origin master

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)
