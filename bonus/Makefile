NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES =  ft_strjoin_bonus.c pipex_bonus.c ft_split_bonus.c files_bonus.c ft_strnstr_bonus.c ft_strcmp_bonus.c path_finder_bonus.c  here_doc_bonus.c count_bonus.c

RM = rm -f


$(NAME):  $(FILES)
	$(CC) $(CFLAGS)  -o $(NAME) $(FILES)

all : $(NAME)

clean_bonus :
	@$(RM) $(NAME)

clean :
	@$(RM) $(NAME)

fclean : clean
	@$(RM) $(NAME)

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
