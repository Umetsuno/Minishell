#include "../../Includes/MiniShell.h"

void	ft_strerror(char *s1, char *s2, char *s3)
{
	write(2, "bash: ", 6);
	if (s1)
	{
		write(2, s1, ft_strlen(s1));
		write(2, ": ", 2);
	}
	if (s2)
	{
		write(2, s2, ft_strlen(s2));
		write(2, ": ", 2);
	}
	if (s3)
	{
		write(2, s3, ft_strlen(s3));
	}
}
