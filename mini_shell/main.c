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

t_cmd	*create_connection_node(char *str)
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

t_cmd	*create_command_node(t_tokens	*token_stream)
{
	t_exec *ptr;

	ptr = malloc(sizeof(t_exec));
	ptr->type = EXEC;
	ptr->arg = token_stream->arguments[token_stream->flag];
	ptr->arguments = NULL;
	ptr->path = NULL;

	return ((t_cmd *)ptr);
}

void scan_token(t_tokens *token_stream)
{
	char	**arg;

	arg = token_stream->arguments;
	if (*arg[token_stream->flag] == '|' || *arg[token_stream->flag] == '>' || *arg[token_stream->flag] == '<')
	{
		token_stream->token = create_connection_node(arg[token_stream->flag]);
		token_stream->flag++;
	}
	else
	{
		token_stream->token = create_command_node(token_stream);
		token_stream->flag++;
	}
	if (*arg[token_stream->flag] == '|' || *arg[token_stream->flag] == '>' || *arg[token_stream->flag] == '<')
		token_stream->next_token = create_connection_node(arg[token_stream->flag]);
	else
		token_stream->next_token = create_command_node(token_stream);
}

int main()
{
	char *str;
	t_tokens *token_stream;

	token_stream = malloc(sizeof(t_tokens));
	if(!token_stream)
		return (0);
	while(1)
	{
		str = readline("$> ");
		token_stream->arguments = ft_split(str);
		scan_token(token_stream);
		// while(*token_stream->arguments)
		// {
		// 	printf("%s\n", *token_stream->arguments);
		// 	fflush(stdout);
		// 	token_stream->arguments++;
		// }
	}
	return (0);
}
