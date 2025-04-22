#include "header.h"

t_cmd	*create_pipe_node(t_cmd *right, t_cmd *left)
{
	t_pipe	*ptr;

	ptr = malloc(sizeof(t_pipe));
	if (!ptr)
		return (NULL);
	ptr->type = PIPE;
	ptr->left = left;
	ptr->right = right;

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

// t_cmd	*create_connection_node(char *str)
// {
// 	int i;
// 	t_cmd *token;

// 	i = 0;
// 	if (str[i] == '|' || str[i] == '>' || str[i] == '<')
// 	{
// 		if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
// 		{
// 			if (str[i] == '>')
// 				token = create_redirection_node(str);
// 			if (str[i] == '<')
// 				token = create_redirection_node(str);
// 		}
// 		if (str[i] == '|')
// 			token = create_pipe_node();
// 		if (str[i] == '>')
// 			token = create_redirection_node(str);
// 		if (str[i] == '<')
// 			token = create_redirection_node(str);
// 	}

// 	return (token);
// }

// t_cmd	*create_command_node(t_tokens	*token_stream)
// {
// 	t_exec *ptr;

// 	ptr = malloc(sizeof(t_exec));
// 	ptr->type = EXEC;
// 	ptr->arg = token_stream->arguments[token_stream->flag];
// 	ptr->arguments = NULL;
// 	ptr->path = NULL;

// 	return ((t_cmd *)ptr);
// }


t_cmd	*parse_pipe(t_tokens	*token_stream)
{
	t_cmd	*left;
	t_cmd	*right;
	t_cmd	*ptr;

	scan_token(token_stream);
	left = parse_redirection(token_stream);
	if (!left)
		return (NULL);
	scan_token(token_stream);
	if (token_stream->token_type == PIPE)
	{
		right = parse_pipe(token_stream);
		ptr = create_pipe_node(right, left);
		return (ptr);
	}
	else
		return (left);
}

t_cmd	*parse_redirection(t_tokens	*token_stream)
{
	t_cmd	*a;
	t_cmd	*f;

	if(token_stream->next_token_type != REDIR)
		return (parse_command(token_stream));
	a = parse_command(token_stream);
	scan_token(token_stream);
	if(token_stream->next_token_type != EXEC)
		return (NULL);
	scan_token(token_stream);
	f = parse_redirection(token_stream);
	return (NULL);
}

t_cmd	*parse_command(t_tokens *token_stream)
{
	if (token_stream->token_type == EXEC)
		return (token_stream->token);
	else
		return (NULL);
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
		parse_pipe(token_stream);
		// while(*token_stream->arguments)
		// {
		// 	printf("%s\n", *token_stream->arguments);
		// 	fflush(stdout);
		// 	token_stream->arguments++;
		// }
	}
	return (0);
}
