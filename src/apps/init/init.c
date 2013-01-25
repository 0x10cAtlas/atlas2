#include <atlas2.h>
#include <stdio.h>

#define WELCOME_MSG "Atlas 2 starting.\n"

int main(int argc, char *argv[])
{
	int signald, login;

	printf(WELCOME_MSG);

	signald = exec("/bin/signald", env());
	login = exec("/bin/login", env());

	signal(SIGINT, onkill);
	signal(SIGTERM, onkill);

	wait();

}

void onkill(int signal)
{

	if (signal == SIGTERM || signal == SIGINT) {

		term(login);
		term(signald);

	}

}

