#include "../../Includes/MiniShell.h"

void	sig_ctrl_c(int signal)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	(void)signal;
}

void	sig_ctrl_bs(int signal)
{
	if (g_data.in_cmd == true)
		printf("Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	(void)signal;
}
