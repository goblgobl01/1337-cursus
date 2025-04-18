#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum
{
	command,
	pp,
	redirections
} e_num;

typedef struct ASTNode
{
	e_num	type;
	union
	{
		char **arguments;
		struct
		{
			struct ASTNode	*left;
			struct ASTNode	*right;
		} connection;
	} data;
} t_ast;

typedef struct tokens
{
	t_ast	*token;
	t_ast	*next_token;
} t_tokens;

char	**ft_split(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);

#endif