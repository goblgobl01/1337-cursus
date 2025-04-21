#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum e_type
{
	EXEC,
	PIPE,
	REDIR
} t_type;

typedef struct 
{
	int type;
} t_cmd;

typedef struct
{
	t_type type;
	char *path;
	char *arg;
	char **arguments;
} t_exec;

typedef struct
{
	t_type type;
	t_exec *left;
	t_exec *right;
} t_pipe;

typedef struct
{
	int			type;
	char		*str;
	struct cmd	*cmd;
	char		*file;
	int			mode;
	int			fd;
} t_redirect;

typedef struct tokens
{
	char	**arguments;
	t_cmd	*token;
	t_cmd	*next_token;
	int		flag;
} t_tokens;

char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
void	scan_token(t_tokens *token_stream)


#endif