#include "header.h"

t_ast create_command_node()
{
	
}

t_ast *create_connection_token(char *argument)
{
	t_ast	*ptr;

	ptr = malloc(sizeof(t_ast));
	if (!ptr)
		return (NULL);
	if (argument[0] == '|' || argument[0] == '>' || argument[0] == '<')
	{
		if ((argument[0] == '>' && argument[1] == '>') || (argument[0] == '<' && argument[1] == '<'))
		{
			if (argument[0] == '>')
				ptr->type = drightredir;
				ptr->data.connection.left = NULL;
				ptr->data.connection.right = NULL;
			if (argument[0] == '<')
				arguments[k] = 
		}
		if (argument[0] == '|')
			arguments[k] = 
		if (argument[0] == '>')
			arguments[k] = 
		if (argument[0] == '<')
			arguments[k] = 
	}
}

void scan_token(char *str, t_tokens *token_stream)
{
	int	flag;
	int	**arguments;

	arguments = token_stream->arguments;
	flag = token_stream->flag;
	while(arguments[flag])
	{
		if (*arguments[flag] != '|' || *arguments[flag] != '>' || *arguments[flag] != '<')
			token_stream->token = create_connection_token(arguments);
		else
	}
}

int main()
{
	char *str;
	t_tokens *token_stream;

	while(1)
	{
		str = readline("$> ");
		token_stream->arguments = ft_split(str);
		// while(*arguments)
		// {
		// 	printf("%s\n", *arguments);
		// 	fflush(stdout);
		// 	arguments++;
		// }
	}
	return (0);
}
