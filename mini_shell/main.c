#include "header.h"

t_cmd	*create_pipe_node()
{
	t_pipe	*ptr;

	ptr = malloc(sizeof(t_pipe));
	if (!ptr)
		return (NULL);
	ptr->type = PIPE;
	ptr->left = NULL;
	ptr->right = NULL;

	return ((t_cmd *) ptr);
}
typedef struct
{
	int			type;
	char		*str;
	struct cmd	*cmd;
	char		*file;
	int			mode;
	int			fd;
} t_redirect;

t_cmd	*create_redirection_node(char *str)
{
	t_redirect	*ptr;

	ptr = malloc(sizeof(t_redirect));
	if(!ptr)
		return (NULL);
	ptr->type = REDIR;
	ptr->str = str;
	ptr->cmd = NULL;
	ptr->file = NULL;
	ptr->mode = -1;
	ptr->fd = -1;

	return ((t_cmd *) ptr);
}

t_cmd	*create_conection_node(char *str)
{
	int i;
	t_cmd *token;

	i = 0;
	if (str[i] == '|' || str[i] == '>' || str[i] == '<')
	{
		if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
		{
			if (str[i] == '>')
				token = create_redirection_node(str);
			if (str[i] == '<')
				token = create_redirection_node(str);
		}
		if (str[i] == '|')
			token = create_pipe_node();
		if (str[i] == '>')
			token = create_redirection_node(str);
		if (str[i] == '<')
			token = create_redirection_node(str);
	}

	return (token);
}

void scan_token(t_tokens *token_stream)
{
	t_cmd	*token;
	char	**arguments;
	int		i;

	arguments = token_stream->arguments;
	i = token_stream->flag;
	while(arguments[i])
	{
		if (*arguments[i] != '|' || *arguments[i] != '>' || *arguments[i] != '<')
		{
			token = create_conection_node(*arguments[i]);
			i++;
		}
	}
	token_stream->flag = i;
}

int main()
{
	char *str;
	t_tokens *token_stream;

	while(1)
	{
		str = readline("$> ");
		token_stream->arguments = ft_split(str);
		scan_token(token_stream);
		// while(*arguments)
		// {
		// 	printf("%s\n", *arguments);
		// 	fflush(stdout);
		// 	arguments++;
		// }
	}
	return (0);
}
