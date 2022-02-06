NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_strjoin.c pipex.c ft_split.c files.c ft_strnstr.c ft_strcmp.c path_finder.c count.c

FILES2 =  ft_strjoin.c pipex_bonus.c ft_split.c files.c ft_strnstr.c ft_strcmp.c path_finder.c  here_doc.c count.c

RM = rm -f


$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES)

$(NAME2):  $(FILES2)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES2)


all:$(NAME)

clean :
	@$(RM) $(NAME)

bonus : $(NAME2)

clean_bonus :
	@$(RM) $(NAME2)

fclean : clean
	@$(RM) $(NAME) $(NAME2)

re : fclean all


#  github bigin
# ./pipex infile "cat" "awk NR==1" "wc -c" outfile
# ./pipex pipex.c "sleep 10" "ls" da
# ./pipex pipex.c "sleep 2" "cat" "ls" "jfjfjf" da

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
