#include "pipex.h"
#include "libft.h"

char	*ft_strjoin_pipex(char const *s1, char const *s2);

char	*get_pathname(char **path_tab, char *cmd)
{
	int	i;
	char	*pathname_cmd;

	i = 0;
	while (path_tab[i] != NULL)
	{
		pathname_cmd = ft_strjoin_pipex((char const *)path_tab[i], (char const *)cmd);
		if (pathname_cmd == NULL)
			return (NULL);
		if (access(pathname_cmd, X_OK) == 0)
			return (pathname_cmd);
		i++;
	}
	return (NULL);
}

int	tab_len(char **path_tab)
{
	int	tab_len;

	tab_len = 0;
	while (path_tab[tab_len] != NULL)
		tab_len++;
	return (tab_len);
}

char	**get_path_tab(char **envp)
{
	int			i;
	int			first_len;
	char	*path_s;
	char		**path_tab;

	if (!*envp || !envp)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			path_s = envp[i];
			break;
		}
		i++;
	}
	path_tab = ft_split(path_s, ':');
	if (path_tab == NULL)
		return (NULL);
	first_len = ft_strlen(path_tab[0] + 5);
	ft_memmove(path_tab[0], path_tab[0] + 5, ft_strlen(path_tab[0] + 5));
	ft_bzero(path_tab[0] + first_len, ft_strlen(path_tab[0]) - first_len);
	return (path_tab);
}

int	cmd_exec(char **cmd, char *cmd_path, char **envp)
{
	pid_t	pid1;
	int	i = 0;
	int		execve_return;

	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
	{
		execve_return = execve(cmd_path, (char *const*)cmd, (char *const*) envp);
		if (execve_return == -1)
			return (-1);
	}
	return (0);
}

void	cmd1_exec(char **argv, char **envp)
{
	pid_t	pid1;
	char	**cmd1;
	char *cmd1_path;

	cmd1 = ft_split((const char *)argv[1], ' ');
	if (cmd1 == NULL)
		exit(EXIT_FAILURE);
	cmd1_path = get_pathname(get_path_tab(envp), cmd1[0]);
	if (cmd1_path == NULL)
	{
		free(cmd1);
		exit(EXIT_FAILURE);
	}
	if (cmd_exec(cmd1, cmd1_path, envp) == -1)
	{
		free(cmd1);
		free(cmd1_path);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc >= 50)
		return (0);
	cmd1_exec(argv, envp);
}
//cc -g test.c ft_split.c ft_strjoin_pipex.c ft_strlen.c ft_memmove.c ft_bzero.c ft_strlcat.c ft_strlcpy.c
